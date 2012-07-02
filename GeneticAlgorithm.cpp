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
	_organism = new Organism(20);
	_GUI.displayPhenotypeImage(_organism->getPhenotype());
}

GeneticAlgorithm::~GeneticAlgorithm()
{
	delete _organism;
}

void GeneticAlgorithm::start()
{
	std::cout << "Start" << std::endl;
	double avgDistance = _comparator->compare(_organism->getPhenotype(), *TargetImage::Instance());
	std::cout << "Distance: " << avgDistance << std::endl;
}

void GeneticAlgorithm::stop()
{
	std::cout << "Stop" << std::endl;
}


