//Isabelle Hoff + Skyla Gyimesi
#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include "Item.h"
#include "Weapon.h"
#include "Armor.h"
#include "Potion.h"

using namespace std;

class Player{
  private:
    string name;
    int maxHP;
    int currentHP;
    int strength;
    int defense;
    int gold;
    Weapon weapon;
    Armor armor;
    Potion potion;
    int highestFloor;
  public:
    Player();
    Player(string nameIn, int maxHpIn, int strengthIn, int defenseIn, int goldIn, int highestFloorIn);

    string getName();
    Item getItem(int slot);
    void printStats();
    int getMaxHealth();
    int getHealth();
    int getStrength();
    int getDefense();
    int getAttackBonus();
    int getGold();
    int getHighestFloor();
    int getDamageMod();

    void setHealth(int hpIn);
    void setMaxHealth(int hpIn);
    void removeHealth(int damage);//input how much health they are losing not how much they will have
    void setStrength(int strIn);
    void setDefense(int defIn);
    void setGold(int goldIn);
    void addGold(int goldIn);
    void addHealth();
    void setHighestFloor(int floorIn);
    void addOneHighestFloor();
    void boughtPotion();
};


#endif