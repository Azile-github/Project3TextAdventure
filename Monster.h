#ifndef MONSTER_H
#define MONSTER_H

#include <string>
#include <fstream>
#include <iostream>

using namespace std;

class Monster{
  private:
    string nameMonster;
    int table;
    int hitPoints;
    int damageBase;
    int strength;
    int defence;
    int rewardBase;
    int noMonsters;
  public:
    void SetNoMonsters();
    int initializeMonster(int id);
    void setName(string nameIn);
    void setTable(int TableIn);
    void setHP(int hitPointsIn);
    void setDamageBase(int damageBaseIn);
    void setStrength(int strengthIn);
    void setDefence(int defenceIn);
    void setRewardBaseIn(int rewardBaseIn);
    string returnNameMonster();
    int returnTable();
    int returnHitPoints();
    int returnDamageBase();
    int returnStrength();
    int returnDefence();
    int returnRewardBase();
};
#endif