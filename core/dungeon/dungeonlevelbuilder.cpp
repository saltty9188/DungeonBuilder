#include "dungeonlevelbuilder.h"
#include "core/game.h"
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

void DungeonLevelBuilder::insertItem(std::shared_ptr<Item> item) {
    _prototypeItems.push_back(item);
}

void DungeonLevelBuilder::insertCreature(std::shared_ptr<AbstractCreature> creature) {
    _prototypeCreatures.push_back(creature);
}

std::shared_ptr<Item> DungeonLevelBuilder::randomItem() const{
    int randomIndex = (int)(core::Game::instance().randomDouble() * _prototypeItems.size());
    return _prototypeItems[randomIndex];
}

std::shared_ptr<AbstractCreature> DungeonLevelBuilder::randomCreature() const {
    int randomIndex = (int)(core::Game::instance().randomDouble() * _prototypeCreatures.size());
    return _prototypeCreatures[randomIndex];
}

/**
 * @brief Overloads the bitwise or operator for use with two MoveContraints values.
 * @param lhs The first MoveConstraints value.
 * @param rhs The second MoveConstraints value.
 * @return The result of lhs | rhs.
 */
DungeonLevelBuilder::MoveContraints core::dungeon::operator|(const DungeonLevelBuilder::MoveContraints &lhs,
                                                             const DungeonLevelBuilder::MoveContraints &rhs) {
    return static_cast<DungeonLevelBuilder::MoveContraints>(static_cast<unsigned>(lhs) | static_cast<unsigned>(rhs));
}

/**
 * @brief Overloads the bitwise and operator for use with two MoveContraints values.
 * @param lhs The first MoveConstraints value.
 * @param rhs The second MoveConstraints value.
 * @return The result of lhs & rhs.
 */
DungeonLevelBuilder::MoveContraints core::dungeon::operator&(const DungeonLevelBuilder::MoveContraints &lhs,
                                                             const DungeonLevelBuilder::MoveContraints &rhs) {
    return static_cast<DungeonLevelBuilder::MoveContraints>(static_cast<unsigned>(lhs) & static_cast<unsigned>(rhs));
}
