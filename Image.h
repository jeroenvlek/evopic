/**
 * Image.h
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

#ifndef IMAGE_H_
#define IMAGE_H_

#include "Gene.h"
#include "ImageImp.h"
#include "Pixel.h"

#include <string>


/**
 * The base class for the images used. It uses a bridge to decouple interface
 * from implementation. The implementation is stored in an ImageImp object.
 */
class Image
{
public:
	virtual ~Image();

	/**
	 * Clears the image to black.
	 */
	void clear();

	/**
	 * @return The width of the image in pixels.
	 */
	unsigned int getWidth();

	/**
	 * @return The height of the image in pixels.
	 */
	unsigned int getHeight();

	/**
	 * @return A reference to the object containing the implementation.
	 */
	ImageImp& getImageImp();

	/**
	 * @return The pixel at location (x,y)
	 */
	const PIXEL* get(unsigned int x, unsigned int y);

	/**
	 * Returns the horizontal pixel line at height y
	 *
	 * @param y
	 * @return
	 */
	const PIXEL* getScanline(unsigned int y);

protected:
	/**
	 * The actual implementation of the image.
	 */
	ImageImp* m_imp;

	/**
	 * Constructor
	 */
	Image();

	/**
	 * Loads an image from file.
	 * Virtual implementation to be overridden by TargetImage. The default
	 * implementation only prints a message to cout.
	 * @param filename
	 */
	virtual void loadFromFile(const std::string& filename);

	/**
	 * Draws the gene onto the image.
	 * Virtual implementation to be overridden by PhenotypeImage. The default
	 * implementation only prints a message to cout.
	 * @param gene
	 */
	virtual void drawGene(const Gene& gene);

};

#endif /* IMAGE_H_ */
