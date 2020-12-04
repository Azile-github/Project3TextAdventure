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

int calcCostW(Weapon w){
    return w.getWeaponDamageBonus() + w.getWeaponAttackBonus() + 9;
}
int calcCostA(Armor a){
    return (a.getDefBonus() * 1.50) + 10;
}

int main(){
    Shopkeep s;
    s.loadItems("tx.txt");
    s.saveItems("tt.txt");
    
    return 0;
}
/**
 * 
    vector<string> quotes;      // vector array of shopkeep quotes
    vector<Weapon> weapons;     // vector array of weapon items
    vector<Armor> armors;       // vector array of armor items
    vector<Potion> potions;
    
    ifstream myFile;
    myFile.open("ItemsFile.txt");
    //myFile.open("itemtest.txt");

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
        cout << "Starting a new item...";

        if(itemCategory == 0){ 
            // weapons category
            cout << "weapon\n";
            cout << "name is: " << line << "\n";

            // set playerHas to default
            tempW.setPlayerHas(false);

            // set name
            tempW.setItemName(line);
            getline(myFile, line);

            cout << "desc is: " << line << "\n";

            // set description
            tempW.setDescription(line);
            getline(myFile, line);

            cout << "cost is: " << line << "\n";

            // // set cost

            // tempW.setCost(tempNum);
            getline(myFile, line);

            cout << "attk is: " << line << "\n";

            // set attack bonus
            tempNum = stoi(line);
            tempW.setWeaponAttackBonus(tempNum);            
            getline(myFile, line);

            cout << "dmg is: " << line << "\n";

            // set damage bonus
            tempNum = stoi(line);
            tempW.setWeaponDamageBonus(tempNum);

            cout << "\tAdding to vector\n";

            tempW.setCost(calcCostW(tempW));

            // add to weapons vector
            weapons.push_back(tempW);
            
        }
        else if(itemCategory == 1){ 
            cout << "armor\n";
            // armor category

            cout << "line is: " << line << "\n";

            // set playerHas to default
            tempA.setPlayerHas(false);

            // set name
            tempA.setItemName(line);
            getline(myFile, line);

            cout << "line is: " << line << "\n";

            // set description
            tempA.setDescription(line);
            getline(myFile, line);

            cout << "line is: " << line << "\n";

            // // set cost
            // tempNum = stoi(line);
            // tempA.setCost(tempNum);
            getline(myFile, line);

            cout << "line is: " << line << "\n";

            // set defense bonus
            tempNum = stoi(line);
            tempA.setDefBonus(tempNum);

            tempA.setCost(calcCostA(tempA));
            
            cout << "\tAdding to vector\n";

            // add to armor vector
            armors.push_back(tempA);

        }
        else if(itemCategory == 2){
            cout << "potion\n"; 
            // potion category

            // set playerHas to default
            tempP.setPlayerHas(false);

            cout << "line is: " << line << "\n";

            // set name
            tempP.setItemName(line);
            getline(myFile, line);

            cout << "line is: " << line << "\n";

            // set description
            tempP.setDescription(line);
            getline(myFile, line);

            cout << "line is: " << line << "\n";

            // set cost
            tempNum = stoi(line);
            tempP.setCost(tempNum);
            getline(myFile, line);

            cout << "line is: " << line << "\n";

            // set health bonus
            tempNum = stoi(line);
            tempP.setHPBonus(tempNum);

            cout << "\tAdding to vector\n";

            // add to potions vector
            potions.push_back(tempP);

        }else{  something went wrong if it gets here  }
    
    }//endwhile

    cout << "Finished loading items!\n";
    myFile.close();

    // load to file

    ofstream ofile;

    ofile.open("tx.txt");

    ofile << "$ WEAPONS" << endl;
    for(Weapon temp : weapons){
        ofile << temp.getItemName() << endl;
                ofile << temp.getDescription() << endl;
                ofile << temp.getCost() << endl;
                ofile << temp.getWeaponAttackBonus() << endl;
                ofile << temp.getWeaponDamageBonus() << endl;        
    }
    ofile << "$ ARMORS" << endl;
    for(Armor temp : armors){
        ofile << temp.getItemName() << endl;
                ofile << temp.getDescription() << endl;
                ofile << temp.getCost() << endl;
                ofile << temp.getDefBonus() << endl;            
    }
    ofile << "$ POTIONS" << endl;
    for(Potion temp : potions){
            // print out its information
            ofile << temp.getItemName() << endl;
            ofile << temp.getDescription() << endl;
            ofile << temp.getCost() << endl;
            ofile << temp.getHPBonus() << endl;      
    }// endfor-each
 */