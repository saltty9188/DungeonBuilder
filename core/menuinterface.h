#ifndef MENUINTERFACE_H
#define MENUINTERFACE_H

#include <iostream>
#include <string>

namespace core {
    class MenuInterface
    {
    public:
        /**
         * @brief The constructor for MenuInterface accepting a reference to an ostream object and an istream object.
         * @param display The ostream object reference that the MenuInterface will use to display text.
         * @param input   The istream object reference that the MenuInterface will use to receive input.
         */
        MenuInterface(std::ostream &display, std::istream &input);
        ~MenuInterface() = default;

        /**
         * @brief Displays the welcome message to the console.
         * @param author The author of the program.
         * @param title  The title of the program.
         */
        void displayWelcome(const std::string &author, const std::string &title) const;

        /**
         * @brief Initiates the main loop of the program.
         */
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
