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


QtGeneticAlgorithm::QtGeneticAlgorithm(QtEvoPic& gui) : GeneticAlgorithm(gui),
	m_turnOn(false)
{
	connect(gui.ui.toggleEvolutionButton, SIGNAL(clicked()), this, SLOT(toggle()));
	connect(gui.ui.mutationIntervalSlider, SIGNAL(valueChanged(int)), this, SLOT(setMutationInterval(int)) );
	connect(gui.ui.moreButton, SIGNAL(clicked()), this, SLOT(incrementDisplaySize()));
	connect(gui.ui.lessButton, SIGNAL(clicked()), this, SLOT(decrementDisplaySize()));
}

QtGeneticAlgorithm::~QtGeneticAlgorithm()
{
}

void QtGeneticAlgorithm::toggle()
{
	m_turnOn = !m_turnOn;

	if(m_turnOn) {
		GeneticAlgorithm::start();
	}
	else {
		GeneticAlgorithm::stop();
	}
}

void QtGeneticAlgorithm::incrementDisplaySize() {
	unsigned int displaySize = Config::GetDisplaySize();
	displaySize++;
	Config::SetDisplaySize(displaySize);
}

void QtGeneticAlgorithm::decrementDisplaySize() {
	unsigned int displaySize = Config::GetDisplaySize();
	displaySize--;
	Config::SetDisplaySize(displaySize);
}
