/* Program name: burger.cpp
 * Author: Younghyun Lee
 * Date last updated: 8/28/2024
 * Purpose: Order customized burgers
 */
#include <iostream>
#include <string>
#include "burger.h"

using namespace std;

// Constructor
Burger::Burger(ProteinType proteinT, CondimentType condimentT[], int numC, ToppingType toppingT[], int numT, BunType bunT, CheeseType cheeseT, int numP)
{
  setProtein(proteinT);
  setCondiments(condimentT, numC);
  setToppings(toppingT, numT);
  setBun(bunT);
  setCheese(cheeseT);
  setNumPatties(numP);
}

// Accessors

// A burger will be classified as vegetarian if the burger patty is set to MUSH or VEGGIE, and BACON is not one of the toppings.

bool Burger::isVeggie() const
{
  if (protein == MUSH || protein == VEGGIE)
  {
    for (int i = 0; i < numToppings; i++)
    {
      if (toppings[i] == BACON)
      {
        return false;
      }
    }
    return true;
  }
  return false;
}

// For the price function, you will follow the following algorithm.

// Use the price per patty found in the enum mapping table above to calculate the price for the protein (multiply by the number of patties).
// Add $0.50 for each topping
// Add $0.25 for each condiment
// Add $0.10 if they have cheese

double Burger::getPrice() const
{
  double price = 0;
  switch (protein)
  {
  case BEEF:
    price += 2.50;
    break;
  case CHICKEN:
    price += 2.00;
    break;
  case MUSH:
    price += 1.50;
    break;
  case TURKEY:
    price += 2.25;
    break;
  case VEGGIE:
    price += 2.00;
    break;
  }
  price += numPatties * 1.00;
  price += numCondiments * 0.25;
  price += numToppings * 0.50;
  if (cheese != NOCHEESE)
  {
    price += 0.10;
  }
  return price;
}

BunType Burger::getBun() const
{
  return bunType;
}

CheeseType Burger::getCheese() const
{
  return cheese;
}

int Burger::getNumPatties() const
{
  return numPatties;
}

ProteinType Burger::getProtein() const
{
  return protein;
}

string Burger::getCondiments() const
{
  string condimentList = "";
  for (int i = 0; i < numCondiments; i++)
  {
    if (i == numCondiments - 1)
    {
      condimentList += getCondimentTypeName(condiments[i]);
    }
    else
    {
      condimentList += getCondimentTypeName(condiments[i]) + ", ";
    }
  }
  return condimentList;
}

string Burger::getToppings() const
{
  string toppingList = "";
  for (int i = 0; i < numToppings; i++)
  {
    if (i == numToppings - 1)
    {
      toppingList += getToppingTypeName(toppings[i]);
    }
    else
    {
      toppingList += getToppingTypeName(toppings[i]) + ", ";
    }
  }
  return toppingList;
}

// Other
string Burger::tostring() const
{
  string burgerString = "Protein: " + getProteinTypeName(protein) + "\n";
  burgerString += "Number of patties: " + to_string(numPatties) + "\n";
  burgerString += "Bun Type: " + getBunTypeName(bunType) + "\n";
  burgerString += "Cheese: " + getCheeseTypeName(cheese) + "\n";
  burgerString += "Condiments: " + getCondiments() + "\n";
  burgerString += "Toppings: " + getToppings() + "\n";
  if (isVeggie()) {
    burgerString += "This is a vegetarian burger.\n";
  }
  return burgerString;
}

// Mutators
void Burger::setBun(BunType bunT)
{
  bunType = bunT;
}

void Burger::setCheese(CheeseType cheeseT)
{
  cheese = cheeseT;
}

void Burger::setCondiments(CondimentType condimentT[], int numC)
{
  for (int i = 0; i < numC; i++)
  {
    condiments[i] = condimentT[i];
  }
  numCondiments = numC;
}

void Burger::setNumPatties(int numP)
{
  numPatties = numP;
}

void Burger::setProtein(ProteinType proteinT)
{
  protein = proteinT;
}

void Burger::setToppings(ToppingType toppingT[], int numT)
{
  for (int i = 0; i < numT; i++)
  {
    toppings[i] = toppingT[i];
  }
  numToppings = numT;
}

// Destructor
Burger::~Burger() {}


void showPromptNumP()
{
  cout << "How many patties do you want on your burger?";
  cout << endl;
}

void showProteinList()
{
  cout << "Please choose a protein from the list." << endl;
  cout << "1: Beef" << endl;
  cout << "2: Turkey" << endl;
  cout << "3: Chicken Breast" << endl;
  cout << "4: Portabella Mushroom" << endl;
  cout << "5: Veggie" << endl;
  cout << endl;
}

