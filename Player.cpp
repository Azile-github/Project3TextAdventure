//Isabelle Hoff + Skyla Gyimesi
#include "Player.h"

Player::Player(){

}
Player::Player(string nameIn, int maxHPIn, int strengthIn, int defenseIn, int goldIn, int highestFloorIn){
  name = nameIn;
  maxHP = maxHPIn;
  currentHP = maxHPIn;
  strength = strengthIn;
  defense = defenseIn;
  gold = goldIn;
  highestFloor = highestFloorIn;
}

string Player::getName(){
  return name;
}

Item Player::getItem(int slot){
  if(slot = 0){
    return weapon;
  }
  if(slot = 1){
    return armor;
  }
  if(slot = 2){
    return potion;
  }
}

void Player::printStats(){
  cout << "===========================================" << endl;
  cout << name << endl;
  cout << "HP: " << currentHP << "/" << maxHP << endl;
  cout << "Strength is " << strength << endl;
  cout << "Attack bonus is " << getAttackBonus() << endl;
  cout << "Damage bonus is " << getDamageMod() << endl;
  cout << "Defence is " << defense << endl;
  cout << "Current weapon is " << weapon.getItemName() << endl;
  cout << "Current armor is " << armor.getItemName() << endl;
  cout << "Potions: " << potion.getNumPotions() << endl;
  cout << "===========================================" << endl;
}

int Player::getMaxHealth(){
  return maxHP;
}

int Player::getHealth(){
  return currentHP;
}

int Player::getStrength(){
  return strength;
}

int Player::getDefense(){
  return defense + armor.getDefBonus();
}

int Player::getAttackBonus(){
  return strength + weapon.getWeaponAttackBonus();
}

int Player::getGold(){
  return gold;
}

int Player::getHighestFloor(){
  return highestFloor;
}

int Player::getDamageMod(){
  return strength + weapon.getWeaponDamageBonus();
}

void Player::setHealth(int hpIn){
  currentHP = hpIn;
}

void Player::setMaxHealth(int hpIn){
  maxHP = hpIn;
}

void Player::removeHealth(int damage){
  currentHP = currentHP - damage;
}

void Player::setStrength(int strIn){
  strength = strIn;
}

void Player::setDefense(int defIn){
  defense = defIn;
}

void Player::setGold(int goldIn){
  gold = goldIn;
}

void Player::addGold(int goldIn){
  gold = gold + goldIn;
}

void Player::addHealth(){
  currentHP = potion.getHPBonus() + currentHP;
  if(currentHP > maxHP){
    currentHP = maxHP;
  }
  potion.subtractPotion();
}

void Player::setHighestFloor(int floorIn){
  highestFloor = floorIn;
}

void Player::addOneHighestFloor(){
  highestFloor++;
}