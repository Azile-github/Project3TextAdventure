//Isabelle Hoff + Skyla Gyimesi
// FILE FOR ITEMS CLASS

#include <iostream>
#include <fstream>
#include <string>
#include "Item.h"

using namespace std;

// Constructors


// Methods
/**
 * loads the shopkeep quotes from the txt file into the quotes vector
 */ 
void loadQuotes(){

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
 *      ID
 *      cost
 *      playerHas (this will be false by default)
 *      attackBonus
 *      damageBonus
 * For Armor list:
 *      name
 *      description
 *      ID
 *      cost
 *      playerHas
 *      defenseBonus
 * For Potion list:
 *      name
 *      descritpion
 *      ID
 *      cost
 *      playerHas
 *      hpBonus
 */ 
void loadItems(){
    // opens file
    ifstream myFile;
    myFile.open("ItemsFile.txt");

    string line;
    //char newSect = '$';
    //char newItem = '#';
    int itemCategory = -1;  // depicts the category of item to save to
                            // 0 is weapons, 1 is armor, 2 is potions

    // begins to loop through the file
    while(getline(myFile, line)){
        // if the first char of line is $ ...
        if(line.at(0) == '$'){
            // add a new vector row to shop
            itemCategory++;
            continue;
        } // otherwise...
        // decide which category it's loading and add the item to the vector
        
        if(itemCategory == 0){ // weapons category
            
            
        }else if(itemCategory == 1){

        }else if(itemCategory == 2){

        }else{ /* something went wrong if it gets here */ }
    }


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
void displayStorage();
/**
 * prints the storage items in that specific category using the storage vector
 */ 
void printStorageItems();
/**
 * in the displayStorage() player might choose to access an item in storage and take it out to put in their inventory
 * this method will regulate putting the other item used in it and return 
 */ 
void accessItemInStorage(vector<Item> items);
        


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
void displayMainShopMenu();
/**
 * @returns a random shopkeep quote (also used by the displayMenu method)
 */ 
string getQuote();
/**
 * if the player so desires, a file that contains the Monsters they've defeated 
 * and how many times they've defeated them will be loaded and printed to the console
 */ 
void displayMonsterStats();

// methods for buying
/**
 * when the player decides to buy an item, this method will compare the current gold the player has with the 
 * cost of the item. If the player doesn't have enough, the shopkeep will reject the purchase. If the player
 * has enough, they may buy it, and the item's playerHas variable is set to true (depending on the item)
 */ 
void buyItem();
