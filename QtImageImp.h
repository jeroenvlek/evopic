/**
 * QtImageImp.h
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

#ifndef QTIMAGEIMP_H_
#define QTIMAGEIMP_H_

#include "Gene.h"
#include "ImageImp.h"
#include "Pixel.h"

#include <QImage>
#include <QPainter>

/**
 * A Qt based implementation of the ImageImp class.
 */
class QtImageImp: public ImageImp, public QImage
{
public:
	QtImageImp();
	QtImageImp(const unsigned int width, const unsigned int height);
	virtual ~QtImageImp();

	void clear();

	void drawGene(const Gene& gene);

	void loadFromFile(const std::string& filename);

	const PIXEL* get(unsigned int x, unsigned int y);

	const PIXEL* getScanline(unsigned int y);

	unsigned int getWidth();
	unsigned int getHeight();

private:
	QPainter* m_painter;
};

#endif /* QTIMAGEIMP_H_ */
