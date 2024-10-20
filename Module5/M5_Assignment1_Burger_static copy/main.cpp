/* Program name: burger.cpp
* Author: Younghyun Lee
 * Date last updated: 9/27/2024
 * Purpose: Order customized burgers
 */
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "burger.h"

using namespace std;

// Function declarations
void toLowerCase(string& input);
void trim(string& input);
int getValidatedNumPatties();
ProteinType getValidatedProtein(bool isVeggie = false);
void getValidatedToppings(ToppingType toppings[], int& numToppings, bool isVeggie);
void getValidatedCondiments(CondimentType condiments[], int& numCondiments);
BunType getValidatedBun();
CheeseType getValidatedCheese();
int getValidatedMenuChoice();
char getYesOrNo(const string& errorMessage);

int main()
{
    vector<Burger> burgers;
    char anotherBurger = 'n';

    do
    {
        int numPatties = getValidatedNumPatties();

        ProteinType protein = getValidatedProtein();

        ToppingType toppings[7];
        int numToppings = 0;
        getValidatedToppings(toppings, numToppings, protein == MUSH || protein == VEGGIE);

        CondimentType condiments[7];
        int numCondiments = 0;
        getValidatedCondiments(condiments, numCondiments);

        BunType bun = getValidatedBun();

        CheeseType cheese = getValidatedCheese();

        Burger myBurger(protein, condiments, numCondiments, toppings, numToppings, bun, cheese, numPatties);
        cout << endl << myBurger.tostring() << endl;

        int menuChoice;
        do
        {
            menuChoice = getValidatedMenuChoice();

            switch (menuChoice)
            {
            case 1: // Change Protein
            {
                ProteinType newProtein = getValidatedProtein(myBurger.isVeggie());
                if (myBurger.isVeggie() && (newProtein != MUSH && newProtein != VEGGIE))
                {
                    cout << "Warning you are changing the burger from vegetarian to meat based. Do you want to continue?\n";
                    char choice = getYesOrNo("Error: Please enter Y or N to confirm a change to a non-vegetarian burger.\n");
                    if (choice == 'n')
                    {
                        break; // Do not change the protein
                    }
                }
                myBurger.setProtein(newProtein);
                break;
            }
            case 2: // Change Number of Patties
                numPatties = getValidatedNumPatties();
                myBurger.setNumPatties(numPatties);
                break;
            case 3: // Change Toppings
                getValidatedToppings(toppings, numToppings, myBurger.isVeggie());
                myBurger.setToppings(toppings, numToppings);
                break;
            case 4: // Change Cheese
                cheese = getValidatedCheese();
                myBurger.setCheese(cheese);
                break;
            case 5: // Change Bun
                bun = getValidatedBun();
                myBurger.setBun(bun);
                break;
            case 6: // Change Condiments
                getValidatedCondiments(condiments, numCondiments);
                myBurger.setCondiments(condiments, numCondiments);
                break;
            case 7:
                break;
            }
        } while (menuChoice != 7);

        cout << endl << myBurger.tostring() << endl;

        cout << "Do you want to enter another burger?\n";
        anotherBurger = getYesOrNo("Error: Please enter y or n.\n");

    } while (anotherBurger == 'y');

    return 0;
}

// Helper functions
void toLowerCase(string& input)
{
    transform(input.begin(), input.end(), input.begin(), ::tolower);
}

void trim(string& input)
{
    input.erase(0, input.find_first_not_of(' '));
    input.erase(input.find_last_not_of(' ') + 1);
}

int getValidatedNumPatties()
{
    int numPatties;
    bool valid = false;
    do
    {
        cout << "How many patties do you want on your burger? \n";
        cin >> numPatties;
        if (cin.fail() || numPatties <= 0)
        {
            cout << "You entered an invalid amount of patties. Please try again.\n" << endl;
            cin.clear();
            cin.ignore(1000, '\n');
            valid = false;
        }
        else
        {
            valid = true;
        }
    } while (!valid);
    cin.ignore(1000, '\n');
    return numPatties;
}

ProteinType getValidatedProtein(bool isVeggie)
{
    string input;
    ProteinType protein;
    bool valid = false;
    do
    {
        cout << "Please enter a protein.\n" << endl;
        getline(cin, input);
        toLowerCase(input);
        trim(input);
        if (Burger::stringToProteinType.find(input) != Burger::stringToProteinType.end())
        {
            protein = Burger::stringToProteinType[input];
            valid = true;
        }
        else
        {
            cout << "You have chosen an invalid protein type. Available protein types are: \n";
            for (const auto& pair : Burger::proteinTypeToString)
            {
                cout << pair.second;
                if (pair.first != VEGGIE)
                    cout << ", ";
            }
            cout << endl;
        }
    } while (!valid);
    return protein;
}

