#include "Config.h"
#include "QtEvoPic.h"
#include "QtGeneticAlgorithm.h"

#include <QtGui>
#include <QApplication>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QtEvoPic w;
    QtGeneticAlgorithm qtGenAlg(w);
    QObject::connect(w.getToggleButton(), SIGNAL(clicked()), &qtGenAlg, SLOT(toggle()));
    QObject::connect(w.getMutationIntervalSlider(), SIGNAL(valueChanged(int)), &qtGenAlg, SLOT(setMutationInterval(int)) );
    w.show();
    return a.exec();
}
