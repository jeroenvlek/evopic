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

#include <utility>
#include <boost/bind.hpp>

#include "GeneticAlgorithm.h"
#include "TargetImage.h"

GeneticAlgorithm::GeneticAlgorithm(GUI& aGUI)
	: m_gui(aGUI),
	  m_pairGenerator(PairGenerator(Config::GetPopulationSize())),
	  m_doEvolution(false)
{
	m_gui.loadTargetImage();
	for(unsigned int i = 0; i < Config::GetPopulationSize(); ++i) {
		Organism* organism = new Organism(Config::GetGenomeSize());
		m_population.push_back(organism);
		m_gui.displayPhenotypeImage(i, organism->getPhenotype());
	}
}

GeneticAlgorithm::~GeneticAlgorithm()
{
	m_thread.join();
	std::vector<Organism*>::iterator it;
	for(it = m_population.begin(); it != m_population.end(); ++it) {
		delete (*it);
	}
}

void GeneticAlgorithm::start()
{
	if(m_doEvolution) {
		return;
	}

	std::cout << "Start" << std::endl;
	m_doEvolution = true;
	m_thread = boost::thread(boost::bind(&GeneticAlgorithm::evolve, this));
}

void GeneticAlgorithm::stop()
{
	if(!m_doEvolution) {
		return;
	}

	std::cout << "Stop" << std::endl;
	m_doEvolution = false;
	m_thread.join();
}

void GeneticAlgorithm::evolve() {
	std::cout << "[ GeneticAlgorithm::evolve() ] Entering loop" << std::endl;

	while(m_doEvolution) {
		Couples couples = m_pairGenerator.createRandomPairs();

		// create children
		// mutilate children's dna
		// natural selection
		// update gui
	}
}
