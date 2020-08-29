#include <iostream>
#include "core/menuinterface.h"
#include "core/dungeon/room.h"
#include "core/dungeon/basic/quartzchamber.h"
#include "core/dungeon/basic/rockchamber.h"
#include "core/dungeon/basic/rockwall.h"
#include "core/dungeon/common/opendoorway.h"
#include "core/dungeon/common/onewaydoor.h"
#include "core/dungeon/common/blockeddoorway.h"
#include "core/dungeon/basic/basicdungeonlevel.h"
#include "core/creatures/monster.h"
#include "core/items/weapon.h"

using namespace std;

using namespace core::creatures;
using namespace core::items;
using namespace core::dungeon::basic;
using namespace core::dungeon::common;
using namespace core::dungeon;

int main()
{
//    core::MenuInterface menuInterface{std::cout, std::cin};
//    menuInterface.displayWelcome("Ty Salter", "Dungeon Builder");
//    menuInterface.run();

    BasicDungeonLevel level{"Level", 2, 2};

    level.addRoom(std::make_shared<RockChamber>(1));
    level.addRoom(std::make_shared<RockChamber>(2));
    level.addRoom(std::make_shared<RockChamber>(3));
    level.addRoom(std::make_shared<RockChamber>(4));

    level.retrieveRoom(1)->setEdge(Room::Direction::North, std::make_shared<OneWayDoor>());
    level.retrieveRoom(1)->setEdge(Room::Direction::East, std::make_shared<BlockedDoorway>());
    std::shared_ptr<Doorway> temp = std::dynamic_pointer_cast<Doorway>(level.retrieveRoom(1)->edge(Room::Direction::North));
    temp->setAsEntrance();
    level.retrieveRoom(1)->setItem(std::make_shared<Weapon>("Short Sword"));

    level.retrieveRoom(2)->setEdge(Room::Direction::West, std::make_shared<BlockedDoorway>());
    level.retrieveRoom(2)->setEdge(Room::Direction::South, std::make_shared<OpenDoorway>());

    level.retrieveRoom(3)->setEdge(Room::Direction::East, std::make_shared<BlockedDoorway>());
    level.retrieveRoom(3)->setCreature(std::make_shared<Monster>("Goblin"));

    level.retrieveRoom(4)->setEdge(Room::Direction::West, std::make_shared<BlockedDoorway>());
    level.retrieveRoom(4)->setEdge(Room::Direction::North, std::make_shared<OpenDoorway>());
    level.retrieveRoom(4)->setEdge(Room::Direction::East, std::make_shared<OneWayDoor>());
    temp = std::dynamic_pointer_cast<Doorway>(level.retrieveRoom(4)->edge(Room::Direction::East));
    temp->setAsExit();

    level.retrieveRoom(4)->setCreature(std::make_shared<Monster>("Goblin King"));
    level.retrieveRoom(4)->setItem(std::make_shared<Weapon>("War Axe"));


    cout << level.retrieveRoom(1)->description() << endl;

    cout << level << std::endl;


    return 0;


}
