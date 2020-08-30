#ifndef BASICDUNGEONLEVELBUILDER_H
#define BASICDUNGEONLEVELBUILDER_H

#include "../dungeonlevelbuilder.h"

namespace core::dungeon::basic {
    class BasicDungeonLevelBuilder : public DungeonLevelBuilder
    {
    public:
        BasicDungeonLevelBuilder();
        virtual ~BasicDungeonLevelBuilder() = default;

        virtual void buildDungeonLevel(std::string name, int width, int height) override;
        virtual std::shared_ptr<Room> buildRoom(int id) override;
        virtual void buildDoorway(std::shared_ptr<Room> origin, std::shared_ptr<Room> destination,
                                  Room::Direction direction, MoveContraints constraints) override;
        virtual void buildEntrance(std::shared_ptr<Room> room, Room::Direction direction) override;
        virtual void buildExit(std::shared_ptr<Room> room, Room::Direction direction) override;
        virtual void buildItem(std::shared_ptr<Room> room) override;
        virtual void buildCreature(std::shared_ptr<Room> room) override;
        virtual DungeonLevel * getDungeonLevel() const override;
    protected:
        virtual void generateItems() override;
        virtual void generateCreatures() override;
    private:
        std::shared_ptr<DungeonLevel> _level;
    };
}

#endif // BASICDUNGEONLEVELBUILDER_H
