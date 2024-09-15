/* Program name: burger.cpp
 * Author: Younghyun Lee
 * Date last updated: 8/27/2024
 * Purpose: Order customized burgers
 */
#ifndef BURGER_H
#define BURGER_H
#include <string>
#include "common.h"

using namespace std;

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
