#ifndef BLOCKEDDOORWAY_H
#define BLOCKEDDOORWAY_H

#include "../doorway.h"

namespace core::dungeon::common {
    class BlockedDoorway : public Doorway
    {
    public:
        BlockedDoorway(Room &parent);
        virtual ~BlockedDoorway() = default;
        virtual std::string description() const override;
        virtual char displayCharacter() const override;
        virtual bool isPassage() const override;
    };
}

#endif // BLOCKEDDOORWAY_H
