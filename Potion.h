//Isabelle Hoff + Skyla Gyimesi
/**
 * OWNER: Isabelle Hoff + Skyla Gyimesi
 * DESCRIPTION: 
 * 
 */ 
#ifndef POTION_H
#define POTION_H

#include <iostream>
#include <string>
#include "Item.h"

using namespace std;

class Potion : public Item{

    private:
        int hpBonus;    // the health bonus from the potion
        int quantityInInventory; // a positive integer; the number of potions in player's inventory

    public: 
        Potion();
    
        /**
         * sets the health bonus from the potion
         * @param bonus the positive integer value above 0 to add to current health
         */ 
        void setHPBonus(int bonus);
        /**
         * @returns the positive integer value above 0 
         */ 
        int getHPBonus() const;
        /**
         * gets quantityInInventory
         */ 
        int getNumPotions() const;
        /**
         * subtracts one from the number of potions in inventory, assuming that the quantity is not equal to 0
         */ 
        void subtractPotion();
        /**
         * adds a potion to the player's inventory, AKA adds one to the quantityInInventory variable
         */ 
        void addPotion();


}; 
#endif