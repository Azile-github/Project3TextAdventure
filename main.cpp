//Isabelle Hoff + Skyla Gyimesi
#include <iostream>
#include <fstream>
#include <stdlib.h> 
#include <vector>

using namespace std;

int loadSave();

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
    }
  }
}
void titleInterface(){//going to be the main title with some ascii art and options
//load game
//new game
//exit

}
int loadSave(){
//loads the game's save then goes to gameplay
}
void generateFloor(){
//loads a floor of the dungeon
}
void combat(){//loops until someone is dead

}

int monsterAttack(){
//details for monster making an attack
}

int attackMenu(){
//player interface for their turn in combat
//1 attack
//2 potion
//ect
}
void saveGame(){
//writes game info to the save.dat file
}
//this function takes the floor and monster's table to generate the gold
int rewardCalc(){
//calculates the gold reward from monsters
}