/* Program name: burger.cpp
 * Author: Younghyun Lee
 * Date last updated: 8/27/2024
 * Purpose: Order customized burgers
 */
#ifndef BURGER_H
#define BURGER_H
#include <string>

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

class Burger
{
public:
  // Constructor
  Burger(ProteinType proteinT, CondimentType condimentT[], int numC, ToppingType toppingT[], int numT, BunType bunT, CheeseType cheeseT, int numP);
  // Destructor
  ~Burger();

  // Accessors
  bool isVeggie() const;
  double getPrice() const;
  BunType getBun() const;
  CheeseType getCheese() const;
  int getNumPatties() const;
  ProteinType getProtein() const;
  string getCondiments() const;
  string getToppings() const;

  // Other
  string tostring() const;

  // Mutators
  void setBun(BunType bunT);
  void setCheese(CheeseType cheeseT);
  void setCondiments(CondimentType condimentT[], int numC);
  void setNumPatties(int numP);
  void setProtein(ProteinType proteinT);
  void setToppings(ToppingType toppingT[], int numT);

private:
  bool isVeg;
  BunType bunType;
  CheeseType cheese;
  CondimentType condiments[7];
  int numCondiments;
  int numPatties;
  ProteinType protein;
  ToppingType toppings[7];
  int numToppings;
};

#endif
