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
    w.show();
    return a.exec();
}
