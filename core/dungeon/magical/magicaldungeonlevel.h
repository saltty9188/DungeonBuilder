#ifndef MAGICALDUNGEONLEVEL_H
#define MAGICALDUNGEONLEVEL_H

#include "../dungeonlevel.h"

namespace core::dungeon::magical {
    class MagicalDungeonLevel : public DungeonLevel
    {
    public:
        MagicalDungeonLevel(const std::string &name, int width, int height);
        virtual ~MagicalDungeonLevel() = default;
        virtual std::string description() const override;
    };
}



#endif // MAGICALDUNGEONLEVEL_H
