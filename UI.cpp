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
        std::cout << "3. Use Item\n";
        std::cout << "4. Flee\n";
        std::cout << "Enter Choice\n";
        std::cin >> choice;
        return choice;
    }

    int chooseAttackMenu(const std::string attackOptions[3]) {
        std::cout << "\nChoose your attack:\n";
        for (int i = 0; i < 3; i++) {
            std::cout << (i + 1) << ". " << attackOptions[i] << "\n";
        }
        std::cout << "Enter choice: ";
        int choice;
        std::cin >> choice;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
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

