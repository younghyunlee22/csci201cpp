/* Program name: burger.cpp
* Author: Younghyun Lee
 * Date last updated: 9/27/2024
 * Purpose: Order customized burgers
 */
#include <iostream>
#include <string>
#include "burger.h"

using namespace std;

// Initialize static maps
map<ProteinType, string> Burger::proteinTypeToString = {
    {BEEF, "Beef"},
    {TURKEY, "Turkey"},
    {CHICKEN, "Chicken Breast"},
    {MUSH, "Portabella Mushroom"},
    {VEGGIE, "Veggie"}
};

map<string, ProteinType> Burger::stringToProteinType = {
    {"beef", BEEF},
    {"turkey", TURKEY},
    {"chicken breast", CHICKEN},
    {"chicken", CHICKEN},
    {"portabella mushroom", MUSH},
    {"portabella", MUSH},
    {"mushroom", MUSH},
    {"mush", MUSH},
    {"veggie", VEGGIE}
};

map<ToppingType, string> Burger::toppingTypeToString = {
    {GRILLONION, "Grilled Onion"},
    {RAWONION, "Raw Onion"},
    {TOMATO, "Tomato"},
    {LETTUCE, "Lettuce"},
    {BACON, "Bacon"},
    {MUSHROOM, "Grilled Mushroom"},
    {PICKLE, "Pickle"},
    {NOTOP, "None"}
};

map<string, ToppingType> Burger::stringToToppingType = {
    {"grilled onion", GRILLONION},
    {"raw onion", RAWONION},
    {"tomato", TOMATO},
    {"lettuce", LETTUCE},
    {"bacon", BACON},
    {"grilled mushroom", MUSHROOM},
    {"mushroom", MUSHROOM},
    {"pickle", PICKLE},
    {"none", NOTOP}
};

map<CondimentType, string> Burger::condimentTypeToString = {
    {KETCHUP, "Ketchup"},
    {MUSTARD, "Mustard"},
    {MAYO, "Mayonnaise"},
    {SPECIAL, "Special Sauce"},
    {BBQ, "BBQ Sauce"},
    {STEAK, "Steak Sauce"},
    {PEPPERCORN, "Peppercorn Ranch"},
    {NOCOND, "None"}
};

map<string, CondimentType> Burger::stringToCondimentType = {
    {"ketchup", KETCHUP},
    {"mustard", MUSTARD},
    {"mayonnaise", MAYO},
    {"mayo", MAYO},
    {"special sauce", SPECIAL},
    {"bbq sauce", BBQ},
    {"bbq", BBQ},
    {"steak sauce", STEAK},
    {"steak", STEAK},
    {"peppercorn ranch", PEPPERCORN},
    {"peppercorn", PEPPERCORN},
    {"none", NOCOND}
};

map<BunType, string> Burger::bunTypeToString = {
    {BRIOCHE, "Brioche"},
    {WHEAT, "Wheat"},
    {SESAME, "Sesame"},
    {ONION, "Onion"},
    {RYE, "Rye Bread"},
    {NOBUN, "None"},
    {GLUTENFREE, "Gluten Free"}
};

map<string, BunType> Burger::stringToBunType = {
    {"brioche", BRIOCHE},
    {"wheat", WHEAT},
    {"sesame", SESAME},
    {"onion", ONION},
    {"rye bread", RYE},
    {"rye", RYE},
    {"none", NOBUN},
    {"gluten free", GLUTENFREE}
};

map<CheeseType, string> Burger::cheeseTypeToString = {
    {CHEDDAR, "Cheddar"},
    {AMERICAN, "American"},
    {PEPPERJACK, "Pepper Jack"},
    {SWISS, "Swiss"},
    {COLBYJACK, "Colby Jack"},
    {NOCHEESE, "None"}
};

map<string, CheeseType> Burger::stringToCheeseType = {
    {"cheddar", CHEDDAR},
    {"american", AMERICAN},
    {"pepper jack", PEPPERJACK},
    {"pepperjack", PEPPERJACK},
    {"swiss", SWISS},
    {"colby jack", COLBYJACK},
    {"colbyjack", COLBYJACK},
    {"none", NOCHEESE}
};

// Constructor
Burger::Burger(ProteinType proteinT, CondimentType condimentT[], int numC,
               ToppingType toppingT[], int numT, BunType bunT, CheeseType cheeseT, int numP)
{
    setProtein(proteinT);
    setCondiments(condimentT, numC);
    setToppings(toppingT, numT);
    setBun(bunT);
    setCheese(cheeseT);
    setNumPatties(numP);
}

// Destructor
Burger::~Burger() {}

// Accessors
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

double Burger::getPrice() const
{
    double price = 0;
    switch (protein)
    {
    case BEEF:
        price += 2.50 * numPatties;
        break;
    case CHICKEN:
        price += 2.00 * numPatties;
        break;
    case MUSH:
        price += 1.50 * numPatties;
        break;
    case TURKEY:
        price += 2.25 * numPatties;
        break;
    case VEGGIE:
        price += 2.00 * numPatties;
        break;
    }
    price += numToppings * 0.50;
    price += numCondiments * 0.25;
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
    if (numCondiments == 0)
        return "None";

    string condimentList = "";
    for (int i = 0; i < numCondiments; i++)
    {
        condimentList += condimentTypeToString[condiments[i]];
        if (i != numCondiments - 1)
        {
            condimentList += ", ";
        }
    }
    return condimentList;
}

string Burger::getToppings() const
{
    if (numToppings == 0)
        return "None";

    string toppingList = "";
    for (int i = 0; i < numToppings; i++)
    {
        toppingList += toppingTypeToString[toppings[i]];
        if (i != numToppings - 1)
        {
            toppingList += ", ";
        }
    }
    return toppingList;
}

string Burger::tostring() const
{
    string burgerString = "Protein: " + proteinTypeToString[protein] + "\n";
    burgerString += "Number of patties: " + to_string(numPatties) + "\n";
    burgerString += "Bun Type: " + bunTypeToString[bunType] + "\n";
    burgerString += "Cheese: " + cheeseTypeToString[cheese] + "\n";
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

