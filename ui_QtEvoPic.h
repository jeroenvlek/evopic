/********************************************************************************
** Form generated from reading UI file 'QtEvoPic.ui'
**
** Created: Mon Jul 2 21:01:10 2012
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QTEVOPIC_H
#define UI_QTEVOPIC_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QtEvoPicClass
{
public:
    QWidget *centralwidget;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QLabel *targetImageLabel;
    QLabel *phenotypeImageLabel;
    QPushButton *toggleEvolutionButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *QtEvoPicClass)
    {
        if (QtEvoPicClass->objectName().isEmpty())
            QtEvoPicClass->setObjectName(QString::fromUtf8("QtEvoPicClass"));
        QtEvoPicClass->resize(800, 600);
        QSizePolicy sizePolicy(QSizePolicy::Ignored, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(QtEvoPicClass->sizePolicy().hasHeightForWidth());
        QtEvoPicClass->setSizePolicy(sizePolicy);
        centralwidget = new QWidget(QtEvoPicClass);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        QSizePolicy sizePolicy1(QSizePolicy::Ignored, QSizePolicy::Ignored);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(centralwidget->sizePolicy().hasHeightForWidth());
        centralwidget->setSizePolicy(sizePolicy1);
        gridLayoutWidget = new QWidget(centralwidget);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(-1, 0, 811, 551));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        targetImageLabel = new QLabel(gridLayoutWidget);
        targetImageLabel->setObjectName(QString::fromUtf8("targetImageLabel"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(targetImageLabel->sizePolicy().hasHeightForWidth());
        targetImageLabel->setSizePolicy(sizePolicy2);
        targetImageLabel->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(targetImageLabel, 1, 0, 1, 1);

        phenotypeImageLabel = new QLabel(gridLayoutWidget);
        phenotypeImageLabel->setObjectName(QString::fromUtf8("phenotypeImageLabel"));
        sizePolicy2.setHeightForWidth(phenotypeImageLabel->sizePolicy().hasHeightForWidth());
        phenotypeImageLabel->setSizePolicy(sizePolicy2);
        phenotypeImageLabel->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(phenotypeImageLabel, 1, 1, 1, 1);

        toggleEvolutionButton = new QPushButton(gridLayoutWidget);
        toggleEvolutionButton->setObjectName(QString::fromUtf8("toggleEvolutionButton"));

        gridLayout->addWidget(toggleEvolutionButton, 0, 0, 1, 2);

        QtEvoPicClass->setCentralWidget(centralwidget);
        menubar = new QMenuBar(QtEvoPicClass);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 26));
        QtEvoPicClass->setMenuBar(menubar);
        statusbar = new QStatusBar(QtEvoPicClass);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        QtEvoPicClass->setStatusBar(statusbar);

        retranslateUi(QtEvoPicClass);

        QMetaObject::connectSlotsByName(QtEvoPicClass);
    } // setupUi

    void retranslateUi(QMainWindow *QtEvoPicClass)
    {
        QtEvoPicClass->setWindowTitle(QApplication::translate("QtEvoPicClass", "MainWindow", 0, QApplication::UnicodeUTF8));
        targetImageLabel->setText(QApplication::translate("QtEvoPicClass", "TargetImage", 0, QApplication::UnicodeUTF8));
        phenotypeImageLabel->setText(QApplication::translate("QtEvoPicClass", "Fittest Organism", 0, QApplication::UnicodeUTF8));
        toggleEvolutionButton->setText(QApplication::translate("QtEvoPicClass", "Start / Continue Evolution", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class QtEvoPicClass: public Ui_QtEvoPicClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QTEVOPIC_H
