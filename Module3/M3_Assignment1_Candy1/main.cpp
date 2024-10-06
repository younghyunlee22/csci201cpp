/* Program name: main.cpp
 * Author: Younghyun Lee
 * Date last updated: 9/14/2024
 * Purpose: Order custom candy
 */
#include <iostream>
#include <iomanip>
#include <limits>
#include "candy.h"
using namespace std;

// Function prototypes
void intro();
void resetStream();
bool isUniqueCombination(Candy **candies, int currentCount, flavorType flavor, colorType color);

// Functions
void intro()
{
  cout << setfill('=') << setw(90) << " " << endl;
  cout << setfill(' ') << setw(60) << "Welcome to The Cavity Factory!" << endl;
  cout << setfill('=') << setw(90) << " " << endl;

  cout << "\n- We allow our beloved Candy Connoisseurs (yes, that'd be you) to build their own candy!" << endl;
  cout << "There's only one catch: To ensure that our customers explore their palate,\n"
       << "we only allow unique candy to be ordered. Don't think of it as a limitation, but as an EXPERIENCE!\n\n"
       << endl;
}

void resetStream()
{
  cin.clear();
  cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

// Function to check if a candy combination is unique
bool isUniqueCombination(Candy **candies, int currentCount, flavorType flavor, colorType color)
{
  for (int i = 0; i < currentCount; i++)
  {
    if (candies[i]->getFlavor() == flavor && candies[i]->getColor() == color)
    {
      return false;
    }
  }
  return true;
}

int main()
{
  int candyCount;
  const int MAX_CANDIES = 25;

  intro();

  cout << "How many candies will you be ordering today? (range: 1-" << MAX_CANDIES << ")\n";
  cin >> candyCount;

  // Input Validation
  while (!cin || candyCount < 1 || candyCount > MAX_CANDIES)
  {
    if (!cin)
    {
      resetStream();
      cout << "That's not a number." << endl;
    }

    cout << "Invalid entry. Number must be between 1 and " << MAX_CANDIES << " inclusive. Try again." << endl;
    cin >> candyCount;
  }

  // Dynamically allocate array of Candy pointers
  Candy **candies = new Candy *[candyCount];
  int currentCount = 0;

  // Candy creation loop
  for (int i = 0; i < candyCount; i++)
  {
    flavorType selectedFlavor;
    colorType selectedColor;

    // Flag
    bool unique = false;

    // Loop until a unique flavor and color combination is selected
    while (!unique)
    {
      // Flavor selection
      cout << "Candy #" << (i + 1) << " of " << candyCount << "\n";
      cout << "Choose a flavor you would like:\n";
      cout << "[1] Cotton Candy\n[2] Watermelon Burst\n[3] Papaya Bliss\n[4] Citrus Splash\n[5] Cola\n";
      int flavorChoice;
      cin >> flavorChoice;

      // Input Validation
      while (!cin || flavorChoice < 1 || flavorChoice > 5)
      {
        if (!cin)
        {
          resetStream();
          cout << "That's not a number." << endl;
        }
        cout << "Invalid entry. Number must be between 1 and 5 inclusive. Try again." << endl;
        cin >> flavorChoice;
      }

      selectedFlavor = static_cast<flavorType>(flavorChoice);
      cout << Candy::getFlavorString(selectedFlavor) << "? Great choice.\n\n";

      // Color selection
      cout << "Choose a color for your " << Candy::getFlavorString(selectedFlavor) << " candy:\n";
      cout << "[1] Scarlet Blaze\n[2] Azure Sky\n[3] Emerald Mist\n[4] Goldenrod Glow\n[5] Amethyst Haze\n";
      int colorChoice;
      cin >> colorChoice;

      // Input Validation
      while (!cin || colorChoice < 1 || colorChoice > 5)
      {
        if (!cin)
        {
          resetStream();
          cout << "That's not a number." << endl;
        }
        cout << "Invalid entry. Number must be between 1 and 5 inclusive. Try again." << endl;
        cin >> colorChoice;
      }

      selectedColor = static_cast<colorType>(colorChoice);
      cout << Candy::getColorString(selectedColor) << " " << Candy::getFlavorString(selectedFlavor) << " it is!\n";

      // Check for unique combination
      if (!isUniqueCombination(candies, currentCount, selectedFlavor, selectedColor))
      {
        cout << "But wait, this is not unique, try again.\n";

        // Print current order so far
        cout << "Your order:\n";
        for (int j = 0; j < currentCount; j++)
        {
          cout << "#" << (j + 1) << " " << Candy::getColorString(candies[j]->getColor()) << " "
               << Candy::getFlavorString(candies[j]->getFlavor()) << "\n";
        }
        cout << "\n";
        continue;
      }

      // Add candy to the array
      candies[currentCount++] = new Candy(selectedFlavor, selectedColor);
      cout << "Marvelous! Your candy was added to the order.\n\n";

      // Print current order
      cout << "Your order:\n";
      for (int j = 0; j < currentCount; j++)
      {
        cout << "#" << (j + 1) << " " << Candy::getColorString(candies[j]->getColor()) << " "
             << Candy::getFlavorString(candies[j]->getFlavor()) << "\n";
      }
      cout << "\n";
      unique = true; // Exit loop
    }
  }

  // Delete dynamically allocated memory
  for (int i = 0; i < candyCount; i++)
  {
    delete candies[i];
  }
  delete[] candies;

  cout << "Thank you for choosing The Cavity Factory, where tooth decay is our priority!\n";
  return 0;
}
