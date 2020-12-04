#include <iostream>
#include <string>
#include "Item.h"
#include "Armor.h"

using namespace std;

/**
 * sets the def bonus from the armor
 * @param bonus the positive integer value to add to player's defense
 */ 
void Armor::setDefBonus(int bonus){
    defenseBonus = bonus;
}
/**
 * @returns the positive integer value of the defense bonus
 */ 
int Armor::getDefBonus() const{
    return defenseBonus;
}