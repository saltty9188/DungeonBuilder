#include <iostream>
#include "core/menuinterface.h"
#include "core/dungeon/room.h"
#include "core/dungeon/basic/quartzchamber.h"
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

    QuartzChamber room{1};

    room.setEdge(Room::Direction::North, std::make_shared<OpenDoorway>());
    room.setEdge(Room::Direction::West, std::make_shared<BlockedDoorway>());

    cout << room << std::endl;

    return 0;


}
