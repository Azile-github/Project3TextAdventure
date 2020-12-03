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
 
    getline(currentMonsterFile, line);
    
      mName = line;
    
    getline(currentMonsterFile, line);
   
      table = stoi(line);
    
    getline(currentMonsterFile, line);

      hp = stoi(line);
    
    getline(currentMonsterFile, line);
   
      dmg = stoi(line);

      getline(currentMonsterFile, line);
    
   
      str = stoi(line);

      getline(currentMonsterFile, line);
 

      def = stoi(line);

      getline(currentMonsterFile, line);

      cout << "rewardBase is " << line << endl;
      rewardBaseIn = stoi(line);

  
  currentMonsterFile.close();
  setName(mName);
  setTable(tableIn);
  setHP(hp);
  setDamageBase(dmg);
  setStrength(str);
  setDefense(def);
  setRewardBase(rewardBaseIn);
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

string Monster::returnNameMonster() const{
  return nameMonster;
}

int Monster::returnTable() const{
  return table;
}

int Monster::returnHitPoints() const{
  return hitPoints;
}

int Monster::returnDamageBase() const{
  return damageBase;
}

int Monster::returnStrength() const{
  return strength;
}

int Monster::returnDefense() const{
  return defense;
}

int Monster::returnRewardBase() const{
  return rewardBase;
}

int Monster::takeDamage(int damage) {
  hitPoints = hitPoints - damage;
  return hitPoints;
}

int Monster::getAttackBonus() const{
//takes the strength to return attack bonus
}