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
#include "QtEvoPic.h"

#include <qobject.h>

class QtEvoPic;

class QtGeneticAlgorithm: public QObject, public GeneticAlgorithm
{
	Q_OBJECT

public:
	QtGeneticAlgorithm(QtEvoPic& gui);
	virtual ~QtGeneticAlgorithm();

public slots:
	void toggle();
	void setMutationInterval(int mutationInterval) { Config::SetMutationInterval(mutationInterval); }
	void incrementDisplaySize();
	void decrementDisplaySize();

private:
	bool m_turnOn;
};

#endif /* QTGENETICALGORITHM_H_ */
