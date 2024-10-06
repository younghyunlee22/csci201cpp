/* Program name: main.cpp
 * Author: Younghyun Lee
 * Date last updated: 9/16/2024
 * Purpose: Order bags of candy
 */

#ifndef BAG_H
#define BAG_H

#include <string>
#include "candy.h"
using namespace std;

class Bag
{
private:
  Candy **candies;
  int numCandies;

public:
  Bag();
  Bag(const Bag &otherBag);
  ~Bag();
  bool duplicateCheck(int currentCount, Candy newCandy);
  string getCandyList();
  void copyBag(const Bag &otherBag);
  void fillBag();
};

#endif
