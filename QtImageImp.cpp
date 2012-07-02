/**
 * QtImageImp.cpp
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

#include "Config.h"
#include "QtImageImp.h"
#include "QtPolygonGene.h"

#include <iostream>
#include <QBrush>
#include <QColor>
#include <qrgb.h>


QtImageImp::QtImageImp(const unsigned int width, const unsigned int height)
		: ImageImp(width, height), QImage(width, height, QImage::Format_ARGB32)
{
	// TargetImage initiates with (0, 0), and this results in a debug warning
	// by QPainter.
	// Furthermore, TargetImage doesn't need a painter.
	if(width > 0 && height > 0) {
		_painter = new QPainter((QImage*) this);
	}

	fill(Qt::black);
}

QtImageImp::~QtImageImp()
{
	if(_painter) {
		delete _painter;
	}
}

void QtImageImp::loadFromFile(const std::string& filename)
{
	load(filename.c_str());
	Config::SetWidth(width());
	Config::SetHeight(height());
}

unsigned int QtImageImp::getWidth()
{
	return width();
}

void QtImageImp::drawGene(const Gene& gene)
{
	const QtPolygonGene& qtGene = dynamic_cast<const QtPolygonGene&>(gene);
	const GeneColor& color = qtGene.getColor();
	QColor aQColor(color.red, color.green, color.blue, color.alpha);
	_painter->setPen(aQColor);
	_painter->setBrush(aQColor);
	_painter->drawPolygon(qtGene);
}

unsigned int QtImageImp::getHeight()
{
	return height();
}

const RGBA32* QtImageImp::get(unsigned int x, unsigned int y)
{
	const unsigned char* pixel = scanLine(y) + (x * 4);
	return (const RGBA32*) pixel;
}

void QtImageImp::clear()
{
	fill(Qt::black);
}

