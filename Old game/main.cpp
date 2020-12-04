//Isabelle Hoff + Skyla Gyimesi
#include <iostream>
#include <fstream>
#include <stdlib.h> 
#include <vector>
#include <string>
#include "Game.h"
#include "Player.h"
#include "Monster.h"
#include <stdlib.h>

using namespace std;

void loadSave();
int findHighscore();
void titleInterface();
void newGame();
void endGame();

int main(){
  titleInterface();
}

int findHighscore(){
  string line;
  int highscore;
  vector<string> scores;
  vector<int> intScores;
  ifstream highscoreFile;
  highscoreFile.open("./save/highscore.dat");
  while(getline(highscoreFile, line)){
    scores.push_back(line);
  }
  for(int i = 0; i < scores.size(); i++){
    intScores.push_back(stoi(scores.at(i)));
  }
  highscore = intScores.at(0);
  for(int i = 0; i < intScores.size(); i++){
    if(intScores.at(i) > highscore){
      highscore = intScores.at(i);
    }
  }
  return highscore;
}

void titleInterface(){//going to be the main title with some ascii art and options
//load game
//new game
//exit
  bool exitCondition = false;
  int titleSelect;
  while(exitCondition == false){
    cout << R"(
              _                 _                  
     /\      | |               | |                 
    /  \   __| |_   _____ _ __ | |_ _   _ _ __ ___ 
   / /\ \ / _` \ \ / / _ \ '_ \| __| | | | '__/ _ \
  / ____ \ (_| |\ V /  __/ | | | |_| |_| | | |  __/ 
 /_/    \_\__,_| \_/ \___|_| |_|\__|\__,_|_|  \___|....._      
                                                    `.   ``-.                               .-----.._
                                                      `,     `-.                          .:      /`
                                                        :       `"..                 ..-``       :
                                                        /   ...--:::`n            n.`::...       :
       Type 1 to Start New Game                       `:``      .` ::          /  `.     ``---..:.
       Type 2 to Load Game                             `\    .`   ._:    .-:   ::    `.     .-``
       Type 3 to Quit                                     :  :    :_\\_/: :  .::      `.  /
                                                            : /      \-../:/_.`-`         \ :
                                                             :: _.._  q` p ` /`             \|
                                                             :-`    ``(_. ..-----hh``````/-._:
                                                                         `:      ``     /     `
                                                                         E:            /
                                                                          :          _/
                                                                          :    _..-``
                                                                           l--``)" << endl;
    //cout << "Current highscore is " << findHighscore() << endl;
    cin >> titleSelect;
    switch (titleSelect)
    {
    case 1:
      newGame();
      break;

    case 2:
      loadSave();
      break;

    case 3:
      endGame();
      break;

    default:
      break;
    }
  }

}

void newGame(){
  ofstream writeSave;
  string name;
  string option = "n";
  cout << string(50, '\n');
  while(option!= "Y"){
    cout << "What is your name, adventurer?" << endl;
    cin >> name;
    cout << "Ah, so you are the one they call " << name << " is that right?" << endl;
    cout << "(Y/N)" << endl;
    cin >> option;
  }
  cout << "Wonderful, Wonderful... Welcome to the town of Rathamir, many adventurers like yourself have tried our challenge." << endl;
  cout << "In our town is, the spire. The spire is an infinitely tall tower of challenges for adventurers. We wish you luck on your adventure." << endl;
  writeSave.open("./save/save.dat");
  writeSave << name << endl;
  writeSave << 12 << endl;
  writeSave << 12 << endl;
  writeSave << 10 << endl;
  writeSave << 1 << endl;
  writeSave << 0 << endl;
  writeSave << "storage.dat" << endl;
  writeSave << "itemsBase.dat" << endl;
  loadSave();
}

void loadSave(){//ends in calling Game game(player);
  string line;
  ifstream readFile;
  string name;
  int maxHP;
  int currentHP;
  int strength;
  int defense;
  int gold;
  int highestFloor;
  int numberPotions;
  string storageFileName;
  string savedItemsFileName;
  for(int i = 0; i < 13; i++){
    if(i = 0){
      getline(readFile,line);
      name = line;
    }
    if(i = 1){
      getline(readFile,line);
      cout << "1";
      maxHP = stoi(line);
      currentHP = maxHP;
    }
    if(i = 2){
      getline(readFile,line);
      cout << "2";
      strength = stoi(line);
    }
    if(i = 3){
      getline(readFile,line);
      cout << "3";
      defense = stoi(line);
    }
    if(i = 4){
      getline(readFile,line);
      cout << "4";
      gold = stoi(line);
    }
    if(i = 5){
      getline(readFile,line);
      highestFloor = stoi(line);
    }
    if(i = 6){
      getline(readFile,line);
      storageFileName = line;
    }
    if(i = 7){
      getline(readFile,line);
      savedItemsFileName = line;
    }
  }
  
  Player player(name, maxHP, strength, defense, gold, highestFloor); // Needs items input and stuff // load this one last it boots to game stuff
  Game game(player, savedItemsFileName, storageFileName);
}

void endGame(){
  exit(0);
}