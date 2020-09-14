#ifndef MAGICALDUNGEONLEVEL_H
#define MAGICALDUNGEONLEVEL_H

#include "../dungeonlevel.h"

namespace core::dungeon::magical {
    /**
     * @brief The MagicalDungeonLevel class represents the magical type of DungeonLevel.
     */
    class MagicalDungeonLevel : public DungeonLevel
    {
    public:
        /**
         * @brief The constructor for MagicalDungeonLevel accepting a string containing the name of the MagicalDungeonLevel and its width and height.
         * @param name   The name of the MagicalDungeonLevel.
         * @param width  The width of the MagicalDungeonLevel.
         * @param height The height of the MagicalDungeonLevel.
         */
        MagicalDungeonLevel(const std::string &name, int width, int height);
        virtual ~MagicalDungeonLevel() = default;

        /**
         * @brief A description of this Dungeon Level.
         * @return A description of this Dungeon Level.
         */
        virtual std::string description() const override;
    };
}



#endif // MAGICALDUNGEONLEVEL_H
