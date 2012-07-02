/**
 * ImageImp.h
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

#ifndef IMAGEIMP_H_
#define IMAGEIMP_H_

#include "Gene.h"
#include "RGBA32.h"

#include <string>


class ImageImp
{
public:
	virtual ~ImageImp();

	/**
	 * Clears the image to black or transparent, depending on implementation.
	 */
	virtual void clear() =0;

	/**
	 * Loads image from file.
	 *
	 * @param filename
	 */
	virtual void loadFromFile(const std::string& filename) =0;

	/**
	 * Draws the gene on the image.
	 *
	 * @param gene
	 */
	virtual void drawGene(const Gene& gene) =0;

	/**
	 * @return Width of the image.
	 */
	virtual unsigned int getWidth() =0;

	/**
	 * @return Height of the image.
	 */
	virtual unsigned int getHeight() =0;

	/**
	 * @return The pixel at location (x,y)
	 */
	virtual const RGBA32* get(unsigned int x, unsigned int y) =0;


protected:
	ImageImp(const unsigned int width, const unsigned int height);
};

#endif /* IMAGEIMP_H_ */
