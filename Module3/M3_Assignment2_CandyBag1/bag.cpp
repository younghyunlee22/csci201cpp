/* Program name: main.cpp
 * Author: Younghyun Lee
 * Date last updated: 9/16/2024
 * Purpose: Order bags of candy
 */

#include <iostream>
#include <string>
#include <limits>
#include "bag.h"

// Default constructor
Bag::Bag() : candies(nullptr), numCandies(0) {}

// Copy constructor
Bag::Bag(const Bag &otherBag)
{
  copyBag(otherBag);
}

// Destructor
Bag::~Bag()
{
  for (int i = 0; i < numCandies; ++i)
  {
    delete candies[i];
  }
  delete[] candies;
}

// Check if the candy is a duplicate
bool Bag::duplicateCheck(int currentCount, Candy newCandy)
{
  for (int i = 0; i < currentCount; ++i)
  {
    if (candies[i]->getFlavor() == newCandy.getFlavor() &&
        candies[i]->getColor() == newCandy.getColor())
    {
      return true; // Found a duplicate
    }
  }
  return false; // No duplicates
}

// Get the list of candies in the bag
string Bag::getCandyList()
{
  string result = ""; // Initialize an empty string
  for (int i = 0; i < numCandies; ++i)
  {
    result += "#" + to_string(i + 1) + " " + Candy::getColorString(candies[i]->getColor()) + " " + Candy::getFlavorString(candies[i]->getFlavor()) + "\n";
  }
  return result;
}

// Perform a deep copy from another Bag
void Bag::copyBag(const Bag &otherBag)
{
  numCandies = otherBag.numCandies;
  candies = new Candy *[numCandies];
  for (int i = 0; i < numCandies; ++i)
  {
    candies[i] = new Candy(*otherBag.candies[i]);
  }
}

// Fill the bag with candies
void Bag::fillBag()
{
  cout << "How many candies will you be ordering today? (range: 1-25)\n";
  cin >> numCandies;

  // Input validation for number of candies
  while (!cin || numCandies < 1 || numCandies > 25)
  {
    if (!cin)
    {
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
      cout << "That's not a number." << endl;
    }
    cout << "Invalid entry. Number must be between 1 and 25 inclusive. Try again.\n";
    cin >> numCandies;
  }

  // Dynamically allocate the candies array
  candies = new Candy *[numCandies];

  for (int i = 0; i < numCandies; ++i)
  {
    flavorType selectedFlavor;
    colorType selectedColor;

    // Get user input for flavor
    cout << "Candy #" << (i + 1) << " of " << numCandies << "\n";
    cout << "Choose a flavor you would like:\n";
    cout << "[1] Cotton Candy\n[2] Watermelon Burst\n[3] Papaya Bliss\n[4] Citrus Splash\n[5] Cola\n";
    int flavorChoice;
    cin >> flavorChoice;

    // Input validation for flavor
    while (!cin || flavorChoice < 1 || flavorChoice > 5)
    {
      if (!cin)
      {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "That's not a number." << endl;
      }
      cout << "Invalid entry. Number must be between 1 and 5 inclusive. Try again.\n";
      cin >> flavorChoice;
    }

    selectedFlavor = static_cast<flavorType>(flavorChoice);

    // Output confirmation message for flavor
    cout << Candy::getFlavorString(selectedFlavor) << "? Great choice.\n";

    // Get user input for color
    cout << "Choose a color for your " << Candy::getFlavorString(selectedFlavor) << " candy:\n";
    cout << "[1] Scarlet Blaze\n[2] Azure Sky\n[3] Emerald Mist\n[4] Goldenrod Glow\n[5] Amethyst Haze\n";
    int colorChoice;
    cin >> colorChoice;

    // Input validation for color
    while (!cin || colorChoice < 1 || colorChoice > 5)
    {
      if (!cin)
      {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "That's not a number." << endl;
      }
      cout << "Invalid entry. Number must be between 1 and 5 inclusive. Try again.\n";
      cin >> colorChoice;
    }

    selectedColor = static_cast<colorType>(colorChoice);

    // Create a new Candy object with the selected flavor and color
    Candy newCandy(selectedFlavor, selectedColor);

    // Output confirmation message for color
    cout << Candy::getColorString(selectedColor) << " " << Candy::getFlavorString(selectedFlavor) << " it is!\n";

    // Check for duplicates
    if (duplicateCheck(i, newCandy))
    {
      // Output duplicate message matching expected output
      cout << "But wait, this is not unique, try again.\n";

      // Display the current order
      cout << "\nYour order:\n";
      for (int j = 0; j < i; ++j)
      {
        cout << "#" << (j + 1) << " " << Candy::getColorString(candies[j]->getColor())
             << " " << Candy::getFlavorString(candies[j]->getFlavor()) << "\n";
      }
      cout << endl;

      --i; // Re-prompt the user for this candy
    }
    else
    {
      // Add the candy to the array
      candies[i] = new Candy(selectedFlavor, selectedColor);
      cout << "Marvelous! Your candy was added to the order.\n";

      // Display the current order
      cout << "\nYour order:\n";
      for (int j = 0; j <= i; ++j)
      {
        cout << "#" << (j + 1) << " " << Candy::getColorString(candies[j]->getColor())
             << " " << Candy::getFlavorString(candies[j]->getFlavor()) << "\n";
      }
      cout << endl;
    }
  }
}
