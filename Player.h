//Isabelle Hoff + Skyla Gyimesi
#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include "Item.h"

using namespace std;

class Player{
  private:
  string name;
    int maxHP;
    int currentHP;
    int strength;
    int defense;
    int gold;
    int quantity[4];
    Item items[4];
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

    void setHealth(int hpIn);
    void removeHealth(int damage);//input how much health they are losing not how much they will have
    void setStrength(int strIn);
    void setDefense(int defIn);
    void setGold(int goldIn);
    void addGold(int goldIn);
    void setHighestFloor(int floorIn);
    void addOneHighestFloor();
};


#endif