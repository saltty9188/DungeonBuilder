#ifndef MAGICALDUNGEONLEVELBUILDER_H
#define MAGICALDUNGEONLEVELBUILDER_H

#include "../dungeonlevelbuilder.h"

namespace core::dungeon::magical {
    class MagicalDungeonLevelBuilder : public DungeonLevelBuilder
    {
    public:
        MagicalDungeonLevelBuilder();
        virtual ~MagicalDungeonLevelBuilder() = default;

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


#endif // MAGICALDUNGEONLEVELBUILDER_H
