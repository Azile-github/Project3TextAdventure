//Isabelle Hoff + Skyla Gyimesi
#ifndef GAME_H
#define GAME_H

#include <fstream>
#include <iostream>
#include <string>

using namespace std;

class Game{
  private:
    Player player;
    int currentfloor;
    int monT1;
    int monT2;
    int monT3;
  public:
    Game();
    Game(Player playerIn);
    void loadFloor(int floor);
    int gameOver();
    int attackMenu();
    int highScoreSort();
    int chooseMonster();
    int readTable(int tableNo, int lineNo);
    void exitGame();
    void saveGame();
    void introduction();
    void combat(int monsterId);
    void postCombat();
    void death();
    void theGround();
    void generateFloor();
};
#endif