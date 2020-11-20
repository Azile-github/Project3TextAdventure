//Isabelle Hoff + Skyla Gyimesi
#ifndef GAME_H
#define GAME_H

class Game{
  private:
    int currentfloor;
  public:
    void loadSettings();
    void loadFloor(int floor);
    int gameOver();
    int attackMenu();
    int highScoreSort();
};
#endif