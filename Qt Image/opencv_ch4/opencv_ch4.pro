#-------------------------------------------------
#
# Project created by QtCreator 2015-05-19T22:13:15
#
#-------------------------------------------------

QT       += core

QT       -= gui

TARGET = opencv_ch4
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += \
 #   finder.cpp \
 #   histograms.cpp \
 #   objectfinder.cpp \
    retrieve.cpp

INCLUDEPATH += D:/opencv/include

LIBS += -L D:/opencv/x86/mingw/lib/libopencv_*.dll.a

HEADERS += \
    colorhistogram.h \
    histogram.h \
    imageComparator.h \
    objectFinder.h

