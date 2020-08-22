#ifndef MENUINTERFACE_H
#define MENUINTERFACE_H

#include <iostream>
#include <string>

namespace core {
    class MenuInterface
    {
    public:
        MenuInterface(std::ostream &display, std::istream &input);
        ~MenuInterface() = default;
        void displayWelcome(const std::string author, const std::string title) const;
        void run() const;

    private:
        std::ostream &_display;
        std::istream &_input;

        void displayMainMenu() const;
        void generateRandomDungeon() const;
        bool quitGame() const;
        void displayViewMenu() const;
        void displayExplorationMenu() const;
        void describeRoom() const;
    };
}

#endif // MENUINTERFACE_H
