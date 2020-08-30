#include "dungeonlevelbuilder.h"
using namespace core::dungeon;

DungeonLevelBuilder::DungeonLevelBuilder()
{

}

void DungeonLevelBuilder::buildDungeonLevel(std::string name, int width, int height) {

}

std::shared_ptr<Room> DungeonLevelBuilder::buildRoom(int id) {
    return nullptr;
}

void DungeonLevelBuilder::buildDoorway(std::shared_ptr<Room> origin, std::shared_ptr<Room> destination,
                                       Room::Direction direction, MoveContraints constraints) {

}

void DungeonLevelBuilder::buildEntrance(std::shared_ptr<Room> room, Room::Direction direction) {

}

void DungeonLevelBuilder::buildExit(std::shared_ptr<Room> room, Room::Direction direction) {

}

void DungeonLevelBuilder::buildItem(std::shared_ptr<Room> room) {

}

void DungeonLevelBuilder::buildCreature(std::shared_ptr<Room> room) {

}

DungeonLevel * DungeonLevelBuilder::getDungeonLevel() const {
    return nullptr;
}
