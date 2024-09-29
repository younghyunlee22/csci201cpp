/* Program name: character.cpp
 * Author: Younghyun Lee
 * Date last updated: 9/1/2024
 * Purpose: Make RPG character base class and derived classes
 */

#ifndef CHARACTER_CPP
#define CHARACTER_CPP

#include <string>
#include <iostream>
#include <cstdlib>
#include "character.h"

using namespace std;

// base class
Character::Character(string nameParam, double hpParam, double mpParam, int strengthP, int dexterityP, int intelligenceP, int speedP, int enduranceP, int faithP)
{
  name = nameParam;
  setDexterity(dexterityP);
  setEndurance(enduranceP);
  setFaith(faithP);
  setHp(hpParam);
  setIntelligence(intelligenceP);
  setMp(mpParam);
  setSpeed(speedP);
  setStrength(strengthP);
}

Character::~Character() {}

double Character::getHp() const
{
  return hp;
}

double Character::getMp() const
{
  return mp;
}

int Character::getDexterity() const
{
  return dexterity;
}

int Character::getEndurance() const
{
  return endurance;
}

int Character::getFaith() const
{
  return faith;
}

int Character::getIntelligence() const
{
  return intelligence;
}

int Character::getSpeed() const
{
  return speed;
}

int Character::getStrength() const
{
  return strength;
}

string Character::getName() const
{
  return name;
}

void Character::setDexterity(int dexterityP)
{
  dexterity = dexterityP;
}

void Character::setEndurance(int enduranceP)
{
  endurance = enduranceP;
}

void Character::setFaith(int faithP)
{
  faith = faithP;
}

void Character::setHp(double hpParam)
{
  hp = hpParam;
}

void Character::setIntelligence(int intelligenceP)
{
  intelligence = intelligenceP;
}

void Character::setMp(double mpParam)
{
  mp = mpParam;
}

void Character::setSpeed(int speedP)
{
  speed = speedP;
}

void Character::setStrength(int strengthP)
{
  strength = strengthP;
}

double Character::attack()
{
  // amount of damage == character's strength stat
  return strength;
}

string Character::tostring()
{
  string result = "";

  result += getName() + " stats:\n";
  result += "HP: " + to_string(getHp()) + "\n";
  result += "MP: " + to_string(getMp()) + "\n";
  result += "Strength: " + to_string(getStrength()) + "\n";
  result += "Dexterity: " + to_string(getDexterity()) + "\n";
  result += "Intelligence: " + to_string(getIntelligence()) + "\n";
  result += "Speed: " + to_string(getSpeed()) + "\n";
  result += "Endurance: " + to_string(getEndurance()) + "\n";
  result += "Faith: " + to_string(getFaith()) + "\n";

  return result;
}

// Derived classes
Fighter::Fighter(string nameParam)
    : Character(nameParam, 300.00, 0.00, 16, 10, 5, 8, 15, 5)
{
}

Fighter::~Fighter() {}

double Fighter::strongAttack(Character &other)
{
  double damageAmount = strength + endurance;

  other.setHp(other.getHp() - damageAmount);
  return damageAmount;
}

Rogue::Rogue(string nameParam)
    : Character(nameParam, 200.00, 0.00, 10, 16, 16, 15, 8, 5)
{
}

Rogue::~Rogue() {}

double Rogue::steal(Character &other)
{
  double statSum = (dexterity + speed + intelligence);
  int randPrcnt = rand() % 41 + 10;
  double percentage = randPrcnt / 100.0;

  // double percentage = 0.15; for sample output

  double amountToSteal = statSum * percentage;

  other.setHp(other.getHp() - amountToSteal);
  setHp(getHp() + amountToSteal);

  return amountToSteal;
}

Magician::Magician(string nameParam)
    : Character(nameParam, 250.00, 200.00, 5, 10, 16, 16, 5, 8)
{
}

Magician::~Magician() {}

double Magician::cast(Character &other)
{
  double damageAmount = intelligence + speed;

  // if magician has enough MP to cast
  if (getMp() >= damageAmount)
  {
    other.setHp(other.getHp() - damageAmount);
    setMp(getMp() - damageAmount);
    return damageAmount;
  }
  else
  {
    return 0;
  }
}

Cleric::Cleric(string nameParam)
    : Character(nameParam, 200.00, 200.00, 5, 10, 8, 16, 5, 16)
{
}

Cleric::~Cleric() {}

double Cleric::heal(Character &other)
{
  // if cleric has enough MP to heal
  if (getMp() >= getFaith())
  {
    other.setHp(other.getHp() + faith);
    setMp(mp - faith);
    return faith;
  }
  else
  {
    return 0;
  }
}

#endif
