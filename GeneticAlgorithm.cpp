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

#include <boost/bind.hpp>

#include "GeneticAlgorithm.h"
#include "TargetImage.h"

GeneticAlgorithm::GeneticAlgorithm(GUI& aGUI)
	: m_gui(aGUI),
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
	std::cout << "Start" << std::endl;
	m_doEvolution = true;
	m_thread = boost::thread(boost::bind(&GeneticAlgorithm::evolve, this));
}

void GeneticAlgorithm::stop()
{
	std::cout << "Stop" << std::endl;
	m_doEvolution = false;
	m_thread.join();
}

void GeneticAlgorithm::evolve() {
	std::cout << "GeneticAlgorithm::evolve()" << std::endl;
	while(m_doEvolution) {
		// pair up organisms
		// create children
		// mutilate children's dna
		// natural selection
		// update gui
	}
}
