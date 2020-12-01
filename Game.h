//Isabelle Hoff + Skyla Gyimesi
#ifndef GAME_H
#define GAME_H

#include <fstream>
#include <iostream>
#include <string>

using namespace std;

class Game{
  private:
    int currentfloor;
    int monT1;
    int monT2;
    int monT3;
  public:
    Game();
    Game(int t);
    void loadFloor(int floor);
    int gameOver();
    int attackMenu();
    int highScoreSort();
    void exitGame();
    void saveGame();
};
#endif