/********************************************************************************
** Form generated from reading UI file 'QtEvoPic.ui'
**
** Created: Sun Sep 9 17:13:12 2012
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
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QPushButton>
#include <QtGui/QSlider>
#include <QtGui/QStatusBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QtEvoPicClass
{
public:
    QWidget *centralwidget;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QPushButton *toggleEvolutionButton;
    QSlider *mutationIntervalSlider;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *QtEvoPicClass)
    {
        if (QtEvoPicClass->objectName().isEmpty())
            QtEvoPicClass->setObjectName(QString::fromUtf8("QtEvoPicClass"));
        QtEvoPicClass->resize(814, 596);
        QSizePolicy sizePolicy(QSizePolicy::Ignored, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(QtEvoPicClass->sizePolicy().hasHeightForWidth());
        QtEvoPicClass->setSizePolicy(sizePolicy);
        centralwidget = new QWidget(QtEvoPicClass);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(centralwidget->sizePolicy().hasHeightForWidth());
        centralwidget->setSizePolicy(sizePolicy1);
        gridLayoutWidget = new QWidget(centralwidget);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(-1, 0, 811, 551));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        gridLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        toggleEvolutionButton = new QPushButton(gridLayoutWidget);
        toggleEvolutionButton->setObjectName(QString::fromUtf8("toggleEvolutionButton"));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(toggleEvolutionButton->sizePolicy().hasHeightForWidth());
        toggleEvolutionButton->setSizePolicy(sizePolicy2);

        horizontalLayout->addWidget(toggleEvolutionButton);

        mutationIntervalSlider = new QSlider(gridLayoutWidget);
        mutationIntervalSlider->setObjectName(QString::fromUtf8("mutationIntervalSlider"));
        mutationIntervalSlider->setMaximum(100);
        mutationIntervalSlider->setOrientation(Qt::Horizontal);
        mutationIntervalSlider->setTickPosition(QSlider::TicksBelow);
        mutationIntervalSlider->setTickInterval(1);

        horizontalLayout->addWidget(mutationIntervalSlider);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);

        QtEvoPicClass->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(QtEvoPicClass);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        QtEvoPicClass->setStatusBar(statusbar);

        retranslateUi(QtEvoPicClass);

        QMetaObject::connectSlotsByName(QtEvoPicClass);
    } // setupUi

    void retranslateUi(QMainWindow *QtEvoPicClass)
    {
        QtEvoPicClass->setWindowTitle(QApplication::translate("QtEvoPicClass", "QtEvoPic", 0, QApplication::UnicodeUTF8));
        toggleEvolutionButton->setText(QApplication::translate("QtEvoPicClass", "Start / Continue Evolution", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class QtEvoPicClass: public Ui_QtEvoPicClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QTEVOPIC_H
