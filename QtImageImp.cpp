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


QtImageImp::QtImageImp()
		: ImageImp(), QImage(0, 0, QImage::Format_ARGB32), m_painter(NULL)
{
	fill(Qt::black);
}

QtImageImp::QtImageImp(const unsigned int width, const unsigned int height)
		: ImageImp(width, height), QImage(width, height, QImage::Format_ARGB32)
{
	m_painter = new QPainter((QImage*) this);
	fill(Qt::black);
}

QtImageImp::~QtImageImp()
{
	if(m_painter) {
		delete m_painter;
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
	m_painter->setPen(aQColor);
	m_painter->setBrush(aQColor);
	m_painter->drawPolygon(qtGene);
}

unsigned int QtImageImp::getHeight()
{
	return height();
}

const PIXEL* QtImageImp::get(unsigned int x, unsigned int y)
{
	const unsigned char* pixel = scanLine(y) + (x * 4);
	return (const PIXEL*) pixel;
}

void QtImageImp::clear()
{
	fill(Qt::black);
}

