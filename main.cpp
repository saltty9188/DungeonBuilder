#include <iostream>
#include "core/menuinterface.h"
#include "core/dungeon/room.h"
#include "core/dungeon/basic/rockchamber.h"
#include "core/dungeon/common/opendoorway.h"
#include "core/dungeon/common/blockeddoorway.h"

using namespace std;

using namespace core::dungeon::basic;
using namespace core::dungeon::common;
using namespace core::dungeon;

int main()
{
//    core::MenuInterface menuInterface{std::cout, std::cin};
//    menuInterface.displayWelcome("Ty Salter", "Dungeon Builder");
//    menuInterface.run();

    RockChamber room{1};

    OpenDoorway o1{};
    BlockedDoorway o2{};

    room.setEdge(Room::Direction::North, &o1);
    room.setEdge(Room::Direction::West, &o2);

    cout << room.description() << std::endl;

    return 0;


}
