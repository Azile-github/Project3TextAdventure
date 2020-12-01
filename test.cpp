#include <iostream>
#include <string>
#include <vector>
#include "Item.h"
#include "Potion.h"
#include "Weapon.h"
#include "Game.h"

using namespace std;

// int main(){
//     Game game;
// }

// int main(){
//   int tableNo = 1;
//   int lineNo = 1;
//   string line;
//   string tableNoStr = to_string(tableNo);
//   string fileHead = "./res/monsters/monsterTable";
//   ifstream currentTable;
//   fileHead.append(tableNoStr);
//   fileHead.append(".dat");
//   cout << fileHead;
//   currentTable.open(fileHead);
//   for(int i = 0; i < lineNo; i++){
//     getline(currentTable, line);
//   }
//   cout << line;
//   return stoi(line);
// }

// int main(){
//     // testing Items
//     Item a1;
//     a1.setItemName("item");
//     a1.setDescription("jfhds");
//     Weapon a2;
//     a2.setItemName("sword");
//     Potion a3;
//     a3.setItemName("health potion");
//     cout << a1.getItemName() << " " << a2.getItemName() << " " << a3.getItemName() << "\n";
// }
void saveScore(int score){
  string scoreStr = to_string(score);
  string line;
  vector<string> scores;
  ifstream currentFile;
  ofstream currentFileW;
  currentFile.open("./save/highscore.dat"); 
  while(getline(currentFile, line)){
    scores.push_back(line);
  }
  currentFile.close();
  scores.push_back(scoreStr);
  currentFileW.open("./save/highscore.dat");
  for (int i = 0; i < scores.size(); i++){
    currentFileW << scores.at(i) << endl;
  }
  
}

int main(){
    saveScore(7);
}

// 20
// 18
// 16
// 13
// 20
// 38