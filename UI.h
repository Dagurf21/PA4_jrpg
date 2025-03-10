#ifndef UI_H
#define UI_H

#include <string>

namespace UI {
    // Clear console screen
    void clearScreen();

    // Display healthbar
    void printHealthBar(const std::string &name, int currentHP, int maxHP);

    // Display the battle menu and return players choice
    int displayBattleMenu();

    // Pauses for given num of milliseconds
    void pause(int milliseconds);

    void drawBattleScene(const std::string &playerName, int playerHP, int playerMaxHP,
                            const std::string &enemyName, int enemyHP, int enemyMaxHP);

    void waitForKeyPress();
}

#endif // UI_H
