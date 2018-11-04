TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp \
    gameoflife.cpp \
    cell.cpp

HEADERS += \
    gameoflife.h \
    cell.h
