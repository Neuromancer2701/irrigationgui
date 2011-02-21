#-------------------------------------------------
#
# Project created by QtCreator 2011-02-20T18:10:05
#
#-------------------------------------------------

QT       += core gui

TARGET = Generation2
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h

FORMS    += mainwindow.ui


INCLUDEPATH += D:\workspace\irrigationgui\Generation2\includes
QMAKE_LIBDIR += D:\workspace\irrigationgui\Generation2\libs

LIBS += -LD:\workspace\irrigationgui\Generation2\libs -lqextserialport

CONFIG(debug, debug|release):LIBS += -lqextserialportd
CONFIG(release, debug|release):LIBS += -lqextserialport


unix:DEFINES = _TTY_POSIX_
win32:DEFINES = _TTY_WIN_ QWT_DLL QT_DLL
