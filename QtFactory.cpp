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

#include "QtFactory.h"
#include "QtImageImp.h"
#include "QtPolygonGene.h"

#include <iostream>
#include <QPoint>


QtFactory::QtFactory()
{
}

QtFactory::~QtFactory()
{
}

Gene* QtFactory::makeGene()
{
	return new QtPolygonGene();
}

Gene* QtFactory::makeRandomGene()
{
	QtPolygonGene* aQtPG = new QtPolygonGene();
	aQtPG->setColor(randPrimary(), randPrimary(), randPrimary(), randPrimary());
	for(unsigned int i = randGeneSize(); i > 0; --i)
		(*aQtPG) << QPoint(randX(), randY());
	return aQtPG;
}

ImageImp* QtFactory::makeImageImp()
{
	return new QtImageImp(Config::GetWidth(), Config::GetHeight());
}

