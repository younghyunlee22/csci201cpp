#include "common.h"

void showPromptNumP()
{
  cout << "How many patties do you want on your burger? ";
  cout << endl;
}

void showProteinList()
{
  cout << "Please choose a protein from the list." << endl;
  cout << "1: Beef" << endl;
  cout << "2: Turkey" << endl;
  cout << "3: Chicken Breast" << endl;
  cout << "4: Portabella Mushroom" << endl;
  cout << "5: Veggie" << endl;
}

void showTopplingList()
{
  cout << "Please choose a topping from the list. Enter -1 to stop adding toppings." << endl;
  cout << "1: Grilled Onion" << endl;
  cout << "2: Raw Onion" << endl;
  cout << "3: Tomato" << endl;
  cout << "4: Lettuce" << endl;
  cout << "5: Bacon" << endl;
  cout << "6: Grilled Mushroom" << endl;
  cout << "7: Pickle" << endl;
  cout << "8: None" << endl;
}

void showCondimentList()
{
  cout << "Please choose a condiment from the list. Enter -1 to stop adding condiments." << endl;
  cout << "1: Ketchup" << endl;
  cout << "2: Mustard" << endl;
  cout << "3: Mayonnaise" << endl;
  cout << "4: Special Sauce" << endl;
  cout << "5: BBQ Sauce" << endl;
  cout << "6: Steak Sauce" << endl;
  cout << "7: Peppercorn Ranch" << endl;
  cout << "8: None" << endl;
}

void showBunList()
{
  cout << "Please choose a bun from the list." << endl;
  cout << "1: Brioche" << endl;
  cout << "2: Wheat" << endl;
  cout << "3: Seasme" << endl;
  cout << "4: Onion" << endl;
  cout << "5: Rye Bread" << endl;
  cout << "6: None" << endl;
  cout << "7: Gluten Free" << endl;
}

void showCheeseList()
{
  cout << "Please choose a cheese from the list." << endl;
  cout << "1: Cheddar" << endl;
  cout << "2: American" << endl;
  cout << "3: Pepper Jack" << endl;
  cout << "4: Swiss" << endl;
  cout << "5: Colby Jack" << endl;
  cout << "6: None" << endl;
}

void showBurgerChangeMenu()
{
  cout << "Would you like to change the burger? Please choose from the menu." << endl;
  cout << "1. Change Protein" << endl;
  cout << "2. Change Number of Patties" << endl;
  cout << "3. Change Toppings" << endl;
  cout << "4. Change Cheese" << endl;
  cout << "5. Change Bun" << endl;
  cout << "6. Change Condiments" << endl;
  cout << "7. No Changes" << endl;
}

void showWarning()
{
  cout << "Warning you are changing the burger from vegetarian to meat based. Do you want to continue?";
}

int getUserChoiceInt()
{
  int choice;
  cin >> choice;
  return choice;
}

char getUserChoiceChar()
{
  char choice;
  cin >> choice;
  return tolower(choice);
}

string getBunTypeName(BunType bunT)
{
  switch (bunT)
  {
  case BRIOCHE:
    return "Brioche";
  case ONION:
    return "Onion";
  case RYE:
    return "Rye Bread";
  case SESAME:
    return "Sesame";
  case WHEAT:
    return "Wheat";
  case NOBUN:
    return "None";
  case GLUTENFREE:
    return "Gluten Free";
  }
  return "UNKNOWN";
}

string getCheeseTypeName(CheeseType cheeseT)
{
  switch (cheeseT)
  {
  case AMERICAN:
    return "American";
  case CHEDDAR:
    return "Cheddar";
  case COLBYJACK:
    return "Colby Jack";
  case PEPPERJACK:
    return "Pepper Jack";
  case SWISS:
    return "Swiss";
  case NOCHEESE:
    return "None";
  }
  return "UNKNOWN";
}

string getCondimentTypeName(CondimentType condimentT)
{
  switch (condimentT)
  {
  case BBQ:
    return "BBQ Sauce";
  case KETCHUP:
    return "Ketchup";
  case MAYO:
    return "Mayonnaise";
  case MUSTARD:
    return "Mustard";
  case PEPPERCORN:
    return "Peppercorn Ranch";
  case SPECIAL:
    return "Special Sauce";
  case STEAK:
    return "Steak Sauce";
  case NOCOND:
    return "None";
  }
  return "UNKNOWN";
}

string getProteinTypeName(ProteinType proteinT)
{
  switch (proteinT)
  {
  case BEEF:
    return "Beef";
  case CHICKEN:
    return "Chicken Breast";
  case MUSH:
    return "Portabella Mushroom";
  case TURKEY:
    return "Turkey";
  case VEGGIE:
    return "Veggie";
  }
  return "UNKNOWN";
}

string getToppingTypeName(ToppingType toppingT)
{
  switch (toppingT)
  {
  case BACON:
    return "Bacon";
  case GRILLONION:
    return "Grilled Onion";
  case LETTUCE:
    return "Lettuce";
  case MUSHROOM:
    return "Grilled Mushroom";
  case PICKLE:
    return "Pickle";
  case RAWONION:
    return "Raw Onion";
  case TOMATO:
    return "Tomato";
  case NOTOP:
    return "None";
  }
  return "UNKNOWN";
}
