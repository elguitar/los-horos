include( ../common.pri )

QT       += core gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += console

TARGET = ElectionGame
TEMPLATE = app

SOURCES +=\
    ../Course/controlexception.cpp \
    ../Course/councilor.cpp \
    ../Course/deck.cpp \
    ../Course/formatexception.cpp \
    ../Course/game.cpp \
    ../Course/gameexception.cpp \
    ../Course/influence.cpp \
    ../Course/ioexception.cpp \
    ../Course/keyexception.cpp \
    ../Course/location.cpp \
    ../Course/manualcontrol.cpp \
    ../Course/player.cpp \
    ../Course/random.cpp \
    ../Course/rangeexception.cpp \
    ../Course/runner.cpp \
    ../Course/settingsreader.cpp \
    ../Course/stateexception.cpp \
    ../Course/withdrawaction.cpp \
    agent.cpp \
    main.cpp \
    akkuna.cpp \
    setupwindow.cpp \
    kaupunginosa.cpp \
    actionasetaagentti.cpp \
    actionnostakortti.cpp \
    actionnostaagentti.cpp \
    actionasetapelimerkki.cpp \
    actionagentillemerkki.cpp \
    pelicard.cpp \
    enddialog.cpp

HEADERS  += \
    agent.h \
    akkuna.h \
    setupwindow.h \
    kaupunginosa.h \
    actionasetaagentti.h\
    actionnostakortti.h \
    actionnostaagentti.h \
    actionasetapelimerkki.h \
    actionagentillemerkki.h \
    pelicard.h \
    enddialog.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}

INCLUDEPATH += $$PWD/../Course
DEPENDPATH += $$PWD/../Course

CONFIG(release, debug|release) {
    DESTDIR = release
}
CONFIG(debug, debug|release) {
    DESTDIR = debug
}

LIBS += -L$$OUT_PWD/../Course/
LIBS += -L$$OUT_PWD/../Course/$${DESTDIR}/ -lCourse

win32 {
    copyfiles.commands += @echo NOW COPYING ADDITIONAL FILE(S) for Windows &
    copyfiles.commands += @call xcopy ..\\..\\$$TARGET\\Assets Assets /i /s /e /y
}
unix:!macx {
    copyfiles.commands += @echo \"NOW COPYING ADDITIONAL FILE(S) for Linux\" &&
    copyfiles.commands += cp -r ../../$$TARGET/Assets $$DESTDIR
}
macx {
    copyfiles.commands += @echo \"NOW COPYING ADDITIONAL FILE(S) for MacOS\" &&
    copyfiles.commands += mkdir -p $$DESTDIR/ElectionGame.app/Contents/MacOS &&
    copyfiles.commands += cp -r ../../$$TARGET/Assets $$DESTDIR &&
    copyfiles.commands += cp -r ../../$$TARGET/Assets $$DESTDIR/ElectionGame.app/Contents/MacOS/
}

QMAKE_EXTRA_TARGETS += copyfiles
POST_TARGETDEPS += copyfiles

FORMS += \
    akkuna.ui \
    setupwindow.ui \
    kaupunginosa.ui \
    pelicard.ui \
    enddialog.ui
