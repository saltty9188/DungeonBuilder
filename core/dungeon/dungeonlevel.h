#ifndef DUNGEONLEVEL_H
#define DUNGEONLEVEL_H

#include <string>
#include <memory>
#include "room.h"

namespace core::dungeon {
    class DungeonLevel
    {
    public:
        DungeonLevel(std::string name, int width, int height);
        virtual ~DungeonLevel() = default;

        bool addRoom(std::shared_ptr<Room> room);
        std::shared_ptr<Room> retrieveRoom(int id);
        int width() const;
        int height() const;
        int numberOfRooms() const;
        std::string name() const;
        //virtual std::string description() const = 0;
        std::vector<std::string> display() const;

    private:
        std::string _name;
        int _width;
        int _height;
        std::vector<std::shared_ptr<Room>> _rooms;
    };

    std::ostream& operator<<(std::ostream &out, const DungeonLevel &level);
}


#endif // DUNGEONLEVEL_H
