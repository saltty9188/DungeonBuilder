#ifndef ENCHANTEDLIBRARY_H
#define ENCHANTEDLIBRARY_H

#include "../room.h"

namespace core::dungeon::magical {
    class EnchantedLibrary : public Room
    {
    public:
        EnchantedLibrary(int id);
        virtual ~EnchantedLibrary() = default;
        virtual std::string description() const override;
    };
}



#endif // ENCHANTEDLIBRARY_H
