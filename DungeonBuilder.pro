TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        core/dungeon/room.cpp \
        core/dungeon/roomedge.cpp \
        core/game.cpp \
        core/menuinterface.cpp \
        main.cpp

HEADERS += \
    core/dungeon/room.h \
    core/dungeon/roomedge.h \
    core/game.h \
    core/menuinterface.h
