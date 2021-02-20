QT += widgets network serialport

TARGET = terminal
TEMPLATE = app

DEPENDPATH += .
INCLUDEPATH += .

# Input
HEADERS += mainwindow.h \
    settingsdialog.h \
    console.h

SOURCES += mainwindow.cpp main.cpp \
    settingsdialog.cpp \
    console.cpp

FORMS += \
    settingsdialog.ui
#LIBS +=-L/usr/local/lib/ -lwiringPi