void getValidatedToppings(ToppingType toppings[], int& numToppings, bool isVeggie)
{
    numToppings = 0;
    string input;
    do
    {
        cout << "Please enter a topping. Enter -1 to move to the next step\n" << endl;
        getline(cin, input);
        toLowerCase(input);
        trim(input);
        if (input == "-1")
        {
            break;
        }
        else if (Burger::stringToToppingType.find(input) != Burger::stringToToppingType.end())
        {
            ToppingType topping = Burger::stringToToppingType[input];
            if (topping == BACON && isVeggie)
            {
                cout << "Warning you are changing the burger from vegetarian to meat based. Do you want to continue?\n";
                char choice = getYesOrNo("Error: Please enter y or n to confirm a change to a non-vegetarian burger.\n");
                if (choice == 'n')
                {
                    continue;
                }
            }
            toppings[numToppings++] = topping;
        }
        else
        {
            cout << "You did not choose a valid topping. Enter one of the following toppings:\n";
            for (const auto& pair : Burger::toppingTypeToString)
            {
                cout << pair.second;
                if (pair.first != NOTOP)
                    cout << ", ";
            }
            cout << endl;
        }
    } while (numToppings < 7);
}

void getValidatedCondiments(CondimentType condiments[], int& numCondiments)
{
    numCondiments = 0;
    string input;
    do
    {
        cout << "Please enter a Condiment. Enter -1 to move to the next step\n" << endl;
        getline(cin, input);
        toLowerCase(input);
        trim(input);
        if (input == "-1")
        {
            break;
        }
        else if (Burger::stringToCondimentType.find(input) != Burger::stringToCondimentType.end())
        {
            CondimentType condiment = Burger::stringToCondimentType[input];
            condiments[numCondiments++] = condiment;
        }
        else
        {
            cout << "You did not choose a valid condiment. Enter one of the following condiments:\n";
            for (const auto& pair : Burger::condimentTypeToString)
            {
                cout << pair.second;
                if (pair.first != NOCOND)
                    cout << ", ";
            }
            cout << endl;
        }
    } while (numCondiments < 7);
}

BunType getValidatedBun()
{
    string input;
    BunType bun;
    bool valid = false;
    do
    {
        cout << "Please enter a bun.\n" << endl;
        getline(cin, input);
        toLowerCase(input);
        trim(input);
        if (Burger::stringToBunType.find(input) != Burger::stringToBunType.end())
        {
            bun = Burger::stringToBunType[input];
            valid = true;
        }
        else
        {
            cout << "You have chosen an invalid bun type. Available bun types are: \n";
            for (const auto& pair : Burger::bunTypeToString)
            {
                cout << pair.second;
                if (pair.first != GLUTENFREE)
                    cout << ", ";
            }
            cout << endl;
        }
    } while (!valid);
    return bun;
}

CheeseType getValidatedCheese()
{
    string input;
    CheeseType cheese;
    bool valid = false;
    do
    {
        cout << "Please enter a cheese.\n" << endl;
        getline(cin, input);
        toLowerCase(input);
        trim(input);
        if (Burger::stringToCheeseType.find(input) != Burger::stringToCheeseType.end())
        {
            cheese = Burger::stringToCheeseType[input];
            valid = true;
        }
        else
        {
            cout << "You have chosen an invalid cheese type. Available cheese types are: \n";
            for (const auto& pair : Burger::cheeseTypeToString)
            {
                cout << pair.second;
                if (pair.first != NOCHEESE)
                    cout << ", ";
            }
            cout << endl;
        }
    } while (!valid);
    return cheese;
}

int getValidatedMenuChoice()
{
    int choice;
    bool valid = false;
    do
    {
        cout << "Would you like to change the burger? Please choose from the menu.\n";
        cout << "1. Change Protein\n";
        cout << "2. Change Number of Patties\n";
        cout << "3. Change Toppings\n";
        cout << "4. Change Cheese\n";
        cout << "5. Change Bun\n";
        cout << "6. Change Condiments\n";
        cout << "7. No Changes\n";
        cout << endl;

        cin >> choice;
        if (cin.fail() || choice < 1 || choice > 7)
        {
            cout << "You have entered an invalid choice. Please try again.\n";
            cin.clear();
            cin.ignore(1000, '\n');
            valid = false;
        }
        else
        {
            valid = true;
        }
    } while (!valid);
    cin.ignore(1000, '\n');
    return choice;
}

char getYesOrNo(const string& errorMessage)
{
    string input;
    char choice;
    bool valid = false;
    do
    {
        getline(cin, input);
        if (input.empty())
        {
            cout << errorMessage;
            continue;
        }
        choice = tolower(input[0]);
        if (choice == 'y' || choice == 'n')
        {
            valid = true;
        }
        else
        {
            cout << errorMessage;
        }
    } while (!valid);
    return choice;
}
