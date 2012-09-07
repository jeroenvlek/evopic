/**
 * GeneticAlgorithm.cpp
 *
 *  Created on: Jul 31, 2011
 *      Author: Jeroen Vlek
 *	     Email: jeroenvlek@gmail.com
 *     Website: www.perceptivebits.com
 *     License: Free Beer (Feel free to use it in every 
 *              way possible and if you like it, make 
 *				sure to give me credit and buy me a drink 
 *              if we ever meet ;) )
 */

#include <algorithm>
#include <iostream>
#include <map>
#include <utility>
#include <boost/bind.hpp>

#include "GeneticAlgorithm.h"
#include "TargetImage.h"

GeneticAlgorithm::GeneticAlgorithm(GUI& aGUI)
	: m_gui(aGUI),
	  m_pairGenerator(new PairGenerator(Config::GetPopulationSize())),
	  m_doEvolution(false) {

	m_gui.loadTargetImage();
	for(unsigned int i = 0; i < Config::GetPopulationSize(); ++i) {
		Organism* organism = new Organism(Config::GetGenomeSize());
		m_population.push_back(organism);
	}

	displayPhenoTypes();
}

GeneticAlgorithm::~GeneticAlgorithm() {
	m_thread.join();
	for(PopulationIter it = m_population.begin(); it != m_population.end(); ++it) {
		delete (*it);
	}
	delete m_pairGenerator;
}

void GeneticAlgorithm::start() {
	if(m_doEvolution) {
		return;
	}

	m_doEvolution = true;
	m_thread = boost::thread(boost::bind(&GeneticAlgorithm::evolve, this));
}

void GeneticAlgorithm::stop() {
	if(!m_doEvolution) {
		return;
	}

	m_doEvolution = false;
	m_thread.join();
}

void GeneticAlgorithm::createOffspring() {
	Couples couples = m_pairGenerator->createRandomPairs();
	Couples::iterator couple;
	for (couple = couples.begin(); couple != couples.end(); ++couple) {
		Organism* parentA = m_population[couple->first];
		Organism* parentB = m_population[couple->second];
		Organism* child = new Organism(*parentA, *parentB);
		m_population.push_back(child);
	}
}

/**
 * Natural selection by selecting the organisms that are
 * the closest to the target image (i.e. fit the best to the environment)
 * and remove the others.
 * @return The closest distance
 */
void GeneticAlgorithm::doNaturalSelection() {
	// calculate fitness of each organism
	Image& targetImage = *TargetImage::Instance();
	std::multimap<double, Organism*> distancePerOrganism;
	for (PopulationIter it = m_population.begin(); it != m_population.end(); ++it) {
		double distance = m_comparator->compare(targetImage, (*it)->getPhenotype());
		distancePerOrganism.insert(std::pair<double, Organism*>(distance, *it));
	}

	// survival of the fittest...
	unsigned int numberToRemove = m_population.size()	- Config::GetPopulationSize();
	std::multimap<double, Organism*>::iterator itDistances = distancePerOrganism.end();
	for (unsigned int i = 0; i < numberToRemove; ++i) {
		--itDistances;
		delete itDistances->second;
		PopulationIter itRemove = find(m_population.begin(), m_population.end(), itDistances->second);
		m_population.erase(itRemove);
	}
}

/**
 * Updates the GUI to display the phenotypes
 */
void GeneticAlgorithm::displayPhenoTypes() {
	for (PopulationIter it = m_population.begin(); it != m_population.end(); ++it) {
		unsigned int index = it - m_population.begin();
		m_gui.displayPhenotypeImage(index, (*it)->getPhenotype());
	}
}

void GeneticAlgorithm::evolve() {
	std::cout << "[ GeneticAlgorithm::evolve() ] Entering evolution loop" << std::endl;

	while(m_doEvolution) {
		createOffspring();
		doNaturalSelection();
		displayPhenoTypes();
	}
}
