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
	m_imp->clear();
}

Image::Image()
{
	FactoryPtr factory = Factory::Instance();
	m_imp = factory->makeImageImp();
}

unsigned int Image::getWidth()
{
	return m_imp->getWidth();
}

unsigned int Image::getHeight()
{
	return m_imp->getHeight();
}

Image::~Image()
{
	delete m_imp;
}

void Image::loadFromFile(const std::string& filename)
{
	std::cout << "[ Image::loadFromFile() ] Only TargetImage can load file: " << filename << std::endl;
}

const PIXEL* Image::get(unsigned int x, unsigned int y)
{
	return m_imp->get(x,y);
}

void Image::drawGene(const Gene&)
{
	std::cout << "[ Image::drawGene() ] Only PhenotypeImage draws gene" << std::endl;
}

ImageImp& Image::getImageImp()
{
	return *m_imp;
}

