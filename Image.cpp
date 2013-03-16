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


Image::Image()
{
	m_imp = Factory::Instance().makeImageImp();
}

Image::~Image()
{
	delete m_imp;
}

void Image::clear()
{
	m_imp->clear();
}

unsigned int Image::getWidth()
{
	return m_imp->getWidth();
}

unsigned int Image::getHeight()
{
	return m_imp->getHeight();
}


void Image::loadFromFile(const std::string& filename)
{
	std::cout << "[ Image::loadFromFile() ] Only TargetImage can load file: " << filename << std::endl;
}

const PIXEL* Image::get(unsigned int x, unsigned int y)
{
	return m_imp->get(x,y);
}

const PIXEL* Image::getScanline(unsigned int y) {
	return m_imp->getScanline(y);
}

void Image::drawGene(const Gene&)
{
	std::cout << "[ Image::drawGene() ] Only PhenotypeImage draws gene" << std::endl;
}

ImageImp& Image::getImageImp()
{
	return *m_imp;
}

