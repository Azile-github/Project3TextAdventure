//Isabelle Hoff + Skyla Gyimesi
#include <iostream>
#include <fstream>
#include <stdlib.h> 
#include <vector>
#include <string>
#include <Game.h>
#include <Player.h>
#include <Monster.h>
#include <stdlib.h>

using namespace std;

void loadSave();
void endGame();
int highscoreCalculation();
int findHighscore();
void titleInterface();
void newGame();
int readTable(int tableNo, int lineNo);
int chooseMonster(int floor);
void theGround(Player player);
void generateFloor(int currentFloor, Player player);
void saveGame();
int rewardCalc();
void endGame();
int highscoreCalculation(Player player);
void saveScare(int score);

int main(){
  bool loadState = false;
  ifstream highscore;
  ifstream save;
  ifstream items;
  ifstream shopStatus;
  highscore.open("highscore.dat");
  save.open("save.dat");
  items.open("items.dat");
  shopStatus.open("shop.dat");
  while (loadState == false){
    highscore.open("highscore.dat");
    save.open("save.dat");
    items.open("items.dat");
    shopStatus.open("shop.dat");
    cout << "Checking files..." << endl;
    if(!highscore.is_open() || !save.is_open() || !items.is_open() || !shopStatus.is_open()){
      cout << "One or more file has failed to open..." << endl;
      if(!highscore.is_open()){
        cout << "Generating high score file..." << endl;
        ofstream createHighscore;
        createHighscore.open("highscore.dat");
        createHighscore.close();
      }
      if(!save.is_open()){
        cout << "Generating save file..." << endl;
        ofstream createSave;
        createSave.open("save.dat");
        createSave.close();
      }
      if(!items.is_open()){
        cout << "ERROR: Items file failure! Please redownload the game!" << endl;
        return -1;
      }
      if(!shopStatus.is_open()){
        cout << "Error: Shop file failure! Please redownload the game!" << endl;
        return -1;
      }
    }else{
      loadState = true;
    }
  }
  titleInterface();
}

int findHighscore(){
//this should be a sorting algorithm that runs at the start to pass the highscore from highscore.dat to the titlescreen.
x
//sorting algorithm goes here
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
    cout << "Current highscore is" << findHighscore() << endl;
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
  while(option != "y", option != "Y"){
    cout << "What is your name, adventurer?" << endl;
    cin >> name;
    cout << "Ah, so you are the one they call " << name << "is that right?" << endl;
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
  writeSave << 0 << endl;
  writeSave << -1 << endl;
  writeSave << "storage.dat" << endl;
  writeSave << "itemsBase.dat" << endl;
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
  int weaponIndex;
  int armorIndex;
  int potionIndex;
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
      maxHP = stoi(line);
      currentHP = maxHP;
    }
    if(i = 2){
      getline(readFile,line);
      strength = stoi(line);
    }
    if(i = 3){
      getline(readFile,line);
      defense = stoi(line);
    }
    if(i = 4){
      getline(readFile,line);
      gold = stoi(line);
    }
    if(i = 5){
      getline(readFile,line);
      highestFloor = stoi(line);
    }
    if(i = 6){
      getline(readFile,line);
      weaponIndex = stoi(line);
    }
    if(i = 7){
      getline(readFile,line);
      armorIndex = stoi(line);
    }
    if(i = 8){
      getline(readFile,line);
      potionIndex = stoi(line);
    }
    if(i = 9){
      getline(readFile,line);
      numberPotions = stoi(line);
    }
    if(i = 10){
      getline(readFile,line);
      storageFileName = line;
    }
    if(i = 11){
      getline(readFile,line);
      savedItemsFileName = line;
    }
  }
  Player player(name, maxHP, strength, defense, gold, highestFloor); // Needs items input and stuff // load this one last it boots to game stuff
  x
  needs to read from file
}