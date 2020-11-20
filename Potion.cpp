// FILE FOR ITEMS CLASS

#include <iostream>
#include <string>
#include "Potion.h"

using namespace std;


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