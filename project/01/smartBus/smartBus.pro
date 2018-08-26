#-------------------------------------------------
#
# Project created by QtCreator 2018-08-23T00:16:48
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = smartBus
TEMPLATE = app


SOURCES += main.cpp\
        smartbus.cpp \
    hdnetwork2.cpp \
    common.cpp \
    hdnetwork.cpp \
    bus.cpp \
    pathshowwin.cpp \
    weather.cpp \
    test.cpp

HEADERS  += smartbus.h \
    hdnetwork2.h \
    common.h \
    hdnetwork.h \
    bus.h \
    pathshowwin.h \
    weather.h \
    test.h

FORMS    += smartbus.ui \
    bus.ui \
    pathshowwin.ui \
    weather.ui \
    test.ui

RESOURCES += \
    images.qrc
