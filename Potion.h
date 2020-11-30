//Isabelle Hoff + Skyla Gyimesi
/**
 * OWNER: Isabelle Hoff + Skyla Gyimesi
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
        int hpBonus;    

    public: 
    
        /**
         * sets the health bonus from the potion
         * @param bonus the positive integer value above 0 to add to current health
         */ 
        void setHPBonus(int bonus);
        /**
         * @returns the positive integer value above 0 
         */ 
        int getHPBonus() const;

}; 
#endif