//Isabelle Hoff + Skyla Gyimesi
#include "Monster.h"

Monster::Monster(){
  cout << "YOU MORON, YOU ABSOLUTE BAFOON, FEED ME AN ID" << endl;
  Monster();
}

Monster::Monster(int idIn){
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

void Monster::setName(string nameIn){
  nameMonster = nameIn;
}

void Monster::setTable(int tableIn){
  table = tableIn;
}

void Monster::setHP(int hp){
  hitPoints = hp;
}

void Monster::setDamageBase(int damageBaseIn){
  damageBase = damageBaseIn;
}

void Monster::setStrength(int strIn){
  strength = strIn;
}

void Monster::setDefense(int defIn){
  defense = defIn;
}

void Monster::setRewardBase(int rewardBaseIn){
  rewardBase = rewardBaseIn;
}

string Monster::returnNameMonster(){
  return nameMonster;
}

int Monster::returnTable(){
  return table;
}

int Monster::returnHitPoints(){
  return hitPoints;
}

int Monster::returnDamageBase(){
  return damageBase;
}

int Monster::returnStrength(){
  return strength;
}

int Monster::returnDefense(){
  return defense;
}

int Monster::returnRewardBase(){
  return rewardBase;
}

int Monster::takeDamage(int damage){
  hitPoints = hitPoints - damage;
  return hitPoints;
}

int Monster::getAttackBonus(){
//takes the strength to return attack bonus
}

string Monster::drawAppearance(int id){
  //This will grab the appearance of the monster from /res/art/ and print return it.
}