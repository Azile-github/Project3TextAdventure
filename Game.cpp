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
void titleInterface(){

}
int loadSave(){

}
void generateFloor(){

}
void combat(){//loops until someone is dead

}

int monsterAttack(){

}

int attackMenu(){

}
void saveGame(){

}
void highscoreFileSort(){

}
//this function takes the floor and monster's table to generate the gold
int rewardCalc(){

}
//this function gets damages number and the user's strength to calc how much damage. call this from monsterAttack of menu when the player does an attack
int damageCalc(int damageBase, int strength){

}