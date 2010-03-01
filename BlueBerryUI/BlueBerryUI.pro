# -------------------------------------------------
# Project created by QtCreator 2010-02-11T13:43:00
# -------------------------------------------------
QT += sql \
    xml \
    xmlpatterns
TARGET = BlueBerryUI
TEMPLATE = app
INCLUDEPATH += headers
SOURCES += source/main.cpp \
    source/mainwindow.cpp
HEADERS += headers/mainwindow.h \
    headers/ui_mainwindow.h
FORMS += rsc/mainwindow.ui
LIBS += lib/libqextserialportd.so
DESTDIR  = build
OBJECTS_DIR   = objects
