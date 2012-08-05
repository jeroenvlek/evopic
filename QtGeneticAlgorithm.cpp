/**
 * QtGeneticAlgorithm.cpp
 *
 *  Created on: Aug 9, 2011
 *      Author: Jeroen Vlek
 *	     Email: jeroenvlek@gmail.com
 *     Website: www.perceptivebits.com
 *     License: Free Beer (Feel free to use it in every 
 *              way possible and if you like it, make 
 *				sure to give me credit and buy me a drink 
 *              if we ever meet ;) )
 */

#include "QtGeneticAlgorithm.h"

#include <iostream>


QtGeneticAlgorithm::QtGeneticAlgorithm(GUI& aGUI) : GeneticAlgorithm(aGUI)
{
	_turnOn = true;
}

QtGeneticAlgorithm::~QtGeneticAlgorithm()
{
}

void QtGeneticAlgorithm::toggle()
{
	if(_turnOn) {
		GeneticAlgorithm::start();
	}
	else {
		GeneticAlgorithm::stop();
	}

	_turnOn = !_turnOn;
}

