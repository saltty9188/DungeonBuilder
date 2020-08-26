#ifndef ONEWAYDOOR_H
#define ONEWAYDOOR_H

#include "../doorway.h"

namespace core::dungeon::common {
    class OneWayDoor : public Doorway
    {
    public:
        OneWayDoor(Room &parent);
        virtual ~OneWayDoor() = default;
        virtual std::string description() const override;
        virtual char displayCharacter() const override;
        virtual bool isPassage() const override;
    };
}


#endif // ONEWAYDOOR_H
