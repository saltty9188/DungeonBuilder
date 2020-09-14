#ifndef MAGICALDUNGEONLEVELBUILDER_H
#define MAGICALDUNGEONLEVELBUILDER_H

#include "../dungeonlevelbuilder.h"

namespace core::dungeon::magical {
    /**
     * @brief The MagicalDungeonLevelBuilder class is a DungeonLevelBuilder for building MagicalDungeonLevel.
     */
    class MagicalDungeonLevelBuilder : public DungeonLevelBuilder
    {
    public:
        /**
         * @brief The constructor for the MagicDungeonLevelBuilder. Generates the allowed Items and Creatures for MagicalDungeonLevel.
         */
        MagicalDungeonLevelBuilder();
        virtual ~MagicalDungeonLevelBuilder() = default;

        /**
         * @brief Builds a new MagicalDungeonLevel with the provided attributes.
         * @param name   The name of the new dungeon.
         * @param width  The width of the new dungeon.
         * @param height The height of the new dungeon.
         */
        virtual void buildDungeonLevel(const std::string &name, int width, int height) override;

        /**
         * @brief Builds a new Room and adds it to the current MagicalDungeonLevel.
         * @param id The ID of the new Room being built.
         * @return The Room that was just built.
         */
        virtual std::shared_ptr<Room> buildRoom(int id) override;

        /**
         * @brief Builds a Doorway between the origin and destination Rooms.
         *
         * Builds a Doorway between the origin and destination Rooms. The Doorway is set to the Direction
         * specified in the origin Room and the opposing direction in the destination Room.
         * The type of Doorway built is determined by the MoveConstraints parameter.
         *
         * @param origin        The origin Room to house the Doorway.
         * @param destination   The destination Room to house the Doorway.
         * @param direction     The Direction that the Doorway will be built in the origin Room.
         * @param constraints   The MoveConstraints that determine the type of Doorway built. Multiple MoveConstraints
         *                      may be combined using bitwise or (|).
         */
        virtual void buildDoorway(const std::shared_ptr<Room> &origin, const std::shared_ptr<Room> &destination,
                                  const Room::Direction &direction, const MoveContraints &constraints) override;

        /**
         * @brief Builds a OneWayDoor at the specified Direction of the given Room and marks it as the entrance.
         * @param room      The Room to have the entrance built in.
         * @param direction The Direction where the entrance will be built.
         */
        virtual void buildEntrance(const std::shared_ptr<Room> &room, const Room::Direction &direction) override;

        /**
         * @brief Builds a OneWayDoor at the specified Direction of the given Room and marks it as the exit.
         * @param room      The Room to have the exit built in.
         * @param direction The Direction where the exit will be built.
         */
        virtual void buildExit(const std::shared_ptr<Room> &room, const Room::Direction &direction) override;

        /**
         * @brief Builds a clone of a random Item and inserts it into the chosen Room.
         * @param room The Room to receive the Item.
         */
        virtual void buildItem(const std::shared_ptr<Room> &room) override;

        /**
         * @brief Builds a clone of a random Abstract Creature and inserts it into the chosen Room.
         * @param room The Room to receive the Creature.
         */
        virtual void buildCreature(const std::shared_ptr<Room> &room) override;

    protected:

        /**
         * @brief Generates the specific items for this type of DungeonLevel.
         */
        virtual void generateItems() override;

        /**
         * @brief Generates the specific creatures for this type of DungeonLevel.
         */
        virtual void generateCreatures() override;
    };
}


#endif // MAGICALDUNGEONLEVELBUILDER_H
