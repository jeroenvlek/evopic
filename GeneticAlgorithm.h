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

#include <vector>
#include <boost/thread.hpp>

#include "GUI.h"
#include "Organism.h"
#include "PairGenerator.h"


class GeneticAlgorithm
{
public:
	virtual ~GeneticAlgorithm();

protected:
	GeneticAlgorithm(GUI& aGUI);

	void start();
	void stop();

private:
	GUI& m_gui;

	typedef std::vector<Organism*> Population;
	typedef Population::iterator PopulationIter;

	Population m_population;

	PairGenerator m_pairGenerator;

	boost::thread  m_thread;
	boost::mutex m_inputLock;
	boost::mutex m_outputLock;

	bool m_doEvolution;

	void displayPhenoTypes();
	void doNaturalSelection();
	void fillNewPopulation(bool doMutation);
	void createOffspring(Population& newPopulation, bool doMutation);
	void evolve();
};

#endif /* GENETICALGORITHM_H_ */
