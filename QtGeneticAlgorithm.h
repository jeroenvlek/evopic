/**
 * QtGeneticAlgorithm.h
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

#ifndef QTGENETICALGORITHM_H_
#define QTGENETICALGORITHM_H_

#include "GeneticAlgorithm.h"

#include <qthread.h>


class QtGeneticAlgorithm: public QThread, public GeneticAlgorithm
{
	Q_OBJECT

public:
	QtGeneticAlgorithm(GUI& aGUI);
	virtual ~QtGeneticAlgorithm();

public slots:
	void toggle();

private:
	bool _turnOn;

	void run();
};

#endif /* QTGENETICALGORITHM_H_ */
