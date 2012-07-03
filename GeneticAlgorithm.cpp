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

#include "GeneticAlgorithm.h"
#include "TargetImage.h"

GeneticAlgorithm::GeneticAlgorithm(GUI& aGUI) : _GUI(aGUI)
{
	_GUI.loadTargetImage();
	_population = new Organism*[Config::GetPopulationSize()];
	for(unsigned int i = 0; i < Config::GetPopulationSize(); ++i) {
		_population[i] = new Organism(Config::GetGenomeSize());
	}
	_GUI.displayPhenotypeImage(_population[0]->getPhenotype());
}

GeneticAlgorithm::~GeneticAlgorithm()
{
	for(unsigned int i = 0; i < Config::GetPopulationSize(); ++i) {
		delete _population[i];
	}
	delete _population;
}

void GeneticAlgorithm::start()
{
	std::cout << "Start" << std::endl;

}

void GeneticAlgorithm::stop()
{
	std::cout << "Stop" << std::endl;
}


