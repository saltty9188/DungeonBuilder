#ifndef DUNGEONLEVELBUILDER_H
#define DUNGEONLEVELBUILDER_H

#include <string>
#include "room.h"
#include "dungeonlevel.h"
#include "../items/consumable.h"
#include "../items/weapon.h"

namespace core::dungeon {
using namespace core::items;
    class DungeonLevelBuilder
    {
    public:
        DungeonLevelBuilder();
        virtual ~DungeonLevelBuilder() = default;

        virtual void buildDungeonLevel(std::string name, int width, int height);
        virtual std::shared_ptr<Room> buildRoom(int id);

        enum class MoveContraints : unsigned {
            None = 0,
            OriginImpassable = 1,
            DestinationImpassable = 2,
            OriginLocked = 4,
            DestinationLocked = 8
        };

        virtual void buildDoorway(std::shared_ptr<Room> origin, std::shared_ptr<Room> destination,
                          Room::Direction direction, MoveContraints constraints);
        virtual void buildEntrance(std::shared_ptr<Room> room, Room::Direction direction);
        virtual void buildExit(std::shared_ptr<Room> room, Room::Direction direction);
        virtual void buildItem(std::shared_ptr<Room> room);
        virtual void buildCreature(std::shared_ptr<Room> room);
        DungeonLevel * getDungeonLevel() const;

    protected:
        void insertConsumable(std::shared_ptr<Consumable> consumable);
        void insertWeapon(std::shared_ptr<Weapon> weapon);
        virtual void generateItems() = 0;
        void insertCreature(std::shared_ptr<AbstractCreature> creature);
        virtual void generateCreatures() = 0;
        std::shared_ptr<Item> randomItem() const;
        std::shared_ptr<AbstractCreature> randomCreature() const;
        void buildDungeonLevel(std::shared_ptr<DungeonLevel> dungeonLevel);

    private:
        std::shared_ptr<DungeonLevel> _level;
        std::vector<std::shared_ptr<Consumable>> _prototypeConsumables;
        std::vector<std::shared_ptr<Weapon>> _prototypeWeapons;
        std::vector<std::shared_ptr<AbstractCreature>> _prototypeCreatures;
    };

    DungeonLevelBuilder::MoveContraints operator|(const DungeonLevelBuilder::MoveContraints &lhs, const DungeonLevelBuilder::MoveContraints &rhs);
    DungeonLevelBuilder::MoveContraints operator&(const DungeonLevelBuilder::MoveContraints &lhs, const DungeonLevelBuilder::MoveContraints &rhs);
}


#endif // DUNGEONLEVELBUILDER_H
