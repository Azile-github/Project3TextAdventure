//Isabelle Hoff + Skyla Gyimesi
#include "Game.h"
#include "Monster.h"
#include "Player.h"
#include <fstream>

Game::Game(){
  ifstream settings;
  string line;
  settings.open(./save/settings.txt);
  getline(settings, line);
  getline(settings, line);
  monT1 = stoi(line.substr(26,2));
  getline(settings, line);
  monT2 = stoi(line.substr(26,2));
  getline(settings, line);
  monT3 = stoi(line.substr(26,2));
  cout << "t1 is " << monT1 << " t2 is " << monT2 << " t3 is " << monT3;
}
void Game::loadFloor(int floor){
  //loads the contents of the floor ie monster encounter
  if(floor > 10){

  }
}

Game::Game(int t){
  cout << "why";
}

int Game::gameOver(){
  //ends the game to title returns -1
}

int Game::attackMenu(){
  //user attack interface returns attack attempt value
}

int Game::highScoreSort(){
  //for the title
  //sorts the highscores gotten to reread to player
}

void Game::introduction(){
  // for the introduction and explanation of the game. Given by the shopkeeper
}

void Game::combat(Player player, int monsterId){
  bool escape = false;
  int menuInput;
  int attackRoll;
  bool playerTurn = true;
  Monster monster(monsterId);
  cout << "Infront of you is a " << monster.returnNameMonster() << " ready to fight." << endl;
  while(player.getHealth() > 0 && monster.returnHitPoints() > 0){
    while(playerTurn = true){
      cout << "What will you do?" << endl;
      cout << "HP: " << player.getHealth() << endl;
      cout << "1. Attack" << endl;
      cout << "2. Use Item" << endl;
      cin >> menuInput;
      switch (menuInput)
      {
      case 1:
        attackRoll = ((rand() % 20) + 1) + player.getAttackBonus();
        cout << "You swing with a " << player.item[0].getName() << " for " << attackRoll << "." << endl;
        if(attackRoll >= monster.returnDefense()){
          cout << "You hit the " << monster.returnNameMonster() << " for " << player.getStrength() + player.item[0].getDamage() << endl;
        }else{
          cout << "You missed the " << monster.returnNameMonster() << endl;
        }

        break;
      case 2:

        break;

      default:
        cout << "Invalid Input!" << endl;
        cout << string(50,'\n');
        break;
      }
    }
    cout << string(50,'\n');
    cout << "The " << monster.returnNameMonster() << " attacks!" << endl;
    attackRoll = ((rand() % 20) + 1) + monster.returnStrength();
    if(attackRoll >= player.getDefense()){
      cout << "The " << monster.returnNameMonster() << " hits you for " << monster.returnDamageBase() << " hit points!" << endl;
      player.removeHealth(monster.returnDamageBase());
    }else{
      cout << "The " << monster.returnNameMonster() << " missed!" << endl;
    }
    playerTurn = true;
  }
  if(player.getHealth() < 1){
    cout << "Darkness surrounds you... You have died." << endl;
  }
  if(monster.returnHitPoints() < 1){
    cout << "You defeated the monster!" << endl;
    cout << "It dropped " << monster.returnRewardBase() << " gold!" << endl;
    player.addGold(monster.returnRewardBase());
  }
}