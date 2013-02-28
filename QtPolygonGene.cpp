/**
 * QPolygonGene.cpp
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

#include "QtPolygonGene.h"

QtPolygonGene::QtPolygonGene(unsigned char red, unsigned char green, unsigned char blue, unsigned char alpha)
	: Gene(red, green, blue, alpha) {
}

QtPolygonGene::QtPolygonGene(const QtPolygonGene& gene)
	: Gene(gene), QPolygon(gene) {
}

QtPolygonGene::~QtPolygonGene() {
}


Gene* QtPolygonGene::clone() {
	return new QtPolygonGene(*this);
}

void QtPolygonGene::mutate() {
}

