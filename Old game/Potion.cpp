//Isabelle Hoff + Skyla Gyimesi
// FILE FOR ITEMS CLASS

#include <iostream>
#include <string>
#include "Potion.h"

using namespace std;


//Constructors
Potion::Potion(){
    Item();
    quantityInInventory = 0;
}

// Methods

/**
 * sets the health bonus from the potion
 * @param bonus the positive integer value above 0 to add to current health
 */
void Potion::setHPBonus(int bonus){
    hpBonus = bonus;
}
/**
 * @returns the positive integer value above 0 
 */
int Potion::getHPBonus() const{
    return hpBonus;
}
/**
 * gets quantityInInventory 
 * @returns the number of potions in player's inventory
 */ 
int Potion::getNumPotions() const{
    return quantityInInventory;
}
/**
 * subtracts one from the number of potions in inventory, assuming that the quantity is not equal to 0
 */ 
void Potion::subtractPotion(){
    if(quantityInInventory > 0)
        quantityInInventory--;
    if(quantityInInventory == 0)
        setPlayerHas(false);
}
/**
 * adds a potion to the player's inventory, AKA adds one to the quantityInInventory variable 
 */ 
void Potion::addPotion(){
    if(!doesPlayerHave())
        setPlayerHas(true);
    quantityInInventory++;
}