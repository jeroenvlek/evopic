/*
 * ImageCompare.cpp
 *
 *  Created on: Jan 22, 2012
 *      Author: jvlek
 */

#include "ImageCompare.h"
#include "RGBA32.h"

#include <cassert>
#include <cmath>
#include <iostream>

ImageCompare::ImageCompare()
{
}

ImageCompare::~ImageCompare()
{
}



double ImageCompare::compare(Image& a, Image& b)
{
	assert(a.getWidth() == b.getWidth() && a.getHeight() == b.getHeight());

	// first rough implementation: compute average Euclidean distance between pixels
	double avgDistance = 0.0;
	unsigned int totalPixels;
	for(unsigned int x = 0; x < a.getWidth(); ++x) {
		for(unsigned int y = 0; y < a.getHeight(); ++y) {
			const RGBA32* pixelA = a.get(x, y);
			const RGBA32* pixelB = b.get(x, y);

			int diffR = (int) pixelA->r - (int) pixelB->r;
			diffR *= diffR;

			int diffG = (int) pixelA->g - (int) pixelB->g;
			diffG *= diffG;

			int diffB = (int) pixelA->b - (int) pixelB->b;
			diffB *= diffB;

			int diffA = (int) pixelA->a - (int) pixelB->a;
			diffA *= diffA;

			avgDistance += sqrt(diffR + diffG + diffB + diffA);
			++totalPixels;
		}
	}
	avgDistance /= totalPixels;
	return avgDistance;
}
