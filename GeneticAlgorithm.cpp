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
#include "ImageComputation.h"
#include "TargetImage.h"

GeneticAlgorithm::GeneticAlgorithm(GUI& aGUI)
	: m_gui(aGUI),
	  m_doEvolution(false),
	  m_populationSizeDelta(0) {

	m_gui.loadTargetImage();

	Image& targetImage = *TargetImage::Instance();

	Organism::reserve(Config::GetPopulationSize() * 2);
	Organism::setGrowthPolicy(memory::DOUBLE);

	for(unsigned int i = 0; i < Config::GetPopulationSize(); ++i) {
		Organism* organism = new Organism(Config::GetGenomeSize());
		m_population.push_back(organism);
		double score = averagePixelDistance(targetImage, organism->getPhenotype());
		organism->setScore(score);
	}

	displayPhenoTypes();
}

GeneticAlgorithm::~GeneticAlgorithm() {
	stop();
	for(PopulationIter it = m_population.begin(); it != m_population.end(); ++it) {
		delete *it;
	}
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

void GeneticAlgorithm::createOffspring(bool doMutation) {
	Image& targetImage = *TargetImage::Instance();

	Population newPopulation;
	while(m_population.size() > 1) {
		std::pair<Organism*, Organism*> couple = m_pairGenerator.removeRandomPair(m_population);
		Organism* child = new Organism(*couple.first, *couple.second, doMutation);
		double score = averagePixelDistance(targetImage, child->getPhenotype());
		child->setScore(score);

		newPopulation.push_back(child);
		newPopulation.push_back(couple.first);
		newPopulation.push_back(couple.second);
	}

	if(m_population.size() == 1) {
		Organism* leftOver = m_population[0];
		newPopulation.push_back(leftOver);
	}

	m_population = newPopulation;
}

/**
 * Natural selection by selecting the organisms that are
 * the closest to the target image (i.e. fit the best to the environment)
 * and remove the others.
 * @return The smallest distance
 */
void GeneticAlgorithm::doNaturalSelection() {
	handlePopulationSizeDelta();

	std::sort(m_population.begin(), m_population.end(), Organism::compareScores);
	while(m_population.size() > Config::GetPopulationSize()) {
		delete m_population.back();
		m_population.pop_back();
	}
}

void GeneticAlgorithm::handlePopulationSizeDelta() {
	if(m_populationSizeDelta == 0) {
		return;
	}

	int newPopulationSize = Config::GetPopulationSize() + m_populationSizeDelta;
	Config::SetPopulationSize(newPopulationSize);

	m_populationSizeDelta  = 0;
}

/**
 * Updates the GUI to display the phenotypes
 */
void GeneticAlgorithm::displayPhenoTypes() {
	int index = 0;
	for (PopulationIter it = m_population.begin(); it != m_population.end(); ++it) {
		m_gui.displayPhenotypeImage(index++, (*it)->getPhenotype());
	}
}

void GeneticAlgorithm::evolve() {
	std::cout << "[ GeneticAlgorithm::evolve() ] Entering evolution loop" << std::endl;

	unsigned int numIterations = 0;
	while(m_doEvolution) {

		bool doMutation = (numIterations % Config::GetMutationInterval()) == 0;
		createOffspring(doMutation);
		doNaturalSelection();
		displayPhenoTypes();

		++numIterations;
//		if((numIterations % Config::GetReportingInterval()) == 0) {
//			std::cout << "[ GeneticAlgorithm::evolve() ] Iteration: " << numIterations <<
//					", smallest distance:  " << m_populationScores.begin()->first << std::endl;
//		}
	}
	std::cout << "[ GeneticAlgorithm::evolve() ] Total number of iterations: " << numIterations << std::endl;
}

void GeneticAlgorithm::incrementPopulationSize() {
	m_populationSizeDelta = 1;
}

void GeneticAlgorithm::decrementPopulationSize() {
	m_populationSizeDelta = -1;
}
