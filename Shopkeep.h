#ifndef SHOPKEEP_H
#define SHOPKEEP_H

#include <iostream>
#include <string>
#include <vector>
#include "Item.h"
#include "Weapon.h"
#include "Potion.h"

using namespace std;

class Shopkeep{
    private: 
        vector<string> quotes;  // vector array of shopkeep quotes
        vector<Item> weapons;   // vector array of weapon items
        vector<Item> armors;    // vector array of armor items
        vector<vector<Item>> storage;   // vector of item vectors. There will be three rows and many columns
        

    public: 
        // methods for loading the files
        /**
         * loads the shopkeep quotes from the txt file into the quotes vector
         */ 
        void loadQuotes();
        /**
         * loads the items (potions, weapons, and armors) from a given txt file into their respective vectors
         */ 
        void loadItems();

        // methods for misc interactions
        /**
         * allows user to see what is in storage, with four separate categories:
         * 1. Weapons
         * 2. Armor
         * 3. Potions
         * Press anything else to leave storage.
         * Asks for user input on which category to access, and if it's 1,2,or 3 then calls printStorageItems
         * to display that particular group of items. If anything else, go back to 
         */ 
        void displayStorage();
        /**
         */ 
        void printStorageItems();
        /**
         * player is prompted to 
         */ 
        void accessItemInStorage(vector<Item> items);
        


        // methods for shopping interactions
        /**
         * displays the interaction menu
         *      What would you like to do?
         *      1. Shop
         *      2. Storage
         *      3. Monster stats
         *      Press anything else to travel back to tower
         *  If player chooses 
         */ 
        void displayMainMenu();
        /**
         * returns a random shopkeep quote (also used by the displayMenu method)
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

};
#endif