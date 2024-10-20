//
// Created by Younghyun Lee on 9/23/24.
//
#include <iostream>
#include "date.h"

int main(int argc, char const *argv[])
{
  for (int i = 0; i < 10; i++)
  {

    date before(2, 28, 1900 + i);
    date after = 1 + before;
    std::cout << "day " << after.getDay() << " month " << after.getMonth() << " year " << after.getYear() << std::endl;
  }

  return 0;
}
