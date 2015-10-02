#-------------------------------------------------
#
# Project created by QtCreator 2015-05-22T13:54:51
#
#-------------------------------------------------

QT       += core

QT       -= gui

TARGET = opencv_ch9
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += \
#    calibrate.cpp \
#    estimateF.cpp \
#    estimateH.cpp \
    robustmatching.cpp\
    CameraCalibrator.cpp


HEADERS += \
    CameraCalibrator.h \
    matcher.h

INCLUDEPATH += D:/opencv/include

LIBS += -L D:/opencv/x86/mingw/lib/libopencv_*.dll.a
