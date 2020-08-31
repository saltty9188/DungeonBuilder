#ifndef MAGICALDUNGEONLEVELBUILDER_H
#define MAGICALDUNGEONLEVELBUILDER_H

#include "../dungeonlevelbuilder.h"

namespace core::dungeon::magical {
    class MagicalDungeonLevelBuilder : public DungeonLevelBuilder
    {
    public:
        MagicalDungeonLevelBuilder();
        virtual ~MagicalDungeonLevelBuilder() = default;

        virtual void buildDungeonLevel(std::string name, int width, int height) override;
        virtual std::shared_ptr<Room> buildRoom(int id) override;
        virtual void buildDoorway(std::shared_ptr<Room> origin, std::shared_ptr<Room> destination,
                                  Room::Direction direction, MoveContraints constraints) override;
        virtual void buildEntrance(std::shared_ptr<Room> room, Room::Direction direction) override;
        virtual void buildExit(std::shared_ptr<Room> room, Room::Direction direction) override;
        virtual void buildItem(std::shared_ptr<Room> room) override;
        virtual void buildCreature(std::shared_ptr<Room> room) override;

    protected:
        virtual void generateItems() override;
        virtual void generateCreatures() override;
    };
}


#endif // MAGICALDUNGEONLEVELBUILDER_H
