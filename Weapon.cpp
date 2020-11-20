// FILE FOR ITEMS CLASS

#include <iostream>
#include <string>
#include "Weapon.h"

using namespace std;

// Methods

/**
 * sets the attackBonus value of the weapon
 * @param attBonus the given attack (a positive integer equal or above 0)
 */
void Weapon::setWeaponAttackBonus(int attBonus){
    attackBonus = attBonus;
}
/**
 * @returns the weapon attack bonus value
 */
int Weapon::getWeaponAttackBonus() const{
    return attackBonus;
}

/**
 * sets the weapon damage
 * @param dmgBonus the given damage value
 */
void Weapon::setWeaponDamageBonus(int dmgBonus){
    damageBonus = dmgBonus;
}
/**
 * @returns the damage value
 */
int Weapon::getWeaponDamageBonus() const{
    return damageBonus;
}
