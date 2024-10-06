/* Program name: main.cpp
 * Author: Younghyun Lee
 * Date last updated: 9/16/2024
 * Purpose: Order bags of candy
 */

#include <iostream>
#include <iomanip>
#include <limits>
#include "bag.h"
using namespace std;

// Function prototypes
void resetStream();
void intro();

// Functions
void resetStream()
{
  cin.clear();
  cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void intro()
{
  cout << setfill('=') << setw(90) << " " << endl;
  cout << setfill(' ') << setw(60) << "Welcome to The Cavity Factory!" << endl;
  cout << setfill('=') << setw(90) << " " << endl;

  cout << "\n- We allow our beloved Candy Connoisseurs (yes, that'd be you) to build their own candy!" << endl;
  cout << "There's only one catch: To ensure that our customers explore their palate,\n"
       << "we only allow unique candy to be ordered in each bag. Don't think of it as a limitation, but as an EXPERIENCE!\n\n"
       << endl;
}

int main()
{
  int numBags;

  // Display introduction
  intro();

  cout << "How many bags of candy will you be ordering today?" << endl;
  cin >> numBags;

  // Input validation for number of bags
  while (!cin || numBags < 1)
  {
    if (!cin)
    {
      resetStream();
      cout << "That's not a number." << endl;
    }
    cout << "Invalid entry. Number must be between 1 and 10000 inclusive. Try again." << endl;
    cin >> numBags;
  }

  // Dynamically allocate array of Bag objects
  Bag *bags = new Bag[numBags]; // Create an array of Bag objects

  // Loop through and fill each bag
  for (int i = 0; i < numBags; i++)
  {
    cout << "\nBag #" << (i + 1) << " of " << numBags << "\n\n"
         << endl;
    bags[i].fillBag();

    int numCopies;
    cout << "How many more bags like the last one would you like? ";
    cin >> numCopies;

    // Validate number of copies
    while (!cin || numCopies < 0 || numCopies > numBags - i - 1)
    {
      if (!cin)
      {
        resetStream();
        cout << "That's not a number." << endl;
      }
      cout << "Invalid entry. Number must be between 0 and 3 inclusive. Try again." << endl;
      cin >> numCopies;
    }

    // Use copyBag to copy this bag to subsequent bags
    for (int j = 1; j <= numCopies; j++)
    {
      bags[i + j].copyBag(bags[i]); // Copy this bag to the next
    }

    i += numCopies; // Skip over the copied bags
  }

  // Display all bags and their candy
  cout << "\nYour order:\n";
  for (int i = 0; i < numBags; i++)
  {
    cout << "Bag #" << (i + 1) << "\n";
    cout << bags[i].getCandyList(); // Display the list of candies in each bag
    cout << endl;
  }

  // Delete dynamically allocated memory
  delete[] bags;

  cout << "Thank you for choosing The Cavity Factory, where tooth decay is our priority!\n";
  return 0;
}
