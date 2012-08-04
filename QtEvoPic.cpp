/**
 * QtEvoPic.cpp
 *
 *  Created on: Aug 9, 2011
 *      Author: Jeroen Vlek
 *	     Email: jeroenvlek@gmail.com
 *     Website: www.perceptivebits.com
 *     License: Free Beer (Feel free to use it in every
 *              way possible and if you like it, make
 *				sure to give me credit and buy me a drink
 *              if we ever meet ;) )
 */

#include "Config.h"
#include "QtEvoPic.h"
#include "TargetImage.h"

#include <iostream>
#include <cmath>

#include <QCoreApplication>
#include <QDebug>
#include <QFileDialog>
#include <QLabel>
#include <QPixmap>
#include <QRegExp>
#include <QSizePolicy>

QtEvoPic::QtEvoPic(QWidget *parent)
    : QMainWindow(parent), _simRunning(false)
{
	ui.setupUi(this);

	_targetImageLabel = new QLabel(ui.gridLayoutWidget);
	_targetImageLabel->setAlignment(Qt::AlignCenter);
	_targetImageLabel->setScaledContents(true);
	ui.gridLayout->addWidget(_targetImageLabel, 1, 0);

	int rowLength = (int) sqrt(Config::GetPopulationSize() + 1);
	for(unsigned int i = 1; i <= Config::GetPopulationSize(); ++i) {
			QLabel* phenotypeImageLabel = new QLabel(ui.gridLayoutWidget);
	        phenotypeImageLabel->setObjectName(QString::fromUtf8("phenotypeImageLabel") + i);
	        phenotypeImageLabel->setAlignment(Qt::AlignCenter);
	        phenotypeImageLabel->setScaledContents(true);
	        _phenoTypeImageLabels.append(phenotypeImageLabel);
	        ui.gridLayout->addWidget(phenotypeImageLabel, (i / rowLength) + 1, i % rowLength);
	}
}

QtEvoPic::~QtEvoPic()
{
}

bool QtEvoPic::loadTargetImage()
{

	// load file
	TargetImagePtr targetImage = TargetImage::Instance();
//	QString filename = QFileDialog::getOpenFileName(this,
//	     tr("Open Image"), "", tr("Image Files (*.png *.jpg *.bmp)"));
//	targetImage->loadFromFile(qPrintable(filename));
	targetImage->loadFromFile(Config::GetTestImageName());

	QImage& qTargetImage = dynamic_cast<QImage&>(targetImage->getImageImp());
	_targetImageLabel->setPixmap(QPixmap::fromImage(qTargetImage));

	// the target image's size is set for the population as well
	Config::SetWidth(qTargetImage.width());
	Config::SetHeight(qTargetImage.height());

	return true;
}

void QtEvoPic::resizeEvent(QResizeEvent* resizeEvent)
{
	ui.gridLayoutWidget->resize(resizeEvent->size());
}

void QtEvoPic::displayPhenotypeImage(unsigned int index, PhenotypeImage& phenotypeImage)
{
	QImage& qImage = dynamic_cast<QImage&>(phenotypeImage.getImageImp());
	_phenoTypeImageLabels.at(index)->setPixmap(QPixmap::fromImage(qImage));
}

void QtEvoPic::keyPressEvent(QKeyEvent* keyEvent)
{
	switch(keyEvent->key()) {
		case Qt::Key_Escape:
			QCoreApplication::exit();
			break;
	}
}

