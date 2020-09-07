#include "magicaldungeonlevelbuilder.h"
#include "magicaldungeonlevel.h"
#include "core/game.h"
#include "../room.h"
#include "enchantedlibrary.h"
#include "alchemistslaboratory.h"
#include "../common/onewaydoor.h"
#include "../common/opendoorway.h"
#include "../common/lockeddoor.h"
#include "../common/blockeddoorway.h"
#include "core/items/consumable.h"
#include "core/items/weapon.h"
#include "core/creatures/monster.h"

using namespace core::dungeon::magical;
using namespace core::dungeon::common;
using namespace core::items;
using core::creatures::Monster;
using namespace core::dungeon;


MagicalDungeonLevelBuilder::MagicalDungeonLevelBuilder() {
    generateItems();
    generateCreatures();
}

void MagicalDungeonLevelBuilder::generateItems() {
    insertConsumable(std::make_shared<Consumable>("Health Potion"));
    insertConsumable(std::make_shared<Consumable>("Molotov Cocktail"));
    insertConsumable(std::make_shared<Consumable>("Resistance Potion"));

    insertWeapon(std::make_shared<Weapon>("Boomerang"));
    insertWeapon(std::make_shared<Weapon>("Wizard's Staff"));
    insertWeapon(std::make_shared<Weapon>("Magic Wand"));
}

void MagicalDungeonLevelBuilder::generateCreatures() {
    insertCreature(std::make_shared<Monster>("Goblin"));
    insertCreature(std::make_shared<Monster>("Dragon"));
    insertCreature(std::make_shared<Monster>("Evil Wizard"));
}

void MagicalDungeonLevelBuilder::buildDungeonLevel(const std::string &name, int width, int height) {
    DungeonLevelBuilder::buildDungeonLevel(new MagicalDungeonLevel(name, width, height));
}

std::shared_ptr<Room> MagicalDungeonLevelBuilder::buildRoom(int id) {
    if(((int) (core::Game::instance().randomDouble() * 10)) % 4 == 0) {
        getDungeonLevel()->addRoom(std::make_shared<AlchemistsLaboratory>(id));
    } else {
        getDungeonLevel()->addRoom(std::make_shared<EnchantedLibrary>(id));
    }
    return getDungeonLevel()->retrieveRoom(id);
}

