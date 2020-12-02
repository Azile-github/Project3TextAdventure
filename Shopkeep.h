//Isabelle Hoff + Skyla Gyimesi
#ifndef SHOPKEEP_H
#define SHOPKEEP_H

#include <iostream>
#include <string>
#include <vector>
#include "Item.h"
#include "Weapon.h"
#include "Potion.h"
#include "Armor.h"

using namespace std;

class Shopkeep{
    private: 
        vector<string> quotes;      // vector array of shopkeep quotes
        vector<Weapon> weapons;     // vector array of weapon items
        vector<Armor> armors;       // vector array of armor items
        vector<Potion> potions;     // vector array of potion items
        vector<Item> storage[3];   // vector of item vectors. There will be three rows and many columns
                                        // row 0 --> Weapons
                                        // row 1 --> Armor
                                        // row 2 --> Potions
        

    public: 
        Shopkeep();
        // methods for loading the files
        /**
         * loads the shopkeep quotes from the txt file into the quotes vector
         */ 
        void loadQuotes();
        /**
         * loads the items (potions, weapons, and armors) from a given txt file into their respective vectors
         * @param inFile the name of the tile to be accessed
         */ 
        void loadItems(string inFile);
        /**
         * outputs the items (potions, weapons, and armors) into a given txt file from their respective vectors
         * @param outFile name of the tile to be accessed
         */ 
        void saveItems(string outFile);
        void displayShop();
        void displayShop(int type);

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
        /**
         * if the player so desires, a file that contains the Monsters they've defeated 
         * and how many times they've defeated them will be loaded and printed to the console
         */ 
        void displayMonsterStats();
        


        // methods for shopping interactions
        /**
         * displays the interaction menu
         *      What would you like to do?
         *      1. Shop
         *      2. Storage
         *      3. Monster stats
         *      Press anything else to travel back to tower
         *  If player chooses ...
         *      1: opens the shopping menu
         *      2: prints out all the items in storage to choose from
         *      3: prints out the stats of encountered monsters
         *      Anything else: player goes back to the tower and the floor they left off on
         */ 
        void displayMainShopMenu();
        /**
         * @returns a random shopkeep quote (also used by the displayMenu method)
         */ 
        string getQuote();

        void shop();
        

        // methods for buying
        /**
         * when the player decides to buy an item, this method will compare the current gold the player has with the 
         * cost of the item. If the player doesn't have enough, the shopkeep will reject the purchase. If the player
         * has enough, they may buy it, and the item's playerHas variable is set to true (depending on the item)
         */ 
        void buyItem();

        /**
         * If player wishes to save game, this method will be called on and will load everything into the current game items file
         */
        void saveItemStatus();

        /**
         * if reloading a saved game...
         */


        // void displayWeapons();
        // void displayArmor();
        // void displayPotions();

        // vector<Item> getWeapons() const;
        // vector<Item> getArmors() const;
        // vector<Item> getW() const;


};
#endif