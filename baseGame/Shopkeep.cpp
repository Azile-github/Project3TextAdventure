//Isabelle Hoff + Skyla Gyimesi
// FILE FOR ITEMS CLASS

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Shopkeep.h"
#include "Item.h"
#include "Weapon.h"
#include "Armor.h"
#include "Potion.h"

using namespace std;

// Constructors
Shopkeep::Shopkeep(){
    loadQuotes();
}

Weapon Shopkeep::getWeapons(int index) const{
    return weapons.at(index);
}
Armor Shopkeep::getArmors(int index) const{
    return armors.at(index);

}
Potion Shopkeep::getPotion(int index) const{
    return potions;
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
 * @param inFile the name of the file to be processed
 */ 
void Shopkeep::loadItems(string inFile){
    // opens file
    ifstream myFile;
    myFile.open(inFile);
    if(!myFile.is_open()){ cout << "File is not open. Restart game.\n";}

    string line; // the placeholder for the line of the file
    int itemCategory = -1;  // depicts the category of item to save to
                            // 0 is weapons, 1 is armor, 2 is potions
    
    Weapon tempW;   // temp variable for Weapon object
    Armor tempA;    // temp variable for armor object
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
        
        // decide which category it's loading and add the item to the vector unless it's potions   
        
        if(itemCategory == 0){ 
            // weapons category

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

            // set playerHas to the given variable
            if(line.compare("f") == 0){ tempW.setPlayerHas(false);}
            else{ tempW.setPlayerHas(true); }
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

            if(line.compare("f") == 0){ tempW.setPlayerHas(false);}
            else{ tempW.setPlayerHas(true); }
            getline(myFile, line);


            // set defense bonus
            tempNum = stoi(line);
            tempA.setDefBonus(tempNum);

            // add to armor vector
            armors.push_back(tempA);

        }
        else if(itemCategory == 2){
            // potion category

            // set name
            potions.setItemName(line);
            getline(myFile, line);

            // set description
            potions.setDescription(line);
            getline(myFile, line);

            // set cost
            tempNum = stoi(line);
            potions.setCost(tempNum);
            getline(myFile, line);

            // set playerHas
            if(line.compare("f") == 0){ potions.setPlayerHas(false);}
            else{ potions.setPlayerHas(true); }
            getline(myFile, line);

            // set health bonus
            tempNum = stoi(line);
            potions.setHPBonus(tempNum);

        }else{  /*something went wrong if it gets here*/  }
    
    }//endwhile

    myFile.close();
}//endloadItems

/**
 * outputs the items (potions, weapons, and armors) into a given txt file from their respective vectors
 * @param outFile name of the tile to be accessed
 */ 
