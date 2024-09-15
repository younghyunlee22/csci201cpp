/* Program name: burger.cpp
 * Author: Younghyun Lee
 * Date last updated: 8/27/2024
 * Purpose: Order customized burgers
 */
#include <iostream>
#include <string>
#include "burger.h"
#include "common.h"

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
  if (isVeggie())
  {
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
