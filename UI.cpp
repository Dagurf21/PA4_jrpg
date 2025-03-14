#include "UI.h"
#include <ios>
#include <iostream>
#include <chrono>
#include <limits>
#include <thread>
#include <cstdlib>

namespace UI {
  
    void clearScreen() {
      #ifdef _WIN32
          system("cls");
      #else 
        system("clear");
      #endif
    }

    void printHealthBar(const std::string &name, int currentHP, int maxHP) {
        const int barwidth = 20;
        int filled = (currentHP * barwidth) / maxHP;
        std::cout << name << " HP: [";
        for (int i = 0; i < filled; i++)
          std::cout << "#";
        for (int i = filled; i < barwidth; i++)
          std::cout << "-";
        std::cout << "] " << currentHP << "/" << maxHP << "\n";
    }

    int displayBattleMenu() {
        int choice = 0;
        std::cout << "\nChoose your action:\n";
        std::cout << "1. Attack\n";
        std::cout << "2. Defend\n";
        std::cout << "Enter Choice\n";
        
        while (true) {
            if (!(std::cin >> choice)) {
                std::cout << "Please enter a valid number. \n";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                continue;
            }

            if (choice == 1 || choice == 2) {
                break;
            } else {
                std::cout << "Invalid selection. Please enter 1 or 2.\n";
            }
        }
        return choice;
    }

    int chooseAttackMenu(const std::string attackOptions[3]) {
        int choice = 0;
        std::cout << "\nChoose your attack:\n";

        for (int i = 0; i < 3; i++) {
            std::cout << (i + 1) << ". " << attackOptions[i] << "\n";
        }
        std::cout << "Enter choice: ";
        
        while (true){
            if (!(std::cin >> choice)) {
                std::cout << "Please enter a valid number. \n";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                continue;
            }

            if (choice == 1 || choice == 2 || choice == 3) {
                break;
            } else {
                std::cout << "Invalid selection. Please enter 1, 2, or 3.\n";
            }
        } 
        return choice;
    }

    void pause(int milliseconds) {
        std::this_thread::sleep_for(std::chrono::milliseconds(milliseconds));
    }
   
    void drawBattleScene(const std::string &playerName, int playerHP, int playerMaxHP,
                            const std::string &enemyName, int enemyHP, int enemyMaxHP) {
        clearScreen();
        std::cout << "==================================================\n";
        std::cout << "                   BATTLE SCENE                    \n";
        std::cout << "==================================================\n\n";
        printHealthBar(playerName, playerHP, playerMaxHP);
        printHealthBar(enemyName, enemyHP, enemyMaxHP);
        std::cout << "\n";
    }

    void waitForKeyPress() {
        std::cout << "Press Enter to continue...";
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

}  // namespace UI

