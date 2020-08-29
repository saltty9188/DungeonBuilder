#include <iostream>
#include "core/menuinterface.h"
#include "core/dungeon/room.h"
#include "core/dungeon/basic/quartzchamber.h"
#include "core/dungeon/basic/rockchamber.h"
#include "core/dungeon/basic/rockwall.h"
#include "core/dungeon/common/opendoorway.h"
#include "core/dungeon/common/blockeddoorway.h"
#include "core/dungeon/basic/basicdungeonlevel.h"
#include "core/creatures/monster.h"

using namespace std;

using namespace core::creatures;
using namespace core::dungeon::basic;
using namespace core::dungeon::common;
using namespace core::dungeon;

int main()
{
//    core::MenuInterface menuInterface{std::cout, std::cin};
//    menuInterface.displayWelcome("Ty Salter", "Dungeon Builder");
//    menuInterface.run();

//    BasicDungeonLevel level{"Level", 2, 2};

//    level.addRoom(std::make_shared<RockChamber>(1));
//    level.addRoom(std::make_shared<RockChamber>(2));
//    level.addRoom(std::make_shared<RockChamber>(3));
//    level.addRoom(std::make_shared<RockChamber>(4));

//    level.retrieveRoom(1)->setEdge(Room::Direction::North, std::make_shared<OpenDoorway>());
//    level.retrieveRoom(1)->setEdge(Room::Direction::East, std::make_shared<BlockedDoorway>());

//    level.retrieveRoom(2)->setEdge(Room::Direction::West, std::make_shared<BlockedDoorway>());
//    level.retrieveRoom(2)->setEdge(Room::Direction::South, std::make_shared<OpenDoorway>());

//    level.retrieveRoom(3)->setEdge(Room::Direction::East, std::make_shared<BlockedDoorway>());

//    level.retrieveRoom(4)->setEdge(Room::Direction::West, std::make_shared<BlockedDoorway>());
//    level.retrieveRoom(4)->setEdge(Room::Direction::North, std::make_shared<OpenDoorway>());

//    cout << level.description() << endl;

//    cout << level << std::endl;


    return 0;


}
