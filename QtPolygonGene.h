/**
 * QPolygonGene.h
 *
 *  Created on: Aug 1, 2011
 *      Author: Jeroen Vlek
 *	     Email: jeroenvlek@gmail.com
 *     Website: www.perceptivebits.com
 *     License: Free Beer (Feel free to use it in every 
 *              way possible and if you like it, make 
 *				sure to give me credit and buy me a drink 
 *              if we ever meet ;) )
 */

#ifndef QTPOLYGONGENE_H_
#define QTPOLYGONGENE_H_

#include <QColor>
#include <QPolygon>

#include "Gene.h"

/**
 * A gene based on the QPolygon class.
 */
class QtPolygonGene: public Gene, public QPolygon
{
public:
	QtPolygonGene(unsigned char red, unsigned char green, unsigned char blue, unsigned char alpha);
	QtPolygonGene(const QtPolygonGene& gene);
	virtual ~QtPolygonGene();

	Gene* clone();

	void mutate();
};

#endif /* QTPOLYGONGENE_H_ */
