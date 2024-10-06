/* Program name: character.cpp
 * Author: Younghyun Lee
 * Date last updated: 9/21/2024
 * Purpose: Make RPG character base class(Include virtual functions and pointers)
 */

#include <iostream>
#include <string>
#include <limits>
#include "character.h"

using namespace std;

int main()
{
  // initialize variables
    int numCharacters;
    string chaName;
    int chaChoice;

    cout << "How many characters do you want to create?\n";
    cin >> numCharacters;
    while (!cin || numCharacters < 1)
    {
        if (!cin)
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "That's not a number." << endl;
        }
        cout << "Invalid entry. Number must be greater than 0. Try again.\n";
        cin >> numCharacters;
    }
    // Clear the input buffer
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    // Allocate memory for the party
    Character **party = new Character *[numCharacters];

    // Create each character
    for (int i = 0; i < numCharacters; i++)
    {
        cout << "What is the name for character #" << i + 1 << "?\n ";
        getline(cin, chaName);
        while (!cin) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "That's not a string." << endl;
            getline(cin, chaName);
        }

        cout << "What character class do you want " << chaName << " to be?\n";
        cout << "1. Fighter Class\n";
        cout << "2. Rogue Class\n";
        cout << "3. Magician Class\n";
        cout << "4. Cleric Class\n";
        cin >> chaChoice;
        while (!cin || chaChoice < 1 || chaChoice > 4)
        {
            if (!cin)
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            cout << "That is not a valid choice. Please choose the class by number from the list.\n";
            cin >> chaChoice;
        }
        // Clear the input buffer for next loop iteration
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        // create object based on user input
        switch(chaChoice) {
            case FIGHTER:
                party[i] = new Fighter(chaName);
                break;
            case ROGUE:
                party[i] = new Rogue(chaName);
                break;
            case MAGICIAN:
                party[i] = new Magician(chaName);
                break;
            case CLERIC:
                party[i] = new Cleric(chaName);
                break;
            default:
                break;
        }

    }

    // Output the created party
    cout << "\nYour Party:\n";
    for (int i = 0; i < numCharacters; i++)
    {
        cout << party[i]->tostring() << endl;
    }

    // Deallocate memory
    for (int i = 0; i < numCharacters; i++)
    {
        delete party[i];
    }
    delete[] party;

    return 0;
}
