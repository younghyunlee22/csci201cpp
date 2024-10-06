/* Program name: character.cpp
* Author: Younghyun Lee
 * Date last updated: 9/21/2024
 * Purpose: Make RPG character base class(Include virtual functions and pointers)
 */

#ifndef CHARACTER_H
#define CHARACTER_H
#include <string>
using namespace std;

enum characterType {
  FIGHTER = 1,
  ROGUE,
  MAGICIAN,
  CLERIC
};

// base class
class Character
{
public:
  // Constructor
  Character(string nameParam, double hpParam, double mpParam, int strengthP, int dexterityP, int intelligenceP, int speedP, int enduranceP, int faithP);
  // Destructor
  virtual ~Character();

  // Accessors
  double getHp() const;
  double getMp() const;
  int getDexterity() const;
  int getEndurance() const;
  int getFaith() const;
  int getIntelligence() const;
  int getSpeed() const;
  int getStrength() const;
  string getName() const;

  // Mutators
  void setDexterity(int dexterity);
  void setEndurance(int endurance);
  void setFaith(int faith);
  void setHp(double hpParam);
  void setIntelligence(int intelligence);
  void setMp(double mpParam);
  void setSpeed(int speed);
  void setStrength(int strength);

  // Other
  double attack();
  virtual string tostring();

protected:
  double hp;
  double mp;
  int dexterity;
  int endurance;
  int faith;
  int intelligence;
  int speed;
  int strength;
  string name;
};

// Derived classes
class Fighter : public Character
{
public:
  Fighter(string nameParam);
  ~Fighter();
  double strongAttack(Character &other);
  string tostring();
};

class Rogue : public Character
{
public:
  Rogue(string nameParam);
  ~Rogue();
  double steal(Character &other);
  string tostring();
};

class Magician : public Character
{
public:
  Magician(string nameParam);
  ~Magician();
  double cast(Character &other);
  string tostring();
};

class Cleric : public Character
{
public:
  Cleric(string nameParam);
  ~Cleric();
  double heal(Character &other);
  string tostring();
};

#endif
