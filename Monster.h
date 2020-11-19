#ifndef MONSTER_H
#define MONSTER_H

#include <string>
#include <fstream>
#include <iostream>

using namespace std;

class Monster{
  private:
    string nameMonster;
    int table;//I want to store this so we can calculate reward from it and the reward base, same with damage. Higher tables are more variable results
    int hitPoints;
    int damageBase;
    int strength;
    int defense;
    int rewardBase;
    int noMonsters;
  public://oh god there are so many
    Monster();
    //void SetNoMonsters();
    Monster(int id);// ALWAYS RUN FIRST when introducing a monster to an encounter
    void setName(string nameIn);
    void setTable(int TableIn);
    void setHP(int hitPointsIn);
    void setDamageBase(int damageBaseIn);
    void setStrength(int strengthIn);
    void setDefense(int defenseIn);
    void setRewardBase(int rewardBaseIn);
    string returnNameMonster();
    int returnTable();
    int returnHitPoints();
    int returnDamageBase();
    int returnStrength();
    int returnDefense();
    int returnRewardBase();
    int takeDamage(int damage); //returns remaining health
    int getAttackBonus();
    string drawAppearance(int id);
};
#endif