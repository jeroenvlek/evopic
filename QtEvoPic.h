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

#include "GUI.h"
#include "PhenotypeImage.h"
#include "ui_QtEvoPic.h"

#include <QtGui/QMainWindow>
#include <QKeyEvent>

class QtEvoPic : public QMainWindow, public GUI
{
    Q_OBJECT;

public:
    QtEvoPic(QWidget *parent = 0);
    ~QtEvoPic();

    QPushButton* getToggleButton() const { return ui.toggleEvolutionButton; }

    /**
	 * Key event handler.
	 *
	 * @param keyEvent
	 */
	void keyPressEvent(QKeyEvent* keyEvent);

	/**
	 * Loads and displays the TargetImage.
	 *
	 * @return True on success, false on failure
	 */
	bool loadTargetImage();

	/**
	 * Displays the given PhenotypeImage.
	 * @param phenotypeImage
	 */
	void displayPhenotypeImage(PhenotypeImage& phenotypeImage);

public slots:

	/**
	 * Changes the text of the start/stop button
	 */
	void toggleButtonText();

private:
    Ui::QtEvoPicClass ui;

    bool _simRunning;
};

#endif // QTEVOPIC_H
