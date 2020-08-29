#ifndef BASICDUNGEONLEVEL_H
#define BASICDUNGEONLEVEL_H

#include "../dungeonlevel.h"

namespace core::dungeon::basic {
    class BasicDungeonLevel : public DungeonLevel
    {
    public:
        BasicDungeonLevel(std::string name, int width, int height);
        virtual ~BasicDungeonLevel() = default;

        virtual std::string description() const override;
    };
}


#endif // BASICDUNGEONLEVEL_H
