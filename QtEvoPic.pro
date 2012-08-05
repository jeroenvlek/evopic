TEMPLATE = app
TARGET = QtEvoPic
QT += core \
    gui
HEADERS += RGBA32.h \
    ImageCompare.h \
    QtEvoPic.h \
    GUI.h \
    Config.h \
    Exceptions.h \
    QtImageImp.h \
    QtPolygonGene.h \
    Organism.h \
    ImageImp.h \
    TargetImage.h \
    PhenotypeImage.h \
    Image.h \
    Gene.h \
    QtFactory.h \
    Factory.h \
    QtGeneticAlgorithm.h \
    GeneticAlgorithm.h
SOURCES += ImageCompare.cpp \
    QtGeneticAlgorithm.cpp \
    QtEvoPic.cpp \
    GUI.cpp \
    Config.cpp \
    QtImageImp.cpp \
    QtPolygonGene.cpp \
    Organism.cpp \
    ImageImp.cpp \
    TargetImage.cpp \
    PhenotypeImage.cpp \
    Image.cpp \
    Gene.cpp \
    QtFactory.cpp \
    Factory.cpp \
    GeneticAlgorithm.cpp \
    Main.cpp
FORMS += QtEvoPic.ui \
    QtEvoPic.ui
LIBS += -lboost_thread-mt
DEFINES += QT_YES
RESOURCES += 
