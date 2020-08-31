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


MagicalDungeonLevelBuilder::MagicalDungeonLevelBuilder()
{

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
/**
 * @brief Builds a new BasicDungeonLevel with the provided attributes.
 * @param name   The name of the new dungeon.
 * @param width  The width of the new dungeon.
 * @param height The height of the new dungeon.
 */
void MagicalDungeonLevelBuilder::buildDungeonLevel(std::string name, int width, int height) {
    DungeonLevelBuilder::buildDungeonLevel(std::make_shared<MagicalDungeonLevel>(name, width, height));
}

/**
 * @brief Builds a new Room and adds it to the current Basic Dungeon Level.
 * @param id The ID of the new Room being built.
 * @return The Room that was just built.
 */
std::shared_ptr<Room> MagicalDungeonLevelBuilder::buildRoom(int id) {
    if(((int) (core::Game::instance().randomDouble() * 10)) % 4 == 0) {
        getDungeonLevel()->addRoom(std::make_shared<AlchemistsLaboratory>(id));
    } else {
        getDungeonLevel()->addRoom(std::make_shared<EnchantedLibrary>(id));
    }
    return getDungeonLevel()->retrieveRoom(id);
}


/**
 * @brief Builds a Doorway between the origin and destination Rooms.
 *
 * Builds a Doorway between the origin and destination Rooms. The Doorway is set to the Direction
 * specified in the origin Room and the opposing direction in the destination Room.
 * The type of Doorway built is determined by the MoveConstraints parameter.
 *
 * @param origin        The origin Room to house the Doorway.
 * @param destination   The destination Room to house the Doorway.
 * @param direction     The Direction that the Doorway will be built in the origin Room.
 * @param constraints   The MoveConstraints that determine the type of Doorway built. Multiple MoveConstraints
 *                      may be combined using bitwise or (|).
 */
void MagicalDungeonLevelBuilder::buildDoorway(std::shared_ptr<Room> origin, std::shared_ptr<Room> destination,
                                            Room::Direction direction, MoveContraints constraints) {
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

/**
 * @brief Builds a OneWayDoor at the specified Direction of the given Room and marks it as the entrance.
 * @param room      The Room to have the entrance built in.
 * @param direction The Direction where the entrance will be built.
 */
void MagicalDungeonLevelBuilder::buildEntrance(std::shared_ptr<Room> room, Room::Direction direction) {
    room->setEdge(direction, std::make_shared<OneWayDoor>());
    // Cast to doorway to set as entrance
    std::shared_ptr<Doorway> door = std::dynamic_pointer_cast<Doorway>(room->edge(direction));
    door->setAsEntrance();
}

/**
 * @brief Builds a OneWayDoor at the specified Direction of the given Room and marks it as the exit.
 * @param room      The Room to have the exit built in.
 * @param direction The Direction where the exit will be built.
 */
void MagicalDungeonLevelBuilder::buildExit(std::shared_ptr<Room> room, Room::Direction direction) {
    room->setEdge(direction, std::make_shared<OneWayDoor>());
    // Cast to doorway to set as entrance
    std::shared_ptr<Doorway> door = std::dynamic_pointer_cast<Doorway>(room->edge(direction));
    door->setAsExit();
}

/**
 * @brief Builds a clone of a random Item and inserts it into the chosen Room.
 * @param room The Room to receive the Item.
 */
void MagicalDungeonLevelBuilder::buildItem(std::shared_ptr<Room> room) {
    room->setItem(randomItem()->clone());
}

/**
 * @brief Builds a clone of a random Abstract Creature and inserts it into the chosen Room.
 * @param room The Room to receive the Creature.
 */
void MagicalDungeonLevelBuilder::buildCreature(std::shared_ptr<Room> room) {
    room->setCreature(randomCreature()->clone());
}
