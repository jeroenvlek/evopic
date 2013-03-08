/**
 * Gene.h
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

#ifndef GENE_H_
#define GENE_H_

#include <utility>
#include <vector>

#include "Pixel.h"

/**
 * Class that models DNA building blocks.
 */
class Gene
{
public:
	Gene(PIXEL color, std::vector<std::pair<int, int> > points);
	virtual ~Gene();

	const PIXEL& getColor() const { return m_color; }
	const std::vector<std::pair<int, int> >& getPoints() const { return m_points; }

private:
	PIXEL m_color;
	std::vector<std::pair<int, int> > m_points;
};

#endif /* GENE_H_ */