void MagicalDungeonLevelBuilder::buildDoorway(const std::shared_ptr<Room> &origin, const std::shared_ptr<Room> &destination,
                                            const Room::Direction &direction, const MoveContraints &constraints) {
    // Extract the move constraints
    bool noConstraints{constraints == MoveContraints::None};
    bool originImpassable{(MoveContraints::OriginImpassable & constraints) == MoveContraints::OriginImpassable};
    bool destinationImpassable{(MoveContraints::DestinationImpassable & constraints) == MoveContraints::DestinationImpassable};
    bool originLocked{(MoveContraints::OriginLocked & constraints) == MoveContraints::OriginLocked};
    bool destinationLocked{(MoveContraints::DestinationLocked & constraints) == MoveContraints::DestinationLocked};

    // Different constraint scenarios
    if(noConstraints) {
        origin->setEdge(direction, std::make_shared<OpenDoorway>());
        destination->setEdge(Room::oppositeDirection(direction), std::make_shared<OpenDoorway>());

        // Cast set edges to Doorways to connect them
        std::shared_ptr<Doorway> originDoor = std::dynamic_pointer_cast<Doorway>(origin->edge(direction));
        std::shared_ptr<Doorway> destinationDoor = std::dynamic_pointer_cast<Doorway>(destination->edge(Room::oppositeDirection(direction)));
        originDoor->connect(*destinationDoor);

    } else if(originImpassable && !destinationImpassable) {
        origin->setEdge(direction, std::make_shared<OneWayDoor>());
        // Check for locked door
        if(destinationLocked) {
            destination->setEdge(Room::oppositeDirection(direction), std::make_shared<LockedDoor>());
        } else {
            destination->setEdge(Room::oppositeDirection(direction), std::make_shared<OpenDoorway>());
        }

        // Cast set edges to Doorways to connect them
        std::shared_ptr<Doorway> originDoor = std::dynamic_pointer_cast<Doorway>(origin->edge(direction));
        std::shared_ptr<Doorway> destinationDoor = std::dynamic_pointer_cast<Doorway>(destination->edge(Room::oppositeDirection(direction)));
        originDoor->connect(*destinationDoor);

    } else if(destinationImpassable && !originImpassable) {
        // Check for locked door
        if(originLocked) {
            origin->setEdge(direction, std::make_shared<LockedDoor>());
        } else {
            origin->setEdge(direction, std::make_shared<OpenDoorway>());
        }
        destination->setEdge(Room::oppositeDirection(direction), std::make_shared<OneWayDoor>());

        // Cast set edges to Doorways to connect them
        std::shared_ptr<Doorway> originDoor = std::dynamic_pointer_cast<Doorway>(origin->edge(direction));
        std::shared_ptr<Doorway> destinationDoor = std::dynamic_pointer_cast<Doorway>(destination->edge(Room::oppositeDirection(direction)));
        originDoor->connect(*destinationDoor);

    } else if(destinationImpassable && originImpassable) {
        origin->setEdge(direction, std::make_shared<BlockedDoorway>());
        destination->setEdge(Room::oppositeDirection(direction), std::make_shared<BlockedDoorway>());

        // Cast set edges to Doorways to connect them
        std::shared_ptr<Doorway> originDoor = std::dynamic_pointer_cast<Doorway>(origin->edge(direction));
        std::shared_ptr<Doorway> destinationDoor = std::dynamic_pointer_cast<Doorway>(destination->edge(Room::oppositeDirection(direction)));
        originDoor->connect(*destinationDoor);

    } else if(originLocked || destinationLocked) {
        // Check for locked doors
        if(originLocked) {
            origin->setEdge(direction, std::make_shared<LockedDoor>());
        } else {
            origin->setEdge(direction, std::make_shared<OpenDoorway>());
        }

        if(destinationLocked) {
            destination->setEdge(Room::oppositeDirection(direction), std::make_shared<LockedDoor>());
        } else {
            destination->setEdge(Room::oppositeDirection(direction), std::make_shared<OpenDoorway>());
        }

        // Cast set edges to Doorways to connect them
        std::shared_ptr<Doorway> originDoor = std::dynamic_pointer_cast<Doorway>(origin->edge(direction));
        std::shared_ptr<Doorway> destinationDoor = std::dynamic_pointer_cast<Doorway>(destination->edge(Room::oppositeDirection(direction)));
        originDoor->connect(*destinationDoor);
    }
}

void MagicalDungeonLevelBuilder::buildEntrance(const std::shared_ptr<Room> &room, const Room::Direction &direction) {
    room->setEdge(direction, std::make_shared<OneWayDoor>());
    // Cast to doorway to set as entrance
    std::shared_ptr<Doorway> door = std::dynamic_pointer_cast<Doorway>(room->edge(direction));
    door->setAsEntrance();
}

void MagicalDungeonLevelBuilder::buildExit(const std::shared_ptr<Room> &room, const Room::Direction &direction) {
    room->setEdge(direction, std::make_shared<OneWayDoor>());
    // Cast to doorway to set as entrance
    std::shared_ptr<Doorway> door = std::dynamic_pointer_cast<Doorway>(room->edge(direction));
    door->setAsExit();
}

void MagicalDungeonLevelBuilder::buildItem(const std::shared_ptr<Room> &room) {
    room->setItem(randomItem()->clone());
}

void MagicalDungeonLevelBuilder::buildCreature(const std::shared_ptr<Room> &room) {
    room->setCreature(randomCreature()->clone());
}
