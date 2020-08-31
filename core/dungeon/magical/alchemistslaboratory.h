#ifndef ALCHEMISTSLABORATORY_H
#define ALCHEMISTSLABORATORY_H

#include "../room.h"

namespace core::dungeon::magical {
    class AlchemistsLaboratory : public Room
    {
    public:
        AlchemistsLaboratory(int id);
        virtual ~AlchemistsLaboratory() = default;
        virtual std::string description() const override;
    };
}


#endif // ALCHEMISTSLABORATORY_H
