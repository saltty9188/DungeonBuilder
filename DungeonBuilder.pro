TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        core/creatures/abstractcreature.cpp \
        core/creatures/monster.cpp \
        core/dungeon/basic/basicdungeonlevel.cpp \
        core/dungeon/basic/quartzchamber.cpp \
        core/dungeon/basic/rockchamber.cpp \
        core/dungeon/basic/rockwall.cpp \
        core/dungeon/common/blockeddoorway.cpp \
        core/dungeon/common/lockeddoor.cpp \
        core/dungeon/common/onewaydoor.cpp \
        core/dungeon/common/opendoorway.cpp \
        core/dungeon/doorway.cpp \
        core/dungeon/dungeonlevel.cpp \
        core/dungeon/room.cpp \
        core/dungeon/roomedge.cpp \
        core/dungeon/wall.cpp \
        core/game.cpp \
        core/items/item.cpp \
        core/items/weapon.cpp \
        core/menuinterface.cpp \
        main.cpp

HEADERS += \
    core/creatures/abstractcreature.h \
    core/creatures/monster.h \
    core/dungeon/basic/basicdungeonlevel.h \
    core/dungeon/basic/quartzchamber.h \
    core/dungeon/basic/rockchamber.h \
    core/dungeon/basic/rockwall.h \
    core/dungeon/common/blockeddoorway.h \
    core/dungeon/common/lockeddoor.h \
    core/dungeon/common/onewaydoor.h \
    core/dungeon/common/opendoorway.h \
    core/dungeon/doorway.h \
    core/dungeon/dungeonlevel.h \
    core/dungeon/room.h \
    core/dungeon/roomedge.h \
    core/dungeon/wall.h \
    core/game.h \
    core/items/item.h \
    core/items/weapon.h \
    core/menuinterface.h
