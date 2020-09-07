#ifndef BASICDUNGEONLEVEL_H
#define BASICDUNGEONLEVEL_H

#include "../dungeonlevel.h"

namespace core::dungeon::basic {
    class BasicDungeonLevel : public DungeonLevel
    {
    public:
        /**
         * @brief The constructor for BasicDungeonLevel accepting a string containing the name of the BasicDungeonLevel and its width and height.
         * @param name   The name of the BasicDungeonLevel.
         * @param width  The width of the BasicDungeonLevel.
         * @param height The height of the BasicDungeonLevel.
         */
        BasicDungeonLevel(const std::string &name, int width, int height);
        virtual ~BasicDungeonLevel() = default;

        /**
         * @brief A description of this Dungeon Level.
         * @return A description of this Dungeon Level.
         */
        virtual std::string description() const override;
    };
}


#endif // BASICDUNGEONLEVEL_H
