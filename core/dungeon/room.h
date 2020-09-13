#ifndef ROOM_H
#define ROOM_H

#include <string>
#include <array>
#include <memory>
#include "../creatures/abstractcreature.h"
#include "../items/item.h"

using core::items::Item;
using core::creatures::AbstractCreature;

namespace core::dungeon {
    class RoomEdge;
    /**
     * @brief The Room class is an abstract represenation of a Room within the DungeonLevel.
     */
    class Room
    {
    public:
        /**
         * @brief The constructor for Room that accepts the integer ID of the Room.
         * @param id The ID of the Room.
         */
        Room(int id);
        virtual ~Room() = default;

        /**
         * @brief Returns a description of this Room, its Item and Creature and its RoomEdges.
         * @return A description of this Room, its Item and Creature and its RoomEdges.
         */
        virtual std::string description() const = 0;

        /**
         * @brief Returns a graphical display of this Room encased in an Array of Strings.
         * @return A graphical display of this Room encased in an Array of Strings.
         */
        std::array<std::string, 5> display() const;
        int id() const;

        /**
         * @brief Returns the item contained within this room.
         * @return The item contained within this room.
         */
        std::shared_ptr<Item> item() const;

        /**
         * @brief Sets the Item contained within this Room to be the given Item.
         * @param newItem The Item to be put in this Room.
         */
        void setItem(const std::shared_ptr<Item> &newItem);

        /**
         * @brief Returns the Creature contained within this room.
         * @return The Creature contained within this room.
         */
        std::shared_ptr<AbstractCreature> creature() const;

        /**
         * @brief Sets the Creature contained within this Room to be the given Creature.
         * @param newCreature The Creature to be put in this Room.
         */
        void setCreature(const std::shared_ptr<AbstractCreature> &newCreature);

        /**
         * @brief Enumeration defining the four edges of anu given Room.
         */
        enum class Direction : unsigned {North, South, East, West};

        /**
         * @brief Returns the opposite Direction to the suppiled Direction (i.e. North will return South).
         * @param direction The Direction the user needs the Opposite of.
         * @return The opposite Direction to the suppiled Direction.
         */
        static Direction oppositeDirection(const Direction &direction);

        /**
         * @brief Sets the edge at the given Direction to the given Room Edge.
         * @param direction The Direction of the edge to be set.
         * @param roomEdge  The Room Edge being set.
         */
        void setEdge(const Direction &direction, const std::shared_ptr<RoomEdge> &roomEdge);

        /**
         * @brief Returns a shared pointer to the Room Edge at the given Direction.
         * @param direction The Direction of the Room Edge to be retrieved.
         * @return A shared pointer to the Room Edge at the given Direction.
         */
        std::shared_ptr<RoomEdge> edge(const Direction &direction) const;
    private:
        int _id;
        std::shared_ptr<Item> _item;
        std::shared_ptr<AbstractCreature> _creature;
        std::array<std::shared_ptr<RoomEdge>, 4> _edges;
        bool hasExit() const;

    };

    /**
     * @brief Overloaded ostream out operator that outputs the supplied level's description.
     * @param out The ostream object being output to.
     * @param room The room being described.
     * @return The ostream object that was output to.
     */
    std::ostream& operator<<(std::ostream &out, const Room &room);
}


#endif // ROOM_H
