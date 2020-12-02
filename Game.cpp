//Isabelle Hoff + Skyla Gyimesi
//Reload saved game
#include "Game.h"
#include "Monster.h"
#include "Player.h"
#include <fstream>

Game::Game(){
  ifstream settings;
  string line;
  settings.open("./save/settings.txt");
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

Game::Game(Player playerIn){
  player = playerIn;
  theGround();
}

void Game::gameOver(){
  //ends the game to title returns -1
}

void Game::combat(int monsterId){
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
        cout << "You swing with a " << player.getItem(0).getItemName() << " for " << attackRoll << "." << endl;
        if(attackRoll >= monster.returnDefense()){
          cout << "You hit the " << monster.returnNameMonster() << " for " << player.getDamageMod() << endl;
        }else{
          cout << "You missed the " << monster.returnNameMonster() << endl;
        }
        playerTurn = false;
        break;
      case 2:
        if(player.getItem(2).doesPlayerHave()){
          player.addHealth();
          cout << "You used a potion and now have " << player.getHealth() << " HP." << endl;
          playerTurn = false;
        }else{
          cout << "You don't have any potions." << endl;
        }
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
    death();
  }
  if(monster.returnHitPoints() < 1){
    cout << "You defeated the monster!" << endl;
    cout << "It dropped " << monster.returnRewardBase() << " gold!" << endl;
    player.addGold(monster.returnRewardBase());
    postCombat();
  }
}

void Game::postCombat(){
  Potion potion;
  int option;
  bool escape = false;
  cout << string(10,'\n');
  while(escape = false){
    cout << "You stand now in an empty room of the tower." << endl;
    cout << "You still have " << player.getHealth() << " out of " << player.getMaxHealth() << endl;
    cout << "Floor: " << currentfloor << endl;
    cout << "Inputs" << endl;
    cout << "1. Continue up the tower." << endl;
    cout << "2. Drink potion." << endl;
    cout << "3. View stats." << endl;
    cout << "4. Return to bottom." << endl; 
    cin >> option;
    switch (option){
      case 1:
        generateFloor();
        break;
      case 2:
        //help i dont know about items out of combat
        if(player.getItem(2).doesPlayerHave()){
          player.addHealth();
        }
        break;
      case 3:
        player.printStats();
        break;
      case 4:
        theGround();
        break;
      default:
        cout << "Invalid input." << endl;
        break;
    }
  }
}

void Game::death(){
  player.setGold(player.getGold() * 0.6);
  theGround();
}

void Game::theGround(){
  int menuChoice;
  bool menuExit = false;
  currentfloor = 0;
  player.setMaxHealth(10 + player.getHighestFloor() * 2);
  player.setHealth(player.getMaxHealth()); 
  cout << string(50, '\n');
  cout << "You stand at the base of the tower, what would you like to do?" << endl;
  while(menuExit = false){
    cout << "Input 1, to go into the tower, input 2 to talk with the shopkeep, and 3 to save and quit." << endl;
    cin >> menuChoice;
    switch (menuChoice){
    case 1:
      generateFloor();

      break;
    case 2:
      shopkeep.displayMainShopMenu();
      break;
    case 3:

      break;
    default:
      cout << "Invalid input" << endl;
      break;
    }
  }
}

void Game::generateFloor(){
  int option;
  option = (rand() % 100) + 1;
  if(option > 2){
    combat(chooseMonster());
  }else{
    int coins = (rand() % 50) + 5;
    cout << "Somehow you managed to find a floor with no monsters, just some coins scattered across the floor." << endl;
    cout << "You get " << coins << " gold!" << endl;
    player.addGold(coins);
    currentfloor++;
    postCombat();
  }
}

int Game::chooseMonster(){//returns a monster id to load for floor generation
  int randNum;
  int tableNo;
  int lineNo;
  if(currentfloor > 15){
    randNum = (rand() % 10) + 1; //1 to 10
    if(randNum > 5){//table 3
      tableNo = 3;
      lineNo = (rand() % 10) + 1;
      return readTable(tableNo, lineNo);
    }
    if(randNum > 2){
      tableNo = 2;
      lineNo = (rand() % 10) + 1;
      return readTable(tableNo, lineNo);
    }
    if(randNum > 0){
      tableNo = 1;
      lineNo = (rand() % 10) + 1;
      return readTable(tableNo, lineNo);
    }
  }else if(currentfloor > 8){
    randNum = (rand() % 10) + 1; //1 to 10
    if(randNum > 8){//table 3
      tableNo = 3;
      lineNo = (rand() % 10) + 1;
      return readTable(tableNo, lineNo);
    }
    if(randNum > 4){
      tableNo = 2;
      lineNo = (rand() % 10) + 1;
      return readTable(tableNo, lineNo);
    }
    if(randNum > 0){
      tableNo = 1;
      lineNo = (rand() % 10) + 1;
      return readTable(tableNo, lineNo);
    }
  }else if(currentfloor > 0){
    randNum = (rand() % 10) + 1; //1 to 10
    if(randNum > 9){//table 3
      tableNo = 3;
      lineNo = (rand() % 10) + 1;
      return readTable(tableNo, lineNo);
    }
    if(randNum > 7){
      tableNo = 2;
      lineNo = (rand() % 10) + 1;
      return readTable(tableNo, lineNo);
    }
    if(randNum > 0){
      tableNo = 1;
      lineNo = (rand() % 10) + 1;
      return readTable(tableNo, lineNo);
    }
  }
}

int Game::readTable(int tableNo, int lineNo){
  string tableNoStr = to_string(tableNo);
  string fileHead = "./res/monsters/monsterTable";
  ifstream currentTable;
  string line;
  fileHead.append(tableNoStr);
  fileHead.append(".dat");
  currentTable.open(fileHead);
  for(int i = 0; i < lineNo; i++){
    getline(currentTable, line);
  }
  return stoi(line);
}

void Game::saveGame(){
  //writes player save to save.dat
  x
  saveScore(highscoreCalculation());
  gameOver();
}

int Game::highscoreCalculation(){
  int gold = player.getGold();
  int highestFloor = player.getHighestFloor();
  int score = (gold * 1.2) + (highestFloor * 12.7) + 1;
  return score;
}

void Game::saveScore(int score){
  string scoreStr = to_string(score);
  string line;
  vector<string> scores;
  ifstream currentFile;
  ofstream currentFileW;
  currentFile.open("./save/highscore.dat");
  while(getline(currentFile, line)){
    scores.push_back(line);
  }
  currentFile.close();
  scores.push_back(scoreStr);
  currentFileW.open("./save/highscore.dat");
  for (int i = 0; i < scores.size(); i++){
    currentFileW << scores.at(i) << endl;
  }
  
}
void sortScore(){

}

