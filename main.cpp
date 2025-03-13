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

// Let player choose a Character
Character* chooseCharacter() {
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
    std::cin >> choice;

    // Clear any leftover input
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    Character* player = nullptr;
    switch (choice) {
        case 1:
            player = new Beastmaster("Player Beastmaster");
            break;
        case 2:
            player = new Berserker("Player Berserker");
            break;
        case 3:
            player = new Cleric("Player Cleric");
            break;
        case 4:
            player = new DarkKnight("Player Dark Knight");
            break;
        case 5:
            player = new Elementalist("Player Elementalist");
            break;
        case 6:
            player = new Mage("Player Mage");
            break;
        case 7:
            player = new Paladin("Player Paladin");
            break;
        case 8:
            player = new Rogue("Player Rogue");
            break;
        case 9:
            player = new Warrior("Player Warrior");
            break;
        default:
            std::cout << "Invalid selection. Defaulting to Warrior. \n";
            break;
    }
    return player;
}

// Function to randomly choose an enemy character
Character* randomEnemy() {
    int choice = std::rand() % 9 + 1; // Generates a number between 1 and 9
    Character* enemy = nullptr;
    switch (choice) {
        case 1:
            enemy = new Beastmaster("Enemy Beastmaster");
            break;
        case 2:
            enemy = new Berserker("Enemy Berserker");
            break;
        case 3:
            enemy = new Cleric("Enemy Cleric");
            break;
        case 4:
            enemy = new DarkKnight("Enemy Dark Knight");
            break;
        case 5:
            enemy = new Elementalist("Enemy Elementalist");
            break;
        case 6:
            enemy = new Mage("Enemy Mage");
            break;
        case 7:
            enemy = new Paladin("Enemy Paladin");
            break;
        case 8:
            enemy = new Rogue("Enemy Rogue");
            break;
        case 9:
            enemy = new Warrior("Enemy Warrior");
            break;
        default:
            enemy = new Warrior("Enemy Warrior");
            break;
    }
    return enemy;
}

int main() {
    // Seed random number generator
    std::srand(static_cast<unsigned>(std::time(nullptr)));
    
    UI::clearScreen();
    Character* player = chooseCharacter();
    Character* enemy = randomEnemy();

    std::cout << "\nYou chose: " << player -> getName();
    std::cout << "\nEnemy is: " << enemy -> getName() << "\n";
    std::cout << "Battle Starts! \n";
    UI::pause(1500); //1.5 sec

    const int playerMaxHP = 100;
    const int enemyMaxHP = 100;

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
            enemy -> attack(*player, playerTurn);
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
    delete player;
    delete enemy;
    return 0;
}
