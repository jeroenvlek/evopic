/**
 * Gene.cpp
 *
 *  Created on: Aug 2, 2011
 *      Author: Jeroen Vlek
 *	     Email: jeroenvlek@gmail.com
 *     Website: www.perceptivebits.com
 *     License: Free Beer (Feel free to use it in every 
 *              way possible and if you like it, make 
 *				sure to give me credit and buy me a drink 
 *              if we ever meet ;) )
 */

#include "Gene.h"


Gene::~Gene()
{
}

void Gene::setColor(unsigned char red, unsigned char green, unsigned char blue, unsigned char alpha)
{
	_color.red = red;
	_color.green = green;
	_color.blue = blue;
	_color.alpha = alpha;
}

const GeneColor& Gene::getColor() const
{
	return _color;
}

Gene::Gene()
{
}
