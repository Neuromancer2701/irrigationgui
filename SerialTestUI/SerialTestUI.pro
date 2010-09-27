#-------------------------------------------------
#
# Project created by QtCreator 2010-09-25T15:35:34
#
#-------------------------------------------------

QT       += xml

TARGET = SerialTestUI
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h

FORMS    += mainwindow.ui

INCLUDEPATH += D:\workspace\irrigationgui\SerialTestUI\qextserialport
QMAKE_LIBDIR += D:\workspace\irrigationgui\SerialTestUI\qextserialport\build

LIBS += -lqextserialport
unix:DEFINES = _TTY_POSIX_
win32:DEFINES = _TTY_WIN_ QWT_DLL QT_DLL


