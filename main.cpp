#include "Character.h"
#include "Characters/Beastmaster/Beastmaster.h"
#include "Characters/Berserker/Berserker.h"
#include "Characters/Cleric/Cleric.h"
#include "Characters/DarkKnight/DarkKnight.h"
#include "Characters/Elementalist/Elementalist.h"
#include "Characters/Mage/Mage.h"
#include "Characters/Paladin/Paladin.h"
#include "Characters/Rogue/Rogue.h"
#include "Characters/Warrior/Warrior.h"

#include "UI.h"
#include <iostream>
#include <limits>
#include <ctime>
#include <cstdlib>
#include <memory>

// Let player choose a Character
std::unique_ptr<Character> chooseCharacter() {
    int choice = 0;
    std::cout << "Choose your character:\n";
    std::cout << "1. Beastmaster\n";
    std::cout << "2. Berserker\n";
    std::cout << "3. Cleric\n";
    std::cout << "4. Dark Knight\n";
    std::cout << "5. Elementalist\n";
    std::cout << "6. Mage\n";
    std::cout << "7. Paladin\n";
    std::cout << "8. Rogue\n";
    std::cout << "9. Warrior\n";
    
    while (!(std::cin >> choice)) {
        std::cout << "Enter a valid number: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    std::unique_ptr<Character> player;
    switch (choice) {
        case 1:
            player = std::make_unique<Beastmaster>("Player Beastmaster");
            break;
        case 2:
            player = std::make_unique<Berserker>("Player Berserker");
            break;
        case 3:
            player = std::make_unique<Cleric>("Player Cleric");
            break;
        case 4:
            player = std::make_unique<DarkKnight>("Player Dark Knight");
            break;
        case 5:
            player = std::make_unique<Elementalist>("Player Elementalist");
            break;
        case 6:
            player = std::make_unique<Mage>("Player Mage");
            break;
        case 7:
            player = std::make_unique<Paladin>("Player Paladin");
            break;
        case 8:
            player = std::make_unique<Rogue>("Player Rogue");
            break;
        case 9:
            player = std::make_unique<Warrior>("Player Warrior");
            break;
        default: // This shouldnt be called, just in case
            std::cout << "Invalid selection. Defaulting to Warrior. \n";
            player = std::make_unique<Warrior>("Player Warrior");
            break;
    }
    return player;
}

// Function to randomly choose an enemy character
std::unique_ptr<Character> randomEnemy() {
    int choice = std::rand() % 9 + 1; // Generates a number between 1 and 9
    std::unique_ptr<Character> enemy;
    switch (choice) {
        case 1:
            enemy = std::make_unique<Beastmaster>("Enemy Beastmaster");
            break;
        case 2:
            enemy = std::make_unique<Berserker>("Enemy Berserker");
            break;
        case 3:
            enemy = std::make_unique<Cleric>("Enemy Cleric");
            break;
        case 4:
            enemy = std::make_unique<DarkKnight>("Enemy Dark Knight");
            break;
        case 5:
            enemy = std::make_unique<Elementalist>("Enemy Elementalist");
            break;
        case 6:
            enemy = std::make_unique<Mage>("Enemy Mage");
            break;
        case 7:
            enemy = std::make_unique<Paladin>("Enemy Paladin");
            break;
        case 8:
            enemy = std::make_unique<Rogue>("Enemy Rogue");
            break;
        case 9:
            enemy = std::make_unique<Warrior>("Enemy Warrior");
            break;
        default:
            enemy = std::make_unique<Warrior>("Enemy Warrior");
            break;
    }
    return enemy;
}

int main() {
    // Seed random number generator
    std::srand(static_cast<unsigned>(std::time(nullptr)));
    
    UI::clearScreen();
    auto player = chooseCharacter();
    auto enemy = randomEnemy();

    std::cout << "\nYou chose: " << player -> getName();
    std::cout << "\nEnemy is: " << enemy -> getName() << "\n";
    std::cout << "Battle Starts! \n";
    UI::pause(1500); //1.5 sec

    const int playerMaxHP = player -> getHealth();
    const int enemyMaxHP = enemy -> getHealth();

    bool playerTurn = true;
    while (player -> isAlive() && enemy -> isAlive()) {
        UI::clearScreen();
        UI::drawBattleScene(player->getName(), player->getHealth(), playerMaxHP,
                            enemy->getName(), enemy->getHealth(), enemyMaxHP);

        if (playerTurn) {
            std::cout << "\nYour Turn:\n";
            int action = UI::displayBattleMenu();
            switch (action) {
                case 1: // Attack
                    player -> attack(*enemy, playerTurn);
                    break;
                case 2: // Defend
                    player -> defend();
                    break;
                default:
                    std::cout << "Invalid action default to attack\n";
                    player -> attack(*enemy, playerTurn);
                    break;
            }
        } else {
            std::cout << "\nEnemy turn:\n";
            enemy -> attack(*player, false);
        }

        // Announce winner
        if (enemy ->getHealth() <= 0) {
            std::cout << player -> getName() << " wins!\n";
            break;
        } else if (player -> getHealth() <= 0){
            std::cout << enemy -> getName() << " wins!\n";
            break;
        }

        playerTurn = !playerTurn;
        UI::waitForKeyPress();
    }

    // Memory cleanup
    return 0;
}
