/* Program name: burger.cpp
 * Author: Younghyun Lee
 * Date last updated: 8/27/2024
 * Purpose: Order customized burgers
 */
#include <iostream>
#include <string>
#include <climits>
#include <iomanip>
#include "burger.h"

using namespace std;

// For the main program you will create a simple menu program that will allow a user to order a custom burger. The program will let the user choose their protein and number of patties. It will let them specify their bun, cheese, condiments, and toppings. After everything has been chosen the burger will be displayed to the user and they will have the option to make changes. If the customer would make a change that would cause a burger to no longer be classified as vegetarian, they should be warned about the change and forced to confirm that they want to proceed. After the user has finished making changes the final burger will be displayed and the program will exit.

int main()
{
  ProteinType proteinT;
  CondimentType condimentT[7];
  int numC = 0;
  ToppingType toppingT[7];
  int numT = 0;
  BunType bunT;
  CheeseType cheeseT;
  int numP = 0;

  showPromptNumP();
  numP = getUserChoiceInt();
  // cout << "numP: " << numP << endl;

  showProteinList();
  int userChoice = getUserChoiceInt();
  proteinT = static_cast<ProteinType>(userChoice);
  // cout << "proteinT: " << proteinT;

  do
  {
    showTopplingList();
    cin >> userChoice;
    if (userChoice != -1 && numT < 7)
    {
      toppingT[numT++] = static_cast<ToppingType>(userChoice);
    }
    cout << "numT: " << numT << endl;
  } while (userChoice != -1 && numT < 7);

  for (int i = 0; i < numT; i++)
  {
    cout << "topping: " << toppingT[i] << endl;
  }

  do
  {
    showCondimentList();
    cin >> userChoice;
    if (userChoice != -1 && numC < 7)
    {
      condimentT[numC++] = static_cast<CondimentType>(userChoice);
    }
  } while (userChoice != -1 && numC < 7);

  showBunList();
  userChoice = getUserChoiceInt();
  bunT = static_cast<BunType>(userChoice);

  showCheeseList();
  userChoice = getUserChoiceInt();
  cheeseT = static_cast<CheeseType>(userChoice);

  // make a class object
  Burger myBurger(proteinT, condimentT, numC, toppingT, numT, bunT, cheeseT, numP);

  return 0;
}
