/**
 * QtEvoPic.h
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

#ifndef QTEVOPIC_H
#define QTEVOPIC_H

#include "Config.h"
#include "GUI.h"
#include "PhenotypeImage.h"
#include "ui_QtEvoPic.h"

#include <QAbstractSlider>
#include <QKeyEvent>
#include <QLabel>
#include <QList>
#include <QMainWindow>
#include <QMutex>
#include <QPaintEvent>
#include <QResizeEvent>

class QtEvoPic : public QMainWindow, public GUI
{
    Q_OBJECT;

public:
    QtEvoPic(QWidget *parent = 0);
    ~QtEvoPic();

    QPushButton* getToggleButton() const { return ui.toggleEvolutionButton; }
    QAbstractSlider* getMutationIntervalSlider() const { return ui.mutationIntervalSlider; }
	void keyPressEvent(QKeyEvent* keyEvent);
	void paintEvent(QPaintEvent* paintEvent);
	void resizeEvent(QResizeEvent* resizeEvent);

	/**
	 * Loads and displays the TargetImage.
	 *
	 * @return True on success, false on failure
	 */
	bool loadTargetImage();

	/**
	 * Displays the given PhenotypeImage at holder position index.
	 * @param index
	 * @param phenotypeImage
	 */
	void displayPhenotypeImage(unsigned int index, PhenotypeImage& phenotypeImage);

private:
    Ui::QtEvoPicClass ui;
    QList<QLabel*> m_phenoTypeImageLabels;
    QList<QPixmap> m_phenoTypePixMaps;
    QLabel* m_targetImageLabel;
    QMutex mutex;
};

#endif // QTEVOPIC_H
