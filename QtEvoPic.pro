CONFIG += debug
CONFIG -= release
TEMPLATE = app
TARGET = QtEvoPic
QT += core \
    gui
HEADERS += PairGenerator.h \
    Pixel.h \
    ImageComputation.h \
    QtEvoPic.h \
    GUI.h \
    Config.h \
    Exceptions.h \
    QtImageImp.h \
    Organism.h \
    ImageImp.h \
    TargetImage.h \
    PhenotypeImage.h \
    Image.h \
    Gene.h \
    QtFactory.h \
    Factory.h \
    QtGeneticAlgorithm.h \
    GeneticAlgorithm.h \
    memory/ObjectPool.h 
SOURCES += PairGenerator.cpp \
    ImageComputation.cpp \
    QtGeneticAlgorithm.cpp \
    QtEvoPic.cpp \
    GUI.cpp \
    Config.cpp \
    QtImageImp.cpp \
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
QMAKE_CFLAGS+=-pg
QMAKE_CXXFLAGS+=-pg
QMAKE_LFLAGS+=-pg
