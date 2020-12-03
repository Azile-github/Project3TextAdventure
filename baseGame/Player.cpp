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

string Player::getName() const{
  return name;
}

Weapon Player::getWeapon() const{
  return weapon;
}
Armor Player::getArmor() const{
  return armor;
}
Potion Player::getPotion() const{
  return potion;
}
void Player::setWeapon(Weapon wIn){
  weapon = wIn;

}
void Player::setArmor(Armor aIn){
  armor = aIn;
}
void Player::setPotion(Potion pIn){
  potion = pIn;
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

int Player::getMaxHealth() const{
  return maxHP;
}

int Player::getHealth() const{
  return currentHP;
}

int Player::getStrength() const{
  return strength;
}

int Player::getDefense() const{
  return defense + armor.getDefBonus();
}

int Player::getAttackBonus() const{
  return strength + weapon.getWeaponAttackBonus();
}

int Player::getGold() const{
  return gold;
}

int Player::getHighestFloor() const{
  return highestFloor;
}

int Player::getDamageMod() const{
  return strength + weapon.getWeaponDamageBonus();
}

int Player::getNumPotions() const{
  return numPotions;
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

void Player::usePotion(){
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

void Player::boughtPotion(){
  potion.addPotion();
}
void Player::setName(string nameIn){
  name = nameIn;

}
void Player::setEqualTo(Player pIn){
  name = pIn.getName();
  maxHP = pIn.getMaxHealth();
  currentHP = pIn.getHealth();
  strength = pIn.getStrength();
  defense = pIn.getDefense();
  gold = pIn.getGold();
  
  highestFloor = pIn.getHighestFloor();
}