void showTopplingList()
{
  cout << "Please choose a topping from the list. Enter -1 to stop adding toppings." << endl;
  cout << "1: Grilled Onion" << endl;
  cout << "2: Raw Onion" << endl;
  cout << "3: Tomato" << endl;
  cout << "4: Lettuce" << endl;
  cout << "5: Bacon" << endl;
  cout << "6: Grilled Mushroom" << endl;
  cout << "7: Pickle" << endl;
  cout << "8: None" << endl;
  cout << endl;
}

void showCondimentList()
{
  cout << "Please choose a condiment from the list. Enter -1 to stop adding condiments." << endl;
  cout << "1: Ketchup" << endl;
  cout << "2: Mustard" << endl;
  cout << "3: Mayonnaise" << endl;
  cout << "4: Special Sauce" << endl;
  cout << "5: BBQ Sauce" << endl;
  cout << "6: Steak Sauce" << endl;
  cout << "7: Peppercorn Ranch" << endl;
  cout << "8: None" << endl;
  cout << endl;
}

void showBunList()
{
  cout << "Please choose a bun from the list." << endl;
  cout << "1: Brioche" << endl;
  cout << "2: Wheat" << endl;
  cout << "3: Sesame" << endl;
  cout << "4: Onion" << endl;
  cout << "5: Rye Bread" << endl;
  cout << "6: None" << endl;
  cout << "7: Gluten Free" << endl;
  cout << endl;
}

void showCheeseList()
{
  cout << "Please choose a cheese from the list." << endl;
  cout << "1: Cheddar" << endl;
  cout << "2: American" << endl;
  cout << "3: Pepper Jack" << endl;
  cout << "4: Swiss" << endl;
  cout << "5: Colby Jack" << endl;
  cout << "6: None" << endl;
  cout << endl;
}

void showBurgerChangeMenu()
{
  cout << "Would you like to change the burger? Please choose from the menu." << endl;
  cout << "1. Change Protein" << endl;
  cout << "2. Change Number of Patties" << endl;
  cout << "3. Change Toppings" << endl;
  cout << "4. Change Cheese" << endl;
  cout << "5. Change Bun" << endl;
  cout << "6. Change Condiments" << endl;
  cout << "7. No Changes" << endl;
  cout << endl;
}

void showWarning()
{
  cout << "Warning you are changing the burger from vegetarian to meat based. Do you want to continue?";
}

int getUserChoiceInt()
{
  int choice;
  cin >> choice;
  return choice;
}

char getUserChoiceChar()
{
  char choice;
  cin >> choice;
  return tolower(choice);
}

string getBunTypeName(BunType bunT)
{
  switch (bunT)
  {
  case BRIOCHE:
    return "Brioche";
  case ONION:
    return "Onion";
  case RYE:
    return "Rye Bread";
  case SESAME:
    return "Sesame";
  case WHEAT:
    return "Wheat";
  case NOBUN:
    return "None";
  case GLUTENFREE:
    return "Gluten Free";
  }
  return "UNKNOWN";
}

string getCheeseTypeName(CheeseType cheeseT)
{
  switch (cheeseT)
  {
  case AMERICAN:
    return "American";
  case CHEDDAR:
    return "Cheddar";
  case COLBYJACK:
    return "Colby Jack";
  case PEPPERJACK:
    return "Pepper Jack";
  case SWISS:
    return "Swiss";
  case NOCHEESE:
    return "None";
  }
  return "UNKNOWN";
}

string getCondimentTypeName(CondimentType condimentT)
{
  switch (condimentT)
  {
  case BBQ:
    return "BBQ Sauce";
  case KETCHUP:
    return "Ketchup";
  case MAYO:
    return "Mayonnaise";
  case MUSTARD:
    return "Mustard";
  case PEPPERCORN:
    return "Peppercorn Ranch";
  case SPECIAL:
    return "Special Sauce";
  case STEAK:
    return "Steak Sauce";
  case NOCOND:
    return "None";
  }
  return "UNKNOWN";
}

string getProteinTypeName(ProteinType proteinT)
{
  switch (proteinT)
  {
  case BEEF:
    return "Beef";
  case CHICKEN:
    return "Chicken Breast";
  case MUSH:
    return "Portabella Mushroom";
  case TURKEY:
    return "Turkey";
  case VEGGIE:
    return "Veggie";
  }
  return "UNKNOWN";
}

string getToppingTypeName(ToppingType toppingT)
{
  switch (toppingT)
  {
  case BACON:
    return "Bacon";
  case GRILLONION:
    return "Grilled Onion";
  case LETTUCE:
    return "Lettuce";
  case MUSHROOM:
    return "Grilled Mushroom";
  case PICKLE:
    return "Pickle";
  case RAWONION:
    return "Raw Onion";
  case TOMATO:
    return "Tomato";
  case NOTOP:
    return "None";
  }
  return "UNKNOWN";
}
