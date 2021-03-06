/*
 * ImageCompare.cpp
 *
 *  Created on: Jan 22, 2012
 *      Author: jvlek
 */

#include "ImageComputation.h"
#include "Pixel.h"

#include <cassert>
#include <cmath>
#include <iostream>

double averagePixelDistance(Image& a, Image& b) {
	assert(a.getWidth() == b.getWidth() && a.getHeight() == b.getHeight());

	double sumDistance = 0.0;
	unsigned int width = a.getWidth();
	unsigned int height = a.getHeight();
	for (unsigned int y = 0; y < height; ++y) {

		const PIXEL* scanlineA = a.getScanline(y);
		const PIXEL* scanlineB = b.getScanline(y);
		for (unsigned int x = 0; x < width; ++x) {

			const PIXEL* pixelA = scanlineA + x;
			const PIXEL* pixelB = scanlineB + x;

			int diffR = (int) pixelA->r - pixelB->r;
			diffR *= diffR;

			int diffG = (int) pixelA->g - pixelB->g;
			diffG *= diffG;

			int diffB = (int) pixelA->b - pixelB->b;
			diffB *= diffB;

			int diffA = (int) pixelA->a - pixelB->a;
			diffA *= diffA;

			sumDistance += sqrt(diffR + diffG + diffB + diffA);
		}
	}

	return sumDistance / (width * height);
}