void Shopkeep::saveItems(string outFile){
    ofstream ofile;

    ofile.open(outFile);

    ofile << "$ WEAPONS" << endl;
    for(Weapon temp : weapons){
        ofile << temp.getItemName() << endl;
        ofile << temp.getDescription() << endl;
        ofile << temp.getCost() << endl;
        if(temp.doesPlayerHave()){ ofile << "t" << endl; } 
        else{ ofile << "f" << endl; }
        ofile << temp.getWeaponAttackBonus() << endl;
        ofile << temp.getWeaponDamageBonus() << endl;        
    }

    ofile << "$ ARMORS" << endl;
    for(Armor temp : armors){
        ofile << temp.getItemName() << endl;
        ofile << temp.getDescription() << endl;
        ofile << temp.getCost() << endl;
        if(temp.doesPlayerHave()){ ofile << "t" << endl; } 
        else{ ofile << "f" << endl; }
        ofile << temp.getDefBonus() << endl;            
    }

    ofile << "$ POTIONS" << endl;
    
        ofile << potions.getItemName() << endl;
        ofile << potions.getDescription() << endl;
        ofile << potions.getCost() << endl;
        if(potions.doesPlayerHave()){ ofile << "t" << endl; } //if player has this, put t for true
        else{ ofile << "f" << endl; } // otherwise put f for false
        ofile << potions.getHPBonus() << endl;      
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
void Shopkeep::displayMainShopMenu(Player player){
    // retrieve quote
    cout << "\"" << getQuote() << "\""  << "\n";

    while(true){

        int input;
        // display options
        cout << "What would you like to do? (Enter a number.)\n";
        cout << "\t1. Shop \n\t2. Access Storage \n\t3. Monster Stats \n\tPress any other integer to leave the shop.\n";

        cin >> input;

        if(input == 1){

            while(true){
                cout << "What do you want? (Enter a number.)\n";
                cout << "\t1. Weapons\n\t2. Armors\n\t3. Potions\nPress any other integer to exit shopping.\n";
                cin >> input;

                // if the input is 1, 2, or 3  --> continue to displaying the options      
                if(input > 0 && input < 4){
                    displayShop(input);
                    cout << "\tYou have " << player.getGold() << " coins.\n";
                    cout << "Enter the ITEM # of what you'd like to purchase. Enter a non-number to leave this menu.\n";
                    string choiceStr;
                    int choice;
                    cin >> choiceStr;
                    try{ choice = stoi(choiceStr); }catch(exception ex){ continue; }
                    
                        cout << "Are you sure you want to buy ";
                        if(input == 1)     {  cout << weapons.at(choice).getItemName() << " for " << weapons.at(choice).getCost() << " coins?"; }
                        else if(input == 2){  cout << armors.at(choice).getItemName() << " for " << armors.at(choice).getCost() << " coins?"; }
                        else if(input == 3){  cout << potions.getItemName() << " for " << potions.getCost() << " coins?"; }
                        cout << " (You have " << player.getGold() << " coins.)\n";
                        cout << "Press 1 to confirm purchase. Press 0 to deny purchase and look again. Press any other integer to exit this menu.\n";
                        int toBuy;
                        cin >> toBuy;
                        if(toBuy == 1){ buyItem(player, choice, input); continue;}
                        else if(toBuy == 0){ continue; }
                        else{ break; }
                }
                // otherwise continue the mainmenu loop
                break;
            }
            continue;
        }
        if(input == 2){
            // Open Storage menu
            continue;
        }
        if(input== 3){
            // prints out the stats of encountered monsters using getMonsterStats()

        }else if(input == 4){
            // triggers the monster stats menu

            continue;
        }
        // otherwise leave the shop
        break;
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
void Shopkeep::buyItem(Player player, int index, int type){

        if(type == 1){ //weapons
            if(player.getGold() >= weapons.at(index).getCost()){
                player.setGold(player.getGold() - weapons.at(index).getCost());
                cout << "\tPurchase successful, " << player.getName() << "! Added to storage.\n";
                weapons.at(index).setPlayerHas(true);
                storage[0].push_back(weapons.at(index));
            }
            else{cout << "This item is too expensive!\n";}
        }
        else if(type == 2){
            if(player.getGold() >= armors.at(index).getCost()){
                player.setGold(player.getGold() - armors.at(index).getCost());
                cout << "\tPurchase successful, " << player.getName() << "! Added to storage.\n";
                armors.at(index).setPlayerHas(true);
                storage[1].push_back(armors.at(index));
            }
            else{ cout << "This item is too expensive!\n";}
        }
        else if(type == 3){
            if(player.getGold() >= potions.getCost()){
                player.setGold(player.getGold() - potions.getCost());
                cout << "\tPurchase successful, " << player.getName() << "! Added to storage.\n";
                player.boughtPotion();
            }
            else {cout << "This item is too expensive!\n";}
        }
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

    if(type - 1 == 0){
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
    else if(type - 1 == 1){

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
    else if(type - 1 == 2){
        cout << "\"Need some health? Got a wound? I got everything you need!\" cheered the shopkeep.\n\n\t\t\t~*~ POTION MENU ~*~\n\n";
        //display potions. Doesn't matter if playerHas is true or false
            index++;
            // print out its information
            cout << "\tITEM #" << index << "\n" << potions.getItemName() << "\n";
            cout << "Description:\n\t" << potions.getDescription() << "\n";
            cout << "HP Bonus: " << potions.getHPBonus() << "\n";
            cout << "Cost: " << potions.getCost() << " coins\n\n";
    }
    else{ cout << "ERROR: Invalid numerical parameter input. A number outside this function's defined range of 0 to 2 was given.\n"; } // error statement


}

// void Shopkeep::displayWeapons();
// void Shopkeep::displayArmor();
// void Shopkeep::displayPotions();
void Shopkeep::loadStorage(string inFile){
    // opens file
    ifstream myFile;
    myFile.open(inFile);

    // string line; // the placeholder for the line of the file
    // int itemCategory = -1;  // depicts the category of item to save to
    //                         // 0 is weapons, 1 is armor, 2 is potions
    
    // Weapon tempW;   // temp variable for Weapon object
    // Armor tempA;    // temp variable for armor object
    // Potion tempP;   // temp variable for potion object
    // int tempNum;    // temp variables for integers

    // // begins to loop through the file
    // while(getline(myFile, line)){


    //      // if the line is empty, skip and continue
    //     if(line.empty()){ continue; } 

    //     // if the first char of line is $ ...
    //     if(line.at(0) == '$'){
    //         // add a new vector row to shop
    //         itemCategory++;
    //         continue;
    //     } // otherwise...
        
    //     // decide which category it's loading and add the item to the vector    
        
    //     if(itemCategory == 0){ 
    //         // weapons category

    //         // set name
    //         tempW.setItemName(line);
    //         getline(myFile, line);

    //         // set description
    //         tempW.setDescription(line);
    //         getline(myFile, line);

    //         // set cost
    //         tempNum = stoi(line);
    //         tempW.setCost(tempNum);
    //         getline(myFile, line);

    //         // set playerHas to the given variable
    //         tempW.setPlayerHas(true); 
    //         getline(myFile, line);

    //         // set attack bonus
    //         tempNum = stoi(line);
    //         tempW.setWeaponAttackBonus(tempNum);            
    //         getline(myFile, line);

    //         // set damage bonus
    //         tempNum = stoi(line);
    //         tempW.setWeaponDamageBonus(tempNum);

    //         // add to weapons vector
    //         storage[0].push_back(tempW);
            
    //     }
    //     else if(itemCategory == 1){ 
    //         // armor category

    //         // set name
    //         tempA.setItemName(line);
    //         getline(myFile, line);

    //         // set description
    //         tempA.setDescription(line);
    //         getline(myFile, line);

    //         // set cost
    //         tempNum = stoi(line);
    //         tempA.setCost(tempNum);
    //         getline(myFile, line);

    //         // set playerHas to default
    //         tempA.setPlayerHas(true);

    //         // set defense bonus
    //         tempNum = stoi(line);
    //         tempA.setDefBonus(tempNum);

    //         // add to armor vector
    //         storage[1].push_back(tempA);

    //     }
    //     else if(itemCategory == 2){
    //         // potion category

    //         // set playerHas to default
    //         tempP.setPlayerHas(false);

    //         // set name
    //         tempP.setItemName(line);
    //         getline(myFile, line);

    //         // set description
    //         tempP.setDescription(line);
    //         getline(myFile, line);

    //         // set cost
    //         tempNum = stoi(line);
    //         tempP.setCost(tempNum);
    //         getline(myFile, line);

    //         // set playerHas to default
    //         tempA.setPlayerHas(true);

    //         // set health bonus
    //         tempNum = stoi(line);
    //         tempP.setHPBonus(tempNum);

    //         // add to potions vector
    //         storage[2].push_back(tempP);

    //     }else{ /* something went wrong if it gets here */ }
    
    // }//endwhile
    myFile.close();

}
