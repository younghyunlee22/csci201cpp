/* Program name: burger.cpp
 * Author: Younghyun Lee
 * Date last updated: 8/28/2024
 * Purpose: Order customized burgers
 */
#include <iostream>
#include <string>
#include <climits>
#include <iomanip>
#include "burger.h"

using namespace std;

int main() {

  ProteinType proteinT;
  CondimentType condimentT[7];
  int numC = 0;
  ToppingType toppingT[7];
  int numT = 0;
  BunType bunT;
  CheeseType cheeseT;
  int numP = 0;

  int userChoice = 0;

  showPromptNumP();
  numP = getUserChoiceInt();
  // cout << "numP: " << numP << endl;

  showProteinList();
  userChoice = getUserChoiceInt();
  proteinT = static_cast<ProteinType>(userChoice);
  // cout << "proteinT: " << proteinT;

  do
  {
    showTopplingList();
    userChoice = getUserChoiceInt();
    if (userChoice != -1) {
        toppingT[numT] = static_cast<ToppingType>(userChoice);
        numT++;
    }
  } while (userChoice != -1 && numT < 7);

  do
  {
    showCondimentList();
    userChoice = getUserChoiceInt();
    if (userChoice != -1) {
        condimentT[numC] = static_cast<CondimentType>(userChoice);
        numC++;
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
  cout << myBurger.tostring() << endl;

  do {
    showBurgerChangeMenu();
    userChoice = getUserChoiceInt();
    char userChoiceChar = ' ';
        switch(userChoice) {
            case 1:
                showProteinList();
                userChoice = getUserChoiceInt();
                proteinT = static_cast<ProteinType>(userChoice);
                if (myBurger.isVeggie() && (proteinT != VEGGIE && proteinT != MUSH)) {
                    showWarning();
                    userChoiceChar = getUserChoiceChar();
                    if (userChoiceChar == 'n') {
                        break;
                    }
                }
                myBurger.setProtein(proteinT);
                break;
            case 2:
                showPromptNumP();
                numP = getUserChoiceInt();
                myBurger.setNumPatties(numP);
                break;
            case 3:
                numT = 0;
              do
                {
                    showTopplingList();
                    userChoice = getUserChoiceInt();
                    if (userChoice != -1) {
                        if (userChoice == 5 && myBurger.isVeggie()) {
                            // userChoice 5 means bacon topping
                            showWarning();
                            userChoiceChar = getUserChoiceChar();
                            if (userChoiceChar == 'n') {
                                continue;
                            }
                        }
                        toppingT[numT] = static_cast<ToppingType>(userChoice);
                        numT++;
                    }
                } while (userChoice != -1 && numT < 7);
                myBurger.setToppings(toppingT, numT);
                break;
            case 4:
                showCheeseList();
                userChoice = getUserChoiceInt();
                cheeseT = static_cast<CheeseType>(userChoice);
                myBurger.setCheese(cheeseT);
                break;
            case 5:
                showBunList();
                userChoice = getUserChoiceInt();
                bunT = static_cast<BunType>(userChoice);
                myBurger.setBun(bunT);
                break;
            case 6:
                numC = 0;
              do
                {
                    showCondimentList();
                    userChoice = getUserChoiceInt();
                    if (userChoice != -1) {
                        condimentT[numC] = static_cast<CondimentType>(userChoice);
                        numC++;
                    }
                } while (userChoice != -1 && numC < 7);
                myBurger.setCondiments(condimentT, numC);
                break;
            case 7:
                break;
        }
  } while (userChoice != 7);

    cout << myBurger.tostring() << endl;

  return 0;
}

