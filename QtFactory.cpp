/**
 * QtFactory.cpp
 *
 *  Created on: Aug 2, 2011
 *      Author: Jeroen Vlek
 *	     Email: jeroenvlek@gmail.com
 *     Website: www.perceptivebits.com
 *     License: Free Beer (Feel free to use it in every 
 *              way possible and if you like it, make 
 *				sure to give me credit and buy me a drink 
 *              if we ever meet ;) )
 */

#include <iostream>
#include <utility>
#include <vector>
#include <QPoint>

#include "QtFactory.h"

QtFactory::QtFactory()
{
	std::cout << "[ QtFactory::QtFactory() ] Using QtFactory" << std::endl;
}

QtFactory::~QtFactory()
{
}

QtImageImp* QtFactory::makeImageImp() {
	return new QtImageImp(Config::GetWidth(), Config::GetHeight());
}

