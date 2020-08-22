TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        core/dungeon/roomedge.cpp \
        core/game.cpp \
        core/menuinterface.cpp \
        main.cpp

HEADERS += \
    core/dungeon/roomedge.h \
    core/game.h \
    core/menuinterface.h
