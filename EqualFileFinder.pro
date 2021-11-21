QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

#QMAKE_CXXFLAGS_RELEASE += /O2 #it is set already
QMAKE_CXXFLAGS_RELEASE += -Ob2
QMAKE_CXXFLAGS_RELEASE += -Oi
QMAKE_CXXFLAGS_RELEASE += -Ot
QMAKE_CXXFLAGS_RELEASE += -GT
QMAKE_CXXFLAGS_RELEASE += -GL

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    EqualFileFinder.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    EqualFileFinder.h \
    Profiler.h \
    mainwindow.h

FORMS += \
    mainwindow.ui

UI_DIR = $$PWD #for GUI to rebuild properly

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
