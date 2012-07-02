/**
 * PhenotypeImage.h
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

#ifndef PHENOTYPEIMAGE_H_
#define PHENOTYPEIMAGE_H_

#include "Gene.h"
#include "Image.h"

class PhenotypeImage: public Image
{
public:
	PhenotypeImage();
	virtual ~PhenotypeImage();

	/**
	 * Draws the gene on the image.
	 * @param gene
	 */
	void drawGene(const Gene& gene);
};

#endif /* PHENOTYPEIMAGE_H_ */
