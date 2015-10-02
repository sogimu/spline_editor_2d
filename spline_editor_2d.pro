#-------------------------------------------------
#
# Project created by QtCreator 2015-10-02T13:24:22
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = spline_editor_2d
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    splineeditorwidget.cpp \
    spline.cpp \
    splinepoint.cpp

HEADERS  += mainwindow.h \
    splineeditorwidget.h \
    spline.h \
    splinepoint.h

FORMS    += mainwindow.ui
