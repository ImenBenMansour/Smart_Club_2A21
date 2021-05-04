QT       += core gui
QT       += core gui sql serialport printsupport network charts multimedia


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    abonne.cpp \
    abonnement.cpp \
    animal.cpp \
    board_widget.cpp \
    connexion.cpp \
    dialog.cpp \
    equipement.cpp \
    evenements.cpp \
    excel.cpp \
    fournisseur.cpp \
    login.cpp \
    main.cpp \
    mainwindow.cpp \
    nourriture.cpp \
    personnel.cpp \
    puzzle_board.cpp \
    role.cpp \
    smtp.cpp \
    sponsor.cpp \
    stati.cpp \
    statis.cpp \
    statis1.cpp \
    statis2.cpp \
    statis3.cpp \
    widget.cpp

HEADERS += \
    abonne.h \
    abonnement.h \
    animal.h \
    board_widget.h \
    connexion.h \
    dialog.h \
    equipement.h \
    evenements.h \
    excel.h \
    fournisseur.h \
    login.h \
    mainwindow.h \
    nourriture.h \
    personnel.h \
    puzzle_board.h \
    role.h \
    smtp.h \
    sponsor.h \
    stati.h \
    statis.h \
    statis1.h \
    statis2.h \
    statis3.h \
    widget.h

FORMS += \
    dialog.ui \
    mainwindow.ui \
    stati.ui \
    statis.ui \
    statis1.ui \
    statis2.ui \
    statis3.ui \
    widget.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
