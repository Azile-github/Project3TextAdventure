/**
 * OWNER: Isabelle Hoff + Skyla Gyimesi
 * 
 */ 
#ifndef ARMOR_H
#define ARMOR_H

#include <iostream>
#include <string>
#include "Item.h"

using namespace std;

class Armor : public Item{

    private:
        int defenseBonus;    

    public: 
    
        /**
         * sets the def bonus from the armor
         * @param bonus the positive integer value to add to player's defense
         */ 
        void setDefBonus(int bonus);
        /**
         * @returns the positive integer value 
         */ 
        int getDefBonus() const;

}; 
#endif