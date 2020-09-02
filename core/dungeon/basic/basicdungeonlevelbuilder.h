#ifndef BASICDUNGEONLEVELBUILDER_H
#define BASICDUNGEONLEVELBUILDER_H

#include "../dungeonlevelbuilder.h"

namespace core::dungeon::basic {
    class BasicDungeonLevelBuilder : public DungeonLevelBuilder
    {
    public:
        BasicDungeonLevelBuilder();
        virtual ~BasicDungeonLevelBuilder() = default;

        virtual void buildDungeonLevel(const std::string &name, int width, int height) override;
        virtual std::shared_ptr<Room> buildRoom(int id) override;
        virtual void buildDoorway(const std::shared_ptr<Room> &origin, const std::shared_ptr<Room> &destination,
                                  const Room::Direction &direction, const MoveContraints &constraints) override;
        virtual void buildEntrance(const std::shared_ptr<Room> &room, const Room::Direction &direction) override;
        virtual void buildExit(const std::shared_ptr<Room> &room, const Room::Direction &direction) override;
        virtual void buildItem(const std::shared_ptr<Room> &room) override;
        virtual void buildCreature(const std::shared_ptr<Room> &room) override;
    protected:
        virtual void generateItems() override;
        virtual void generateCreatures() override;
    };
}

#endif // BASICDUNGEONLEVELBUILDER_H
