#include <iostream>
#include <string>
#include "Item.h"
#include "Potion.h"
#include "Weapon.h"

using namespace std;

int main(){
    // testing Items
    Item a1;
    a1.setItemName("item");
    a1.setDescription("jfhds");
    Weapon a2;
    a2.setItemName("sword");
    Potion a3;
    a3.setItemName("health potion");
    cout << a1.getItemName() << " " << a2.getItemName() << " " << a3.getItemName() << "\n";
}