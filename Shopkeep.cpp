//Isabelle Hoff + Skyla Gyimesi
// FILE FOR ITEMS CLASS

#include <iostream>
#include <fstream>
#include <string>
#include "Shopkeep.h"
#include "Item.h"
#include "Weapon.h"
#include "Armor.h"
#include "Potion.h"

using namespace std;

// Constructors


// Methods
/**
 * loads the shopkeep quotes from the txt file into the quotes vector
 */ 
void Shopkeep::loadQuotes(){

}
/**
 * loads the items (potions, weapons, and armors) from a given txt file into their respective vectors
 * The file will be separated by three categories: Weapons, Armor, and Potions. 
 * 
 * Each category is separated in the file via the character '$'
 * Then each item is separated by '#' at the end of it's stats
 * 
 * Stats go in this order:
 * For Weapons list:
 *      NAME
 *      DESCRIPTION
 *      cost
 *      playerHas (this will be false by default)
 *      attackBonus
 *      damageBonus
 * For Armor list:
 *      name
 *      description
 *      cost
 *      playerHas
 *      defenseBonus
 * For Potion list:
 *      name
 *      descritpion
 *      cost
 *      playerHas
 *      hpBonus
 */ 
void Shopkeep::loadItems(){
    // opens file
    ifstream myFile;
    //myFile.open("ItemsFile.txt");
    myFile.open("itemtest.txt");

    string line; // the placeholder for the line of the file
    //char newSect = '$';
    //char newItem = '#';
    int itemCategory = -1;  // depicts the category of item to save to
                            // 0 is weapons, 1 is armor, 2 is potions
    Weapon tempW;
    Armor tempA;
    Potion tempP;
    int tempNum;

    // begins to loop through the file
    while(getline(myFile, line)){
        // Weapon tempW;
        // Armor tempA;
        // Potion tempP;
        // int tempNum;

         // if the line is empty, skip and continue
        if(line.empty()){ continue; } 

        // if the first char of line is $ ...
        if(line.at(0) == '$'){
            // add a new vector row to shop
            itemCategory++;
            continue;
        } // otherwise...
        
        // decide which category it's loading and add the item to the vector    

        if(itemCategory == 0){ 
            // weapons category

            // set playerHas to default
            tempW.setPlayerHas(false);

            // set name
            tempW.setItemName(line);
            getline(myFile, line);

            // set description
            tempW.setDescription(line);
            getline(myFile, line);

            // set cost
            tempNum = stoi(line);
            tempW.setCost(tempNum);

            // set attack bonus
            tempNum = stoi(line);
            tempW.setWeaponAttackBonus(tempNum);            
            getline(myFile, line);

            // set damage bonus
            tempNum = stoi(line);
            tempW.setWeaponDamageBonus(tempNum);

            // add to weapons vector
            weapons.push_back(tempW);
            
        }
        else if(itemCategory == 1){ 
            // armor category

            // set playerHas to default
            tempA.setPlayerHas(false);

            // set name
            tempA.setItemName(line);
            getline(myFile, line);

            // set description
            tempA.setDescription(line);
            getline(myFile, line);

            // set cost
            tempNum = stoi(line);
            tempA.setCost(tempNum);
            getline(myFile, line);

            // set defense bonus
            tempNum = stoi(line);
            tempA.setDefBonus(tempNum);

            // add to armor vector
            armors.push_back(tempA);

        }
        else if(itemCategory == 2){ 
            // potion category

            // set playerHas to default
            tempP.setPlayerHas(false);

            // set name
            tempP.setItemName(line);
            getline(myFile, line);

            // set description
            tempP.setDescription(line);
            getline(myFile, line);

            // set cost
            tempNum = stoi(line);
            tempP.setCost(tempNum);
            getline(myFile, line);

            // set health bonus
            tempNum = stoi(line);
            tempP.setHPBonus(tempNum);

            // add to potions vector
            potions.push_back(tempP);

        }else{ /* something went wrong if it gets here */ }
    
    }//endwhile

    cout << "Finished loading items!\n";
}

// methods for misc interactions
/**
 * allows user to see what is in storage, with four separate categories:
 * 1. Weapons
 * 2. Armor
 * 3. Potions
 * Press anything else to leave storage.
 * Asks for user input on which category to access, and if it's 1,2,or 3 then calls printStorageItems
 * to display that particular group of items. If anything else, go back to main menu
 */ 
void Shopkeep::displayStorage(){

}
/**
 * prints the storage items in that specific category using the storage vector
 */ 
void Shopkeep::printStorageItems(){

}
/**
 * in the displayStorage() player might choose to access an item in storage and take it out to put in their inventory
 * this method will regulate putting the other item used in it and return 
 */ 
void Shopkeep::accessItemInStorage(vector<Item> items){

}
        


// methods for shopping interactions

/**
 * <enter shopkeep quote here>
 *      What would you like to do?
 *      1. Shop
 *      2. Storage
 *      3. Monster stats
 *      Press anything else to travel back to tower
 *  If player chooses ...
 *      1: opens the shopping menu
 *      2: prints out all the items in storage to choose from
 *      3: prints out the stats of encountered monsters using getMonsterStats()
 *      Anything else: player goes back to the tower and the floor they left off on
 */ 
void Shopkeep::displayMainShopMenu(){

}
/**
 * @returns a random shopkeep quote (also used by the displayMenu method)
 */ 
string Shopkeep::getQuote(){

}
/**
 * if the player so desires, a file that contains the Monsters they've defeated 
 * and how many times they've defeated them will be loaded and printed to the console
 */ 
void Shopkeep::displayMonsterStats(){

}

// methods for buying
/**
 * when the player decides to buy an item, this method will compare the current gold the player has with the 
 * cost of the item. If the player doesn't have enough, the shopkeep will reject the purchase. If the player
 * has enough, they may buy it, and the item's playerHas variable is set to true (depending on the item)
 */ 
void Shopkeep::buyItem(){

}
