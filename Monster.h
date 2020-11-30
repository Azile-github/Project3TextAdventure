//Isabelle Hoff + Skyla Gyimesi
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

    // SETTERS 

    /**
     * @param nameIn the input name of the monster
     */ 
    void setName(string nameIn);
    /**
     * @param TableIn the input ranking of the table
     */ 
    void setTable(int TableIn);
    /**
     * @param hitPointsIn the input health of the monster
     */ 
    void setHP(int hitPointsIn);
    /**
     * @param damageBaseIn the input damage base
     */ 
    void setDamageBase(int damageBaseIn);
    /**
     * @param strengthIn the input strength
     */ 
    void setStrength(int strengthIn);
    /**
     * @param defenseIn the input defense
     */ 
    void setDefense(int defenseIn);
    /**
     * @param rewardBaseIn the input reward of the monster upon defeat
     */ 
    void setRewardBase(int rewardBaseIn);

    // GETTERS

    /**
     * @returns the monster's name 
     */ 
    string returnNameMonster() const;
    /**
     * @returns the table ranking of the monster
     */ 
    int returnTable() const;
    /**
     * @returns the hitpoints of the monster
     */ 
    int returnHitPoints() const;
    /**
     * @returns the base damage the monster can inflict
     */ 
    int returnDamageBase() const;
    /**
     * @returns the strength of the monster
     */ 
    int returnStrength() const;
    /**
     * @returns the defense rating of the monster
     */ 
    int returnDefense() const;
    /**
     * @returns the base reward of the monster
     */ 
    int returnRewardBase() const;
    /**
     * @returns the attack bonus of the monster
     */ 
    int getAttackBonus() const;

    // OTHERS
    /**
     * subtracts the damage taken by the monster and returns the remaining health
     * @param damage the damage inflicted on the monster
     * @returns the remaining health
     */ 
    int takeDamage(int damage); //returns remaining health
    /**
     * @param id the id number of the monster to find the
     * @returns the appearance of the monster
     */ 
    string drawAppearance(int id);
};
#endif