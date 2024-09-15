#ifndef COMMON_H
#define COMMON_H

#include <iostream>
#include <string>
#include <climits>
#include <iomanip>

using namespace std;

enum ProteinType
{
  BEEF = 1,
  TURKEY,
  CHICKEN,
  MUSH,
  VEGGIE
};

enum ToppingType
{
  GRILLONION = 1,
  RAWONION,
  TOMATO,
  LETTUCE,
  BACON,
  MUSHROOM,
  PICKLE,
  NOTOP
};

enum CondimentType
{
  KETCHUP = 1,
  MUSTARD,
  MAYO,
  SPECIAL,
  BBQ,
  STEAK,
  PEPPERCORN,
  NOCOND
};

enum BunType
{
  BRIOCHE = 1,
  WHEAT,
  SESAME,
  ONION,
  RYE,
  NOBUN,
  GLUTENFREE
};

enum CheeseType
{
  CHEDDAR = 1,
  AMERICAN,
  PEPPERJACK,
  SWISS,
  COLBYJACK,
  NOCHEESE
};

// prompt functions
void showPromptNumP();
void showProteinList();
void showTopplingList();
void showCondimentList();
void showBunList();
void showCheeseList();
void showBurgerChangeMenu();
void showWarning();

// get user input functions
int getUserChoiceInt();
char getUserChoiceChar();

// enum to string functions
string getBunTypeName(BunType bunT);
string getCheeseTypeName(CheeseType cheeseT);
string getCondimentTypeName(CondimentType condimentT);
string getProteinTypeName(ProteinType proteinT);
string getToppingTypeName(ToppingType toppingT);

#endif
