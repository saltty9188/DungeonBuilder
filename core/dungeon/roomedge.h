#ifndef ROOMEDGE_H
#define ROOMEDGE_H

#include <string>
#include "room.h"

namespace core::dungeon {
    class RoomEdge
    {
    public:
        RoomEdge();
        virtual ~RoomEdge() = default;

        /**
         * @brief The description of this RoomEdge.
         * @return The description of this RoomEdge.
         */
        virtual std::string description() const = 0;

        /**
         * @brief Returns the character displayed in the dungeon view output.
         * @return The character displayed in the dungeon view output.
         */
        virtual char displayCharacter() const = 0;

        /**
         * @brief Returns true if this RoomEdge is a Doorway and is connected to another Doorway.
         * @return True if this RoomEdge is a Doorway and is connected to another Doorway, false otherwise.
         */
        virtual bool isPassage() const = 0;

        /**
         * @brief Sets the direction that this RoomEdge is occupying.
         * @param direction The direction this RoomEdge will be occupying.
         */
        void setDirection(const Room::Direction &direction);
    protected:
        /**
         * @brief Returns the direction this RoomEdge occupies.
         * @return The direction this RoomEdge occupies.
         */
        Room::Direction direction() const;
    private:
        Room::Direction _direction;
    };
}

#endif // ROOMEDGE_H
