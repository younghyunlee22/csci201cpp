/* Program name: character.cpp
 * Author: Younghyun Lee
 * Date last updated: 9/1/2024
 * Purpose: Make RPG character base class and derived classes
 */

#include <iostream>
#include <string>
#include "character.h"

using namespace std;

int main()
{
  // initialize variables
  string fName;
  string rName;
  string mName;
  string cName;

  // get user input
  cout << "What is your fighter's name: ";
  getline(cin, fName);
  cout << "What is your rogue's name: ";
  getline(cin, rName);
  cout << "What is your magician's name: ";
  getline(cin, mName);
  cout << "What is your cleric's name: ";
  getline(cin, cName);
  cout << "Testing" << endl;

  // create objects
  Fighter fighter(fName);
  Magician magician(mName);
  Cleric cleric(cName);
  Rogue rogue(rName);

  // print out stats and call methods

  cout << "Fighter Starting Stats" << endl;
  cout << fighter.tostring() << endl;

  cout << "Rogue Starting Stats" << endl;
  cout << rogue.tostring() << endl;

  cout << fighter.getName() << " Strong Attack " << rogue.getName() << endl;
  fighter.strongAttack(rogue);
  cout << "Updated Rogue Stats" << endl;
  cout << rogue.tostring() << endl;

  cout << rogue.getName() << " Steal " << fighter.getName() << endl;
  rogue.steal(fighter);
  cout << "Updated Rogue Stats" << endl;
  cout << rogue.tostring() << endl;
  cout << "Updated Fighter Stats" << endl;
  cout << fighter.tostring() << endl;

  cout << "Magician Starting Stats" << endl;
  cout << magician.tostring() << endl;

  cout << magician.getName() << " Cast " << rogue.getName() << endl;
  magician.cast(rogue);
  cout << "Updated Magician Stats" << endl;
  cout << magician.tostring() << endl;
  cout << "Updated Rogue Stats" << endl;
  cout << rogue.tostring() << endl;

  cout << "Cleric Starting Stats" << endl;
  cout << cleric.tostring() << endl;

  cout << cleric.getName() << " Heal " << rogue.getName() << endl;
  cleric.heal(rogue);
  cout << "Updated Cleric Stats" << endl;
  cout << cleric.tostring() << endl;

  cout << "Updated Rogue Stats" << endl;
  cout << rogue.tostring() << endl;

  return 0;
}
