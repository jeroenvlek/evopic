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
#include <QCoreApplication>
#include <QFileDialog>
#include <QPixmap>

QtEvoPic::QtEvoPic(QWidget *parent)
    : QMainWindow(parent), _simRunning(false)
{
	ui.setupUi(this);
	connect(ui.toggleEvolutionButton, SIGNAL(clicked()), this, SLOT(toggleButtonText()));
}

QtEvoPic::~QtEvoPic()
{
}

bool QtEvoPic::loadTargetImage()
{
	// TODO: a lot of potential wrong user input here

	// load file
	TargetImagePtr targetImage = TargetImage::Instance();
//	QString filename = QFileDialog::getOpenFileName(this,
//	     tr("Open Image"), "", tr("Image Files (*.png *.jpg *.bmp)"));
//	targetImage->loadFromFile(qPrintable(filename));
	targetImage->loadFromFile(Config::GetTestImageName());

	// display image and set up phenotype image as same size
	QImage& qTargetImage = dynamic_cast<QImage&>(targetImage->getImageImp());
	ui.targetImageLabel->setFixedSize(qTargetImage.width(), qTargetImage.height());
	ui.phenotypeImageLabel->setFixedSize(qTargetImage.width(), qTargetImage.height());
	updateGeometry();
	ui.targetImageLabel->setPixmap(QPixmap::fromImage(qTargetImage));

	// update config
	Config::SetWidth(qTargetImage.width());
	Config::SetHeight(qTargetImage.height());

	return true;
}

void QtEvoPic::displayPhenotypeImage(PhenotypeImage& phenotypeImage)
{
	// display image
	QImage& qImage = dynamic_cast<QImage&>(phenotypeImage.getImageImp());
	ui.phenotypeImageLabel->setFixedSize(qImage.width(), qImage.height());
	ui.phenotypeImageLabel->setFixedSize(qImage.width(), qImage.height());
	updateGeometry();
	ui.phenotypeImageLabel->setPixmap(QPixmap::fromImage(qImage));

}

void QtEvoPic::keyPressEvent(QKeyEvent* keyEvent)
{
	switch(keyEvent->key()) {
		case Qt::Key_Escape:
			QCoreApplication::exit();
			break;
	}
}

void QtEvoPic::toggleButtonText()
{
//	if(_simRunning) {
//		_simRunning = false;
//		ui.toggleEvolutionButton->setText("Stop Evolution");
//	}
//	else {
//		_simRunning = true;
//		ui.toggleEvolutionButton->setText("Start / Continue Evolution");
//	}
}

