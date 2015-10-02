#-------------------------------------------------
#
# Project created by QtCreator 2015-05-20T10:05:19
#
#-------------------------------------------------

QT       += core

QT       -= gui

TARGET = opencv_ch5
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += \
    morpho2.cpp #\
#    morphology.cpp \
#    segment.cpp

INCLUDEPATH += D:/opencv/include

LIBS += -L D:/opencv/x86/mingw/lib/libopencv_*.dll.a

HEADERS += \
    morphoFeatures.h \
    watershedSegmentation.h
