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

#include <iostream>
#include <QBrush>
#include <QColor>
#include <QPoint>
#include <QPolygon>
#include <QVector>

QtImageImp::QtImageImp() :
		ImageImp(), QImage(0, 0, QImage::Format_ARGB32), m_painter(NULL) {
	fill(Qt::black);
}

QtImageImp::QtImageImp(const unsigned int width, const unsigned int height) :
		ImageImp(width, height), QImage(width, height, QImage::Format_ARGB32) {
	m_painter = new QPainter((QImage*) this);
	fill(Qt::black);
}

QtImageImp::~QtImageImp() {
	if (m_painter) {
		delete m_painter;
	}
}

void QtImageImp::loadFromFile(const std::string& filename) {
	load(filename.c_str());
	Config::SetWidth(width());
	Config::SetHeight(height());
}

unsigned int QtImageImp::getWidth() {
	return width();
}

void QtImageImp::drawGene(const Gene& gene) {
	const PIXEL& color = gene.getColor();
	QColor qColor(color.r, color.g, color.b, color.a);
	m_painter->setPen(qColor);
	m_painter->setBrush(qColor);

	const std::vector<std::pair<int, int> >& points = gene.getPoints();
	QVector<QPoint> qPoints(points.size());
	std::vector<std::pair<int, int> >::const_iterator it;
	for (it = points.begin(); it != points.end(); ++it) {
		qPoints.append(QPoint(it->first, it->second));
	}

	const QPolygon polygon(qPoints);
	m_painter->drawPolygon(polygon);
}

unsigned int QtImageImp::getHeight() {
	return height();
}

const PIXEL* QtImageImp::get(unsigned int x, unsigned int y) {
	const PIXEL* pixel = (const PIXEL*) (scanLine(y) + (x * 4));
	return pixel;
}

const PIXEL* QtImageImp::getScanline(unsigned int y) {
	const PIXEL* scanline = (const PIXEL*) scanLine(y);
	return scanline;
}

void QtImageImp::clear()
{
	fill(Qt::black);
}

