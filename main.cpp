#include "Warrior.h"
#include "Mage.h"
#include <iostream>
#include <ctime>
#include <cstdlib>

// Util function to display current health
void displayStatus(const Character &c) {
    std::cout << c.getName() << " has " << c.getHealth() << " HP remaining. \n";
}

int main() {
    // Seed random number generator
    std::srand(static_cast<unsigned>(std::time(nullptr)));
    
    // Create player controlled Character
    Warrior player("Hero");

    // Create enemy Character
    Mage enemy("Goblin Mage");

    std::cout << "Battle Starts! \n";

    // Simple turn based battle loop
    bool playerTurn = true;
    while (player.isAlive() && enemy.isAlive()) {
        if (playerTurn) {
            std::cout << "\nYour Turn:\n";
                player.attack(enemy);
        } else {
            std::cout << "\nEnemy turn:\n";
                enemy.attack(player);
        }

        // Display health of both Characters after turn
        displayStatus(player);
        displayStatus(enemy);
        

        // Announce winner
        if (enemy.getHealth() <= 0) {
            std::cout << "\n" << player.getName() << "wins!\n";
            break;
        } else if (player.getHealth() <= 0){
            std::cout << "\n" << enemy.getName() << " wins!\n";
            break;
        }

        playerTurn = !playerTurn;
        std::cout << "Press enter to continue...\n";
        std::cin.ignore();
    }


    return 0;
}
