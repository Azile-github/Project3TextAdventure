#ifndef WEAPON_H
#define WEAPON_H

#include <iostream>
#include <string>
#include "Item.h"

using namespace std;

class Weapon : public Item{

    private: 
        
        int attackBonus;        // a positive int attack ability of the item 
                                // (if it is attacked with. otherwise, -1)
        int damageBonus;        // damage it can cause
        
    public: 

        /**
         * sets the attackBonus value of the weapon
         * @param attBonus the given attack (a positive integer equal or above 0)
         */ 
        void setWeaponAttackBonus(int attBonus);
        /**
         * @returns the weapon attack bonus value
         */ 
        int getWeaponAttackBonus() const;

        /**
         * sets the weapon damage
         * @param dmgBonus the given damage value
         */ 
        void setWeaponDamageBonus(int dmgBonus);
        /**
         * @returns the damage value
         */ 
        int getWeaponDamageBonus() const;

};
#endif