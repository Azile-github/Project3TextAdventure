#include "Monster.h"

int Monster::initializeMonster(int idIn){
  ifstream currentMonsterFile;
  string line;
  int pos;
  int str, def, rewardBaseIn, tableIn, hp, dmg;
  string mName;
  int currentLine = 0;
  string stringId = to_string(idIn);
  stringId.append(".dat");//turning the id into the file name to read
  stringId.insert(0, "./res/monsters/");
  currentMonsterFile.open(stringId);
  if(!currentMonsterFile.is_open()){
    cout << "Critical Error: Failed to load Monster!";
    return -1;
  }
  //while(getline(currentMonsterFile, line)){
  for(int i = 0; i < 6; i++){
    getline(currentMonsterFile, line);
    if(i == 0){
      mName = line;
    }
    if(i == 1){
      table = stoi(line);
    }
    if(i == 2){
      hp = stoi(line);
    }
    if(i == 3){
      dmg = stoi(line);
    }
    if(i == 4){
      str = stoi(line);
    }
    if(i == 5){
      def = stoi(line);
    }
    if(i == 6){
      rewardBaseIn = stoi(line);
    }
  }
  //Functions that set the rest of the stats gotten from this
}