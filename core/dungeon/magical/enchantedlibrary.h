#ifndef ENCHANTEDLIBRARY_H
#define ENCHANTEDLIBRARY_H

#include "../room.h"

namespace core::dungeon::magical {
    /**
     * @brief The EnchantedLibrary class is an enchanted library Room exclusive to MagicalDungeonLevel.
     */
    class EnchantedLibrary : public Room
    {
    public:
        /**
         * @brief The constructor for EnchantedLibrary that accepts the integer ID of the Room and sets all the RoomEdges to MagicWalls.
         * @param id The ID of the Room.
         */
        EnchantedLibrary(int id);
        virtual ~EnchantedLibrary() = default;

        /**
         * @brief Returns a description of this Room, its Item and Creature and its RoomEdges.
         * @return A description of this Room, its Item and Creature and its RoomEdges.
         */
        virtual std::string description() const override;
    };
}



#endif // ENCHANTEDLIBRARY_H
