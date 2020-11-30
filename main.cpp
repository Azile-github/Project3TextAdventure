//Isabelle Hoff + Skyla Gyimesi
#include <iostream>
#include <fstream>
#include <stdlib.h> 
#include <vector>
#include <string>

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

int findHighscore(){
//this should be a sorting algorithm that runs at the start to pass the highscore from highscore.dat to the titlescreen.
}

void titleInterface(int highScore){//going to be the main title with some ascii art and options
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
    cout << "Current highscore is" << endl;
    cin >> titleSelect;
    switch (titleSelect)
    {
    case 1:
      /* code */
      break;

    case 2:
      /* code */
      break;

    case 3:
      /* code */
      break;

    default:
      break;
    }
  }

}

void newGame(){
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


}

void writeFile(string fileName, string content, int line){// file name must include location if not at root
  vector<string> contents;
  ifstream currentFile;
  string lineConent;
  currentFile.open(fileName);
  while(getline(currentFile, lineConent)){
    contents.push_back(lineConent);
  }
}

int readTable(int tableNo, int lineNo){
  string tableNoStr = to_string(tableNo);
  string fileHead = "./res/monsters/monsterTable";
  ifstream currentTable;
  string line;
  fileHead.append(tableNoStr);
  fileHead.append(".dat");
  currentTable.open(fileHead);
  for(int i = 0; i < lineNo; i++){
    getline(currentTable, line);
  }
  return stoi(line);
}

int chooseMonster(int floor){//returns a monster id to load
  int randNum;
  int tableNo;
  int lineNo;
  if(floor > 15){
    randNum = (rand() % 10) + 1; //1 to 10
    if(randNum > 5){//table 3
      tableNo = 3;
      lineNo = (rand() % 10) + 1;
      return readTable(tableNo, lineNo);
    }
    if(randNum > 2){
      tableNo = 2;
      lineNo = (rand() % 10) + 1;
      return readTable(tableNo, lineNo);
    }
    if(randNum > 0){
      tableNo = 1;
      lineNo = (rand() % 10) + 1;
      return readTable(tableNo, lineNo);
    }
  }else if(floor > 8){
    randNum = (rand() % 10) + 1; //1 to 10
    if(randNum > 8){//table 3
      tableNo = 3;
      lineNo = (rand() % 10) + 1;
      return readTable(tableNo, lineNo);
    }
    if(randNum > 4){
      tableNo = 2;
      lineNo = (rand() % 10) + 1;
      return readTable(tableNo, lineNo);
    }
    if(randNum > 0){
      tableNo = 1;
      lineNo = (rand() % 10) + 1;
      return readTable(tableNo, lineNo);
    }
  }else if(floor > 0){
    randNum = (rand() % 10) + 1; //1 to 10
    if(randNum > 9){//table 3
      tableNo = 3;
      lineNo = (rand() % 10) + 1;
      return readTable(tableNo, lineNo);
    }
    if(randNum > 7){
      tableNo = 2;
      lineNo = (rand() % 10) + 1;
      return readTable(tableNo, lineNo);
    }
    if(randNum > 0){
      tableNo = 1;
      lineNo = (rand() % 10) + 1;
      return readTable(tableNo, lineNo);
    }
  }
}

int loadSave(){
//loads the game's save then goes to gameplay
}
void theGround(){
  int menuChoice;
  bool menuExit = false;
  cout << string(50, '\n');
  cout << "You stand at the base of the tower, what would you like to do?" << endl;
  while(menuExit = false){
    cout << "Input 1, to go into the tower, input 2 to talk with the shopkeep." << endl;
    cin >> menuChoice;
    switch (menuChoice)
    {
    case 1:
      /* code */
      break;
    case 2:
      /* code */
      break;
    default:
      cout << "Invalid input" << endl;
      break;
    }
  }
  
}
void generateFloor(){

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