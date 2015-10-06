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
    splinepoint.cpp \
    splinepointwidget.cpp \
    splinelinewidget.cpp \
    splineserializer.cpp \
    splineserializerjson.cpp \
    history.cpp \
    historyitem.cpp \
    positionhistoryitem.cpp \
    biashistoryitem.cpp \
    continuityhistoryitem.cpp \
    tensionhistoryitem.cpp

HEADERS  += mainwindow.h \
    splineeditorwidget.h \
    spline.h \
    splinepoint.h \
    splinepointwidget.h \
    splinelinewidget.h \
    splineserializer.h \
    splineserializerjson.h \
    historyitem.h \
    history.h \
    positionhistoryitem.h \
    biashistoryitem.h \
    continuityhistoryitem.h \
    tensionhistoryitem.h

FORMS    += mainwindow.ui
