/**
 * TargetImage.cpp
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

#include "TargetImage.h"

#include <iostream>


TargetImagePtr TargetImage::_Instance;
bool TargetImage::_Loaded = false;

TargetImage::TargetImage()
{
}

TargetImage::~TargetImage()
{
}

TargetImagePtr TargetImage::Instance()
{
	if(TargetImage::_Instance.get() == NULL) {
		_Instance.reset(new TargetImage());
	}
	return _Instance;
}

bool TargetImage::IsLoaded()
{
	return _Loaded;
}

void TargetImage::loadFromFile(const std::string& filename)
{
	m_imp->clear();
	m_imp->loadFromFile(filename);
	_Loaded = true;
	std::cout << "[ TargetImage::loadFromFile() ] loaded " << filename << std::endl;
}
