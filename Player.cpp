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
  return items[slot];
}

void Player::printStats(){
  //prints a nice little ascii box with the player's stats inside
  ghfjkul
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
  return defense;
}

int Player::getAttackBonus(){
  return strength + items[0].attack();
}
int Player::getGold(){
  return gold;
}

int Player::getHighestFloor(){
  return highestFloor;
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

void Player::setHighestFloor(int floorIn){
  highestFloor = floorIn;
}

void Player::addOneHighestFloor(){
  highestFloor++;
}