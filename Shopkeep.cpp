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
Shopkeep::Shopkeep(){
    //empty
}

// Methods
/**
 * loads the shopkeep quotes from the txt file into the quotes vector
 */ 
void Shopkeep::loadQuotes(){
    // opens file
    ifstream myFile;
    myFile.open("quotes.txt");

    string line; // the placeholder for the line of the file

    //go through file and process quotes
    while(getline(myFile, line)){
        //when line isn't empty, put into quotes vector
        if(!line.empty())
            quotes.push_back(line);
    }//endwhile

}//endloadQuotes

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
    
    Weapon tempW;   // temp variable for Weapon object
    Armor tempA;    // temp variable for armor object
    Potion tempP;   // temp variable for potion object
    int tempNum;    // temp variables for integers

    // begins to loop through the file
    while(getline(myFile, line)){


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
            getline(myFile, line);

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
    // retrieve quote
    cout << "\"" << getQuote() << "\""  << "\n";

    string input;
    // display options
    cout << "What would you like to do? (Enter a number.)\n";
    cout << "\t1. Shop \n\t2. Access Storage \n\t3. Monster Stats \n\t4. Leave Game\n\tPress anything else to travel back to the tower\n";

    getline(cin, input);

    if(input.compare("1") == 0){
        // Open shop menu
        shop();

    }else if(input.compare("2") == 0){
        // Open Storage menu
    }else if(input.compare("3") == 0){
        // prints out the stats of encountered monsters using getMonsterStats()

    }else if(input.compare("4") == 0){
        // triggers the exit menu
    }else{
        // player returns to tower
        // nothing happens
    }

}
/**
 * @returns a random shopkeep quote (also used by the displayMenu method)
 */ 
string Shopkeep::getQuote(){
    return quotes.at(rand() % quotes.size()); // retrieves the quote at a random index number from 0 to the quotes vector size
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

/*
    //display weapons
    cout << "WEAPONS\n";
    for(Weapon w : weapons){
        cout << "Name: " << w.getItemName() << "\n";
        cout << "Desc: " << w.getDescription() << "\n";
        cout << "Cost: " << w.getCost() << "\n";
        cout << "Att+: " << w.getWeaponAttackBonus() << "\n";
        cout << "Dmg+: " << w.getWeaponDamageBonus() << "\n----\n";
    }

    cout << "ARMORS\n";
    for(Armor a : armors){
        cout << "Name: " << a.getItemName()     << "\n";
        cout << "Desc: " << a.getDescription()  << "\n";
        cout << "Cost: " << a.getCost()         << "\n";
        cout << "Def+: " << a.getDefBonus()     << "\n----\n";

    }

    cout << "POTIONS\n";
    for(Potion p : potions){
        cout << "Name: " << p.getItemName()     << "\n";
        cout << "Desc: " << p.getDescription()  << "\n";
        cout << "Cost: " << p.getCost()         << "\n";
        cout << "Def+: " << p.getHPBonus()      << "\n----\n";

    }

    cout << "\ndone with display\n";

    //display armor

    //display potions
*/

void Shopkeep::displayShop(){

}

/** 
 * displays items in the shop that do not have playerHas set to true
 * 
 * if a number is entered that is not 0, 1, or 2, then an error message is printed.
 * 
 * ERROR: Invalid numerical parameter input. A number outside this function's defined range of 0 to 2 was given.
 *      
 * @param type the integer value that correlates to the type of item that is being printed. 
 *      0 for weapons
 *      1 for armors
 *      2 for potions
 */ 
void Shopkeep::displayShop(int type){
    int index = -1; // allows easy access into the vector by the player to request an item to buy

    if(type == 0){
        cout << "\"Beware the sharp edges!\" says the shopkeep.\n\n\t\t\t~*~ WEAPON MENU ~*~\n\n";
        //display available weapons
        for(Weapon temp : weapons){
            //if player does not have the item...
            index++;
            if(!temp.doesPlayerHave()){
                // print out its information
                cout << "\tITEM #" << index << "\n" << temp.getItemName() << "\n";
                cout << "Description:\n\t" << temp.getDescription() << "\n";
                cout << "Atk Bonus: " << temp.getWeaponAttackBonus() << "\n";
                cout << "Dmg Bonus: " << temp.getWeaponDamageBonus() << "\n";
                cout << "Cost: " << temp.getCost() << " coins\n\n";
            }
            // otherwise do nothing
        }// endfor-each
    }
    else if(type == 1){

        cout << "\"A classic way to prevent wounds,\" says the shopkeep.\n\n\t\t\t~*~ ARMOR MENU ~*~\n\n";
        //display available armors

        for(Armor temp : armors){
            index++;
            //if player does not have the item...
            if(!temp.doesPlayerHave()){
                // print out its information
                cout << "\tITEM #" << index << "\n" << temp.getItemName() << "\n";
                cout << "Description:\n\t" << temp.getDescription() << "\n";
                cout << "Def Bonus: " << temp.getDefBonus() << "\n";
                cout << "Cost: " << temp.getCost() << " coins\n\n";
            }
            // otherwise do nothing
        }// endfor-each

    }
    else if(type == 2){
        cout << "\"Need some health? Got a wound? I got everything you need!\" cheers the shopkeep.\n\n\t\t\t~*~ POTION MENU ~*~\n\n";
        //display potions. Doesn't matter if playerHas is true or false
        for(Potion temp : potions){
            index++;
            // print out its information
            cout << "\tITEM #" << index << "\n" << temp.getItemName() << "\n";
            cout << "Description:\n\t" << temp.getDescription() << "\n";
            cout << "HP Bonus: " << temp.getHPBonus() << "\n";
            cout << "Cost: " << temp.getCost() << " coins\n\n";
        }// endfor-each
    }
    else{ cout << "ERROR: Invalid numerical parameter input. A number outside this function's defined range of 0 to 2 was given.\n"; } // error statement

}

void shop(){

}

// void Shopkeep::displayWeapons();
// void Shopkeep::displayArmor();
// void Shopkeep::displayPotions();
