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
    int numPotions;
    int highestFloor;
  public:
    Player();
    Player(string nameIn, int maxHpIn, int strengthIn, int defenseIn, int goldIn, int highestFloorIn);

    string getName() const;
    Weapon getWeapon() const;
    Armor getArmor() const;
    Potion getPotion() const;
    void printStats();
    int getMaxHealth() const;
    int getHealth() const;
    int getStrength() const;
    int getDefense() const;
    int getAttackBonus() const;
    int getGold() const;
    int getHighestFloor() const;
    int getDamageMod() const;
    int getNumPotions() const;

    void setWeapon(Weapon wIn);
    void setArmor(Armor aIn);
    void setPotion(Potion pIn);
    void setHealth(int hpIn);
    void setName(string nameIn);
    void setMaxHealth(int hpIn);
    void removeHealth(int damage);//input how much health they are losing not how much they will have
    void setStrength(int strIn);
    void setDefense(int defIn);
    void setGold(int goldIn);
    void addGold(int goldIn);
    void usePotion();
    void setHighestFloor(int floorIn);
    void addOneHighestFloor();
    void boughtPotion();
    void setEqualTo(Player pIn);
};


#endif