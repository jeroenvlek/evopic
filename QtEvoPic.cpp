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

QtEvoPic::QtEvoPic(QWidget *parent) :
		QMainWindow(parent) {
	ui.setupUi(this);

	m_targetImageLabel = new QLabel(ui.gridLayoutWidget);
	m_targetImageLabel->setAlignment(Qt::AlignCenter);
	m_targetImageLabel->setScaledContents(true);
}

QtEvoPic::~QtEvoPic() {
}

void QtEvoPic::updateLayout() {
	updateLabels();

	// remove all current items
	QLayoutItem *child;
	while ((child = ui.gridLayout->takeAt(0)) != 0) {}

	ui.gridLayout->addWidget(m_targetImageLabel, 0, 0);

	// add phenotype labels in a square + remainder as an extra row
	int rowLength = (int) sqrt(Config::GetPopulationSize() + 1);
	for (unsigned int i = 1; i <= Config::GetPopulationSize(); ++i) {
	      unsigned int rowIndex = (i / rowLength);
	      unsigned int columnIndex = i % rowLength;
	      ui.gridLayout->addWidget(m_phenoTypeImageLabels[i - 1], rowIndex,
				columnIndex);
	}
}

QLabel* QtEvoPic::createLabel() {
	QLabel* imageLabel = new QLabel(ui.gridLayoutWidget);
	imageLabel->setAlignment(Qt::AlignCenter);
	imageLabel->setScaledContents(true);
	return imageLabel;
}

void QtEvoPic::updateLabels() {
	int diff = Config::GetPopulationSize() - m_phenoTypeImageLabels.size();
	if(diff > 0) {
		for(int i = 0; i < diff; ++i) {
			addLabel();
		}
	} else if( diff < 0) {
		for(int i = diff; i < 0; ++i) {
			removeLabel();
		}
	}
}

void QtEvoPic::addLabel() {
	QLabel* phenotypeImageLabel = createLabel();
	m_phenoTypeImageLabels.append(phenotypeImageLabel);
}

void QtEvoPic::removeLabel() {
	QLabel* label = m_phenoTypeImageLabels.back();
	m_phenoTypeImageLabels.pop_back();
	m_phenoTypeImages.pop_back();
	ui.gridLayout->removeWidget(label);
	delete label;
}

bool QtEvoPic::loadTargetImage() {

	// load file
	TargetImagePtr targetImage = TargetImage::Instance();
//	QString filename = QFileDialog::getOpenFileName(this,
//	     tr("Open Image"), "", tr("Image Files (*.png *.jpg *.bmp)"));
//	targetImage->loadFromFile(qPrintable(filename));
	targetImage->loadFromFile(Config::GetTestImageName());

	QImage& qTargetImage = dynamic_cast<QImage&>(targetImage->getImageImp());
	m_targetImageLabel->setPixmap(QPixmap::fromImage(qTargetImage));


	// the target image's size is set for the population as well
	Config::SetWidth(qTargetImage.width());
	Config::SetHeight(qTargetImage.height());

	return true;
}

void QtEvoPic::resizeEvent(QResizeEvent* resizeEvent) {
	int newWidth = resizeEvent->size().width();

	// control widget stays the same height
	int controlHeight = ui.layoutWidget->size().height();
	ui.layoutWidget->resize(newWidth, controlHeight);

	// rest of the space goes to the grid layout
	int newGridHeight = resizeEvent->size().height();
	newGridHeight -= controlHeight;
	newGridHeight -= ui.statusbar->height();
	ui.gridLayoutWidget->resize(newWidth, newGridHeight);
}

void QtEvoPic::paintEvent(QPaintEvent*) {
	mutex.lock();

	if( (int) Config::GetPopulationSize() != m_phenoTypeImageLabels.size()) {
		updateLayout();
	}

	for (int i = 0; i < m_phenoTypeImages.size(); ++i) {
		QPixmap pixmap = QPixmap::fromImage(m_phenoTypeImages[i]);
		m_phenoTypeImageLabels[i]->setPixmap(pixmap);
	}

	mutex.unlock();
}

void QtEvoPic::displayPhenotypeImage(unsigned int index,
		PhenotypeImage& phenotypeImage) {
	QImage& qImage = dynamic_cast<QImage&>(phenotypeImage.getImageImp());

	mutex.lock();

	if(m_phenoTypeImages.size() <= (int) index) {
		m_phenoTypeImages.append(qImage);
	} else {
		m_phenoTypeImages[index] = qImage;
	}

	mutex.unlock();
}

void QtEvoPic::keyPressEvent(QKeyEvent* keyEvent) {
	switch (keyEvent->key()) {
	case Qt::Key_Escape:
		QCoreApplication::exit();
		break;
	}
}

