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

	for (unsigned int i = 1; i <= Config::GetPopulationSize(); ++i) {
		QLabel* phenotypeImageLabel = new QLabel(ui.gridLayoutWidget);
		phenotypeImageLabel->setObjectName(
				QString::fromUtf8("phenotypeImageLabel") + i);
		phenotypeImageLabel->setAlignment(Qt::AlignCenter);
		phenotypeImageLabel->setScaledContents(true);
		m_phenoTypeImageLabels.append(phenotypeImageLabel);
	}

	setUpLayout();

	connect(ui.moreButton, SIGNAL(clicked()), this, SLOT(incrementImages()));
	connect(ui.lessButton, SIGNAL(clicked()), this, SLOT(decrementImages()));
}

QtEvoPic::~QtEvoPic() {
}

void QtEvoPic::setUpLayout() {
	int rowLength = (int) sqrt(Config::GetPopulationSize() + 1);
	if(rowLength == ui.gridLayout->columnCount()) {
		return;
	}

	// remove all current items
	QLayoutItem *child;
	while ((child = ui.gridLayout->takeAt(0)) != 0) {}

	ui.gridLayout->addWidget(m_targetImageLabel, 1, 0);

	// add phenotype labels in a square + remainder as an extra row
	for (unsigned int i = 1; i <= Config::GetPopulationSize(); ++i) {
	      unsigned int rowIndex = (i / rowLength) + 1;
	      unsigned int columnIndex = i % rowLength;
	      ui.gridLayout->addWidget(m_phenoTypeImageLabels[i - 1], rowIndex,
				columnIndex);
	}
	ui.gridLayout->addLayout(ui.horizontalLayout, 0, 0, 1,
			ui.gridLayout->columnCount());
}

void QtEvoPic::incrementImages() {
	mutex.lock();

	int newSize = Config::GetPopulationSize() + 1;
	Config::SetPopulationSize(newSize);

	QLabel* phenotypeImageLabel = new QLabel(ui.gridLayoutWidget);
	phenotypeImageLabel->setObjectName(
			QString::fromUtf8("phenotypeImageLabel") + newSize);
	phenotypeImageLabel->setAlignment(Qt::AlignCenter);
	phenotypeImageLabel->setScaledContents(true);
	m_phenoTypeImageLabels.append(phenotypeImageLabel);

	m_phenoTypePixMaps.append(QPixmap(Config::GetWidth(), Config::GetHeight()));

	setUpLayout();

	mutex.unlock();
}

void QtEvoPic::decrementImages() {
	mutex.lock();

	int newSize = Config::GetPopulationSize() - 1;
	Config::SetPopulationSize(newSize);

	QLabel* label = m_phenoTypeImageLabels.back();
	m_phenoTypeImageLabels.pop_back();
	m_phenoTypePixMaps.pop_back();
	ui.gridLayout->removeWidget(label);
	delete label;

	setUpLayout();

	mutex.unlock();
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

	m_phenoTypePixMaps.clear();
	for (unsigned int i = 0; i < Config::GetPopulationSize(); ++i) {
		m_phenoTypePixMaps.append(QPixmap::fromImage(qTargetImage));
	}

	// the target image's size is set for the population as well
	Config::SetWidth(qTargetImage.width());
	Config::SetHeight(qTargetImage.height());

	return true;
}

void QtEvoPic::resizeEvent(QResizeEvent* resizeEvent) {
	ui.gridLayoutWidget->resize(resizeEvent->size());
}

void QtEvoPic::paintEvent(QPaintEvent*) {
	mutex.lock();
	for (int i = 0; i < m_phenoTypePixMaps.size(); ++i) {
		m_phenoTypeImageLabels[i]->setPixmap(m_phenoTypePixMaps[i]);
	}
	mutex.unlock();
}

void QtEvoPic::displayPhenotypeImage(unsigned int index,
		PhenotypeImage& phenotypeImage) {
	QImage& qImage = dynamic_cast<QImage&>(phenotypeImage.getImageImp());
	mutex.lock();
	m_phenoTypePixMaps[index] = QPixmap::fromImage(qImage);
	mutex.unlock();
}

void QtEvoPic::keyPressEvent(QKeyEvent* keyEvent) {
	switch (keyEvent->key()) {
	case Qt::Key_Escape:
		QCoreApplication::exit();
		break;
	}
}

