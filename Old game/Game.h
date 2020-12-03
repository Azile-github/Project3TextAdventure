//Isabelle Hoff + Skyla Gyimesi
#ifndef GAME_H
#define GAME_H

#include <fstream>
#include <iostream>
#include <string>
#include "Player.h"
#include <vector>
#include "Shopkeep.h"

using namespace std;

class Game{
  private:
    Player player;
    int currentfloor;
    int monT1;
    int monT2;
    int monT3;
    Shopkeep shopkeep;
  public:
    Game();
    Game(Player playerIn, string savedItemsFileName, string saveStorageFileName, bool game);
    void gameOver();
    int chooseMonster();
    int readTable(int tableNo, int lineNo);
    void exitGame();
    void saveGame();
    void combat(int monsterId);
    void postCombat();
    void death();
    void theGround();
    void generateFloor();
    int highscoreCalculation();
    void saveScore(int score);
    void recordMonster(int mId);
};
#endif