/**
 * Image.cpp
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

#include "Factory.h"
#include "Image.h"

#include <iostream>

void Image::clear()
{
	_imp->clear();
}

Image::Image()
{
	FactoryPtr factory = Factory::Instance();
	_imp = factory->makeImageImp();
}

unsigned int Image::getWidth()
{
	return _imp->getWidth();
}

unsigned int Image::getHeight()
{
	return _imp->getHeight();
}

Image::~Image()
{
	delete _imp;
}

void Image::loadFromFile(const std::string& filename)
{
	std::cout << "[ Image::loadFromFile() ] Only TargetImage can load file: " << filename << std::endl;
}

const RGBA32* Image::get(unsigned int x, unsigned int y)
{
	return _imp->get(x,y);
}

void Image::drawGene(const Gene&)
{
	std::cout << "[ Image::drawGene() ] Only PhenotypeImage draws gene" << std::endl;
}

ImageImp& Image::getImageImp()
{
	return *_imp;
}

