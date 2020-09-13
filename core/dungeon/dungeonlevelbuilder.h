#ifndef DUNGEONLEVELBUILDER_H
#define DUNGEONLEVELBUILDER_H

#include <string>
#include "room.h"
#include "dungeonlevel.h"
#include "../items/consumable.h"
#include "../items/weapon.h"

namespace core::dungeon {
using namespace core::items;

    /**
     * @brief The DungeonLevelBuilder class is the abstract base for building DungeonLevel.
     */
    class DungeonLevelBuilder
    {
    public:
        DungeonLevelBuilder();
        virtual ~DungeonLevelBuilder() = default;

        /**
         * @brief Builds a new DungeonLevel with the provided attributes.
         * @param name   The name of the new dungeon.
         * @param width  The width of the new dungeon.
         * @param height The height of the new dungeon.
         */
        virtual void buildDungeonLevel(const std::string &name, int width, int height);

        /**
         * @brief Builds a new Room and adds it to the current Magical Dungeon Level.
         * @param id The ID of the new Room being built.
         * @return The Room that was just built.
         */
        virtual std::shared_ptr<Room> buildRoom(int id);

        /**
         * @brief Enumeration that is used as a bitmask for determining which Doorways are built in the
         *        buildDoorway function.
         */
        enum class MoveContraints : unsigned {
            None = 0,
            OriginImpassable = 1,
            DestinationImpassable = 2,
            OriginLocked = 4,
            DestinationLocked = 8
        };


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
                          const Room::Direction &direction, const MoveContraints &constraints);

        /**
         * @brief Builds a OneWayDoor at the specified Direction of the given Room and marks it as the entrance.
         * @param room      The Room to have the entrance built in.
         * @param direction The Direction where the entrance will be built.
         */
        virtual void buildEntrance(const std::shared_ptr<Room> &room, const Room::Direction &direction);

        /**
         * @brief Builds a OneWayDoor at the specified Direction of the given Room and marks it as the exit.
         * @param room      The Room to have the exit built in.
         * @param direction The Direction where the exit will be built.
         */
        virtual void buildExit(const std::shared_ptr<Room> &room, const Room::Direction &direction);

        /**
         * @brief Builds a clone of a random Item and inserts it into the chosen Room.
         * @param room The Room to receive the Item.
         */
        virtual void buildItem(const std::shared_ptr<Room> &room);

        /**
         * @brief Builds a clone of a random Abstract Creature and inserts it into the chosen Room.
         * @param room The Room to receive the Creature.
         */
        virtual void buildCreature(const std::shared_ptr<Room> &room);

        /**
         * @brief Returns a pointer to the currently built DungeonLevel.
         * @return A pointer to the currently built DungeonLevel.
         */
        DungeonLevel * getDungeonLevel() const;

    protected:
        /**
         * @brief Inserts the given Consumable into the list of allowed Consumables.
         * @param consumable The Consumable to be inserted.
         */
        void insertConsumable(const std::shared_ptr<Consumable> &consumable);

        /**
         * @brief Inserts the given Weapon into the list of allowed Weapons.
         * @param weapon The Weapon to be inserted.
         */
        void insertWeapon(const std::shared_ptr<Weapon> &weapon);

        /**
         * @brief Generates the specific items for the DungeonLevel.
         */
        virtual void generateItems() = 0;

        /**
         * @brief Inserts the given Creature into the list of allowed Creatures.
         * @param creature The Creature to be inserted.
         */
        void insertCreature(const std::shared_ptr<AbstractCreature> &creature);

        /**
         * @brief Generates the specific creatures for the DungeonLevel.
         */
        virtual void generateCreatures() = 0;

        /**
         * @brief Returns a random Item (Weapon or Consumable) from the list of allowed Items.
         * @return A random Item from the list of allowed Items.
         */
        std::shared_ptr<Item> randomItem() const;

        /**
         * @brief Returns a random Creature from the list of allowed Creatures.
         * @return A random Creature from the list of allowed Creatures.
         */
        std::shared_ptr<AbstractCreature> randomCreature() const;

        /**
         * @brief Used by subclasses to properly build their specific type of DungeonLevel.
         * @param A pointer to the new DungeonLevel.
         */
        void buildDungeonLevel(DungeonLevel *dungeonLevel);

    private:
        DungeonLevel * _level;
        std::vector<std::shared_ptr<Consumable>> _prototypeConsumables;
        std::vector<std::shared_ptr<Weapon>> _prototypeWeapons;
        std::vector<std::shared_ptr<AbstractCreature>> _prototypeCreatures;
    };

    /**
     * @brief Overloads the bitwise or operator for use with two MoveContraints values.
     * @param lhs The first MoveConstraints value.
     * @param rhs The second MoveConstraints value.
     * @return The result of lhs | rhs.
     */
    DungeonLevelBuilder::MoveContraints operator|(const DungeonLevelBuilder::MoveContraints &lhs, const DungeonLevelBuilder::MoveContraints &rhs);

    /**
     * @brief Overloads the bitwise and operator for use with two MoveContraints values.
     * @param lhs The first MoveConstraints value.
     * @param rhs The second MoveConstraints value.
     * @return The result of lhs & rhs.
     */
    DungeonLevelBuilder::MoveContraints operator&(const DungeonLevelBuilder::MoveContraints &lhs, const DungeonLevelBuilder::MoveContraints &rhs);
}


#endif // DUNGEONLEVELBUILDER_H
