#ifndef GAME_H
#define GAME_H

class Game{
  private:
    int currentfloor;
  public:
    void loadFloor();
    int gameOver();
    int attackMenu();
    int highScoreSort();
};
#endif