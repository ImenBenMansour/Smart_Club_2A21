QT       += sql printsupport
QT       += core gui sql
QT       += core gui charts
QT       += core gui network
QT       += core gui sql serialport printsupport network charts multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11
CONFIG += console
CONFIG +=console
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets


# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    chat.cpp \
    connexion.cpp \
    dialog.cpp \
    role.cpp \
    main.cpp \
    mainwindow.cpp \
    personnel.cpp \
    smtp.cpp \
    stat.cpp

HEADERS += \
    chat.h \
    connexion.h \
    dialog.h \
    role.h \
    mainwindow.h \
    personnel.h \
    smtp.h \
    stat.h

FORMS += \
    chat.ui \
    dialog.ui \
    mainwindow.ui \
    stat.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
