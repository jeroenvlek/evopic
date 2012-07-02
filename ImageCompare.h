/*
 * ImageCompare.h
 *
 *  Created on: Jan 22, 2012
 *      Author: jvlek
 */

#ifndef IMAGECOMPARE_H_
#define IMAGECOMPARE_H_

#include "Image.h"

class ImageCompare
{
public:
	double compare(Image& a, Image& b);
	ImageCompare();
	virtual ~ImageCompare();
};

#endif /* IMAGECOMPARE_H_ */
