//Isabelle Hoff + Skyla Gyimesi
#include "Game.h"
#include <fstream>

Game::Game(){
  ifstream settings;
  string line;
  settings.open(./save/settings.txt);
  getline(settings, line);
  getline(settings, line);
  monT1 = stoi(line.substr(26,2));
  getline(settings, line);
  monT2 = stoi(line.substr(26,2));
  getline(settings, line);
  monT3 = stoi(line.substr(26,2));
  cout << "t1 is " << monT1 << " t2 is " << monT2 << " t3 is " << monT3;
}
void Game::loadFloor(int floor){
  //loads the contents of the floor ie monster encounter
  if(floor > 10){

  }
}

Game::Game(int t){
  cout << "why";
}

int Game::gameOver(){
  //ends the game to title returns -1
}

int Game::attackMenu(){
  //user attack interface returns attack attempt value
}

int Game::highScoreSort(){
  //for the title
  //sorts the highscores gotten to reread to player
}