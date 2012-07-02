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

/**
 * The color of a gene is a 32 bit RGBA tuple.
 */
struct GeneColor
{
	unsigned char red;
	unsigned char green;
	unsigned char blue;
	unsigned char alpha;
};

/**
 * Abstract class that specifies the interface for DNA building blocks.
 */
class Gene
{
public:
	virtual ~Gene();

	const GeneColor& getColor() const;
	void setColor(unsigned char red, unsigned char green, unsigned char blue, unsigned char alpha);

protected:
	Gene();

	/**
	 * The color of a gene is a 24 bit RGB tuple.
	 */
	GeneColor _color;
};

#endif /* GENE_H_ */