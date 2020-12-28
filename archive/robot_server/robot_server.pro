QT       += core gui widgets network serialport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    FenServeur.cpp \
    console.cpp \
    main.cpp \
    mainwindow.cpp \
    robot_uart.cpp \
    settingsdialog.cpp

HEADERS += \
    FenServeur.h \
    console.h \
    mainwindow.h \
    settingsdialog.h

FORMS += \
    mainwindow.ui \
    settingsdialog.ui
    settingsdialog.ui


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
