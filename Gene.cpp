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
	m_color.red = red;
	m_color.green = green;
	m_color.blue = blue;
	m_color.alpha = alpha;
}

const GeneColor& Gene::getColor() const
{
	return m_color;
}

Gene::Gene()
{
}

Gene::Gene(const Gene& gene)
{
	m_color.red = gene.m_color.red;
	m_color.green = gene.m_color.green;
	m_color.blue = gene.m_color.blue;
	m_color.alpha = gene.m_color.alpha;
}

