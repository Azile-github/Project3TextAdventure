// FILE FOR ITEMS CLASS

#include <iostream>
#include <string>
#include "Item.h"

using namespace std;

// Constructors
Item::Item(){
    // emptyyyy does nothing
}

// Methods

/**
 * sets the name of the weapon
 * @param nameIn the given name to set it as
 */
void Item::setItemName(string nameIn){
    itemName = nameIn;
}
/**
 * @returns the name of the 
 */
string Item::getItemName() const{
    return itemName;
}

/**
 * sets the description of the item
 * @param desc the description of the item (what the shopkeep says about it)
 */
void Item::setDescription(string desc){
    description = desc;
}
/**
 * @returns the description of the item
 */
string Item::getDescription() const{
    return description;
}

/**
 * sets the IDNum of the item
 * @param id the ID of the item 
 */
void Item::setID(string id){
    ID = id;
}
/**
 * @returns the description of the item
 */
string Item::getID() const{
    return ID;
}

/**
 * sets the cost of the item to value
 * @param value the input cost of the item
 */
void Item::setCost(int value){
    cost = value;
}
/**
 * @returns the cast of the item
 */
int Item::getCost() const{
    return cost;
}

/**
 * sets the status of the item
 * @param inInventory if true, then the player has this in their inventory. False if not
 */
void Item::setPlayerHas(bool inInventory){
    playerHas = inInventory;
}
/**
 * @returns if the player has this item in their inventory. True if yes, false if not
 */
bool Item::doesPlayerHave() const{
    return playerHas;
}