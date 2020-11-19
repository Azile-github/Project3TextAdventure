#ifndef ITEM_H
#define ITEM_H

#include <iostream>
#include <string>

using namespace std;

class Item{
    private: 
        string name;
        string description;
        int attack;
        int damage;
        
    public: 
        Item();
        void setName(string name);
        string getName();

        void setDescription(string desc);
        string getDescription();

        void setAttack(int att);
        int getAttack();

        void setDamage(int dmg);
        int getDamage();

};
#endif