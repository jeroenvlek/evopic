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

Gene::Gene(PIXEL color, std::vector<std::pair<int, int> > points) : m_color(color), m_points(points)
{
}

Gene::~Gene()
{
}

