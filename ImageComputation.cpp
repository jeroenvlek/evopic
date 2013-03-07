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
	double avgDistance = 0.0;
	unsigned int totalPixels = 0;
	for (unsigned int x = 0; x < a.getWidth(); ++x) {
		for (unsigned int y = 0; y < a.getHeight(); ++y) {
			const PIXEL* pixelA = a.get(x, y);
			const PIXEL* pixelB = b.get(x, y);

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
