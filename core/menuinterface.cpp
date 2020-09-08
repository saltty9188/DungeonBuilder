#include "menuinterface.h"
#include "game.h"
#include "dungeon/basic/basicdungeonlevelbuilder.h"
#include "dungeon/magical/magicaldungeonlevelbuilder.h"

using namespace core;
using core::dungeon::basic::BasicDungeonLevelBuilder;
using core::dungeon::magical::MagicalDungeonLevelBuilder;

MenuInterface::MenuInterface(std::ostream &display, std::istream &input): _display{display}, _input{input} {

}

void MenuInterface::displayWelcome(const std::string &author, const std::string &title) const{
    _display << "Welcome to: " << title << std::endl;
    _display << "      Developed by " << author << std::endl;
    _display << "COMP 3023 Software Development with C++" << std::endl;
}


void MenuInterface::run() const{
    displayMainMenu();
}

void MenuInterface::displayMainMenu() const {
    // Want the menu to stay up until the user goes to another menu
    while(true) {
        // Prompt for user input
        _display << "\nWhat would you like to do?" << std::endl;
        _display << "    (g)enerate the example level" << std::endl;
        _display << "    (r)andom dungeon level" << std::endl;
        _display << "    (q)uit" << std::endl;
        std::string userInput{};
        _input >> userInput;

        switch(userInput.at(0)) {
        case 'g':
        case 'G':
            _display << "\nCreating Example Dungeon Level..." << std::endl;
            Game::instance().createExampleLevel();
            _display << "Dungeon level created!" << std::endl;
            displayViewMenu();
            break;

        case 'r':
        case 'R':
            generateRandomDungeon();
            displayViewMenu();
            break;

        case 'q':
        case 'Q':
            if(quitGame()) {
                return;
            }
            break;

        default:
            // Handle invalid input
            _display << "\nInvalid input. Enter a valid input." << std::endl;
        }
    }
}

void MenuInterface::generateRandomDungeon() const {
    // Prompt for the user to enter the level name.
    _display << "\nWhat would you like to call the level?" << std::endl;
    std::string levelName;
    // Ignore newline character
    _input.ignore();
    std::getline (_input, levelName);

    bool selecting{true};
    int rows{0};
    // Loop the prompt for the amount of rows until the user inputs a valid number.
    while(selecting) {
        _display << "\nHow many rows in " << levelName << std::endl;
        std::string rowString{};
        _input >> rowString;

        try {
            rows = std::stoi(rowString);
            if(rows <= 0 || rows > 4) {
                _display << "\nInvalid input. Enter a value between 1 and 4." << std::endl;
            } else {
                selecting = false;
            }
        } catch (std::invalid_argument const &e) {
            _display << "\nInvalid input. Enter an integer value." << std::endl;
        }
    }

    selecting = true;
    int columns{0};
    // Loop the prompt for the amount of columns until the user inputs a valid number.
    while(selecting) {
        _display << "\nHow many columns in " << levelName << std::endl;
        std::string columnString{};
        _input >> columnString;

        try {
            columns = std::stoi(columnString);
            if(columns <= 0 || columns > 4) {
                _display << "\nInvalid input. Enter a value between 1 and 4." << std::endl;
            } else {
                selecting = false;
            }
        } catch (std::invalid_argument const &e) {
            _display << "\nInvalid input. Enter an integer value." << std::endl;
        }
    }

    selecting = true;
    while(selecting) {
        _display << "\nWhat type of dungeon level is it? (b)asic or (m)agical" << std::endl;
        std::string dungeonType{};
        _input >> dungeonType;
        switch(dungeonType.at(0)) {
        case 'B':
        case 'b':
            Game::instance().setDungeonType(std::make_unique<BasicDungeonLevelBuilder>());
            selecting = false;
            break;
        case 'M':
        case 'm':
            Game::instance().setDungeonType(std::make_unique<MagicalDungeonLevelBuilder>());
            selecting = false;
            break;

        default:
            _display << "\nInvalid input. Enter a valid option." << std::endl;
        }
    }

    _display << "\nCreating " << levelName << "..." << std::endl;
    Game::instance().createRandomLevel(levelName, columns, rows);
    _display << "Dungeon level created!" << std::endl;

}

bool MenuInterface::quitGame() const {
    // Want menu to stay looping until valid input is received
    while(true) {
        _display << "\n*Are you sure you want to quit? (y/n)*" << std::endl;
        std::string userInput{};
        _input >> userInput;
        switch(userInput.at(0)) {
        case 'y':
        case 'Y':
            _display << "\nGoodbye!" << std::endl;
            return true;

        case 'n':
        case 'N':
            return false;

        default:
            _display << "\nInvalid input, enter valid input." << std::endl;
        }
    }
}

void MenuInterface::displayViewMenu() const {
    // Loop until we return to the previous menu
    while(true) {
        _display << "\n What would you like to do?" << std::endl;
        _display << "    (d)escribe the dungeon level" << std::endl;
        _display << "    (v)iew the dungeon level" << std::endl;
        _display << "    (r)eturn to the main menu" << std::endl;
        std::string userInput{};
        _input >> userInput;
        switch (userInput.at(0)) {
        case 'd':
        case 'D':
            _display << "\n" << Game::instance().levelDescription() << std::endl;
            displayExplorationMenu();
            break;

        case 'v':
        case 'V':
            _display << std::endl;
            Game::instance().displayLevel(_display);
            _display << "\n*Press Enter to continue*" << std::endl;
            _input.ignore();
            _input.get();
            break;

        case 'r':
        case 'R':
            _display << "\nReturning to main menu" << std::endl;
            return;

        default:
            _display << "Invalid input, enter a valid option." << std::endl;
        }
    }
}

void MenuInterface::displayExplorationMenu() const {
    while(true) {
        _display << "\nWhat would you like to do?" << std::endl;
        _display << "    (d)escribe a room" << std::endl;
        _display << "    (r)eturn to previous menu" << std::endl;
        std::string userInput{};
        _input >> userInput;
        switch(userInput.at(0)) {
        case 'd':
        case 'D':
            describeRoom();
            break;

        case 'r':
        case 'R':
            _display << "\nReturning to view menu" << std::endl;
            return;

        default:
            _display << "\nInvalid input, enter a valid option." << std::endl;
        }
    }
}

void MenuInterface::describeRoom() const {
    bool selecting{true};
    // Want to loop until the user inputs a valid room number.
    while(selecting) {
        _display << "\nWhich room would you like to describe? (1-" << Game::instance().numberOfRooms() << ")" << std::endl;
        std::string roomNumberString{};
        _input >> roomNumberString;
        int roomNumber{};
        try {
            roomNumber = std::stoi(roomNumberString);
            if(roomNumber >= 1 && roomNumber <= Game::instance().numberOfRooms()) {
                _display << "\nRoom *" << roomNumber << "* is..." << std::endl;
                _display << Game::instance().roomDescription(roomNumber) << std::endl;
                _display << "\n*Press Enter to continue*" << std::endl;
                _input.ignore();
                _input.get();
                selecting = false;
            } else {
                _display << "\nEnter a valid room number." << std::endl;
            }

        } catch (std::invalid_argument const &e) {
            _display << "\nInvalid input. Enter an integer value." << std::endl;
        }
    }

}
