#ifndef DUNGEONLEVELBUILDER_H
#define DUNGEONLEVELBUILDER_H

#include <string>
#include "room.h"
#include "dungeonlevel.h"

namespace core::dungeon {
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
        virtual DungeonLevel * getDungeonLevel() const;
    };
}


#endif // DUNGEONLEVELBUILDER_H
