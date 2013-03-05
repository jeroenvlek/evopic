/**
 * PhenotypeImage.cpp
 *
 *  Created on: Aug 3, 2011
 *      Author: Jeroen Vlek
 *	     Email: jeroenvlek@gmail.com
 *     Website: www.perceptivebits.com
 *     License: Free Beer (Feel free to use it in every 
 *              way possible and if you like it, make 
 *				sure to give me credit and buy me a drink 
 *              if we ever meet ;) )
 */

#include "PhenotypeImage.h"

PhenotypeImage::PhenotypeImage()
		: Image()
{
}

PhenotypeImage::~PhenotypeImage()
{
}

void PhenotypeImage::drawGene(const Gene & gene)
{
	m_imp->drawGene(gene);
}



