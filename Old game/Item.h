//Isabelle Hoff + Skyla Gyimesi
#ifndef ITEM_H
#define ITEM_H

#include <iostream>
#include <string>

using namespace std;

class Item{

    private: 

        string itemName;    // name of item
        string description; // description of item (what the shopkeep says about it)
        string ID;          // the ID number of the item (example W001 for weapon 001 out of 99)
        int cost;           // cost in gold (from killing monsters) of the item
        bool playerHas;     // if true, then the player has this and it will not show up in the shopkeep menu
                            // if false, then player does not have this and it will show up in the shopkeep menu
                            // some items the player can only have one of, and others the player can have multiple
                            
    public: 
        Item(); // this will be blank

        /**
         * sets the name of the item
         * @param nameIn the given name to set it as
         */ 
        void setItemName(string nameIn);
        /**
         * @returns the name of the item
         */ 
        string getItemName() const;

        /**
         * sets the description of the item
         * @param desc the description of the item (what the shopkeep says about it)
         */ 
        void setDescription(string desc);
        /**
         * @returns the description of the item
         */ 
        string getDescription() const;

        /**
         * sets the IDNum of the item
         * @param desc the description of the item (what the shopkeep says about it)
         */ 
        void setID(string id);
        /**
         * @returns the ID of the item
         */ 
        string getID() const;

        /**
         * sets the cost of the item to value
         * @param value the input cost of the item
         */
        void setCost(int value);
        /**
         * @returns the cost of the item
         */
        int getCost() const;  

        /**
         * sets the status of the item
         * @param inInventory if true, then the player has this in their inventory. False if not
         */
        void setPlayerHas(bool inInventory);
        /**
         * @returns if the player has this item in their inventory
         */
        bool doesPlayerHave() const;  


};
#endif