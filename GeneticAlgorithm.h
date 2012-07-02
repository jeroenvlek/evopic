/**
 * GeneticAlgorithm.h
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

#ifndef GENETICALGORITHM_H_
#define GENETICALGORITHM_H_

#include "GUI.h"
#include "ImageCompare.h"
#include "Organism.h"

class GeneticAlgorithm
{
public:
	virtual ~GeneticAlgorithm();

protected:
	GeneticAlgorithm(GUI& aGUI);

	GUI& _GUI;
	Organism* _organism;
	ImageCompare* _comparator;

	void start();
	void stop();
};

#endif /* GENETICALGORITHM_H_ */
