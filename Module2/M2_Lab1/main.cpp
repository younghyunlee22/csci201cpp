#include <iostream>
#include <string>
using namespace std;

// overload, polymorphism

// void phil(int i){
// };
// void phil(double d){
// };
// int main(int argc, char** argv) {
// int u;
// string r;
// cout << phil (4) << endl;
// cout << phil( 7.8) << endl;
// u = 4 + 3;
// r = "Hi " + "there";
// cout << u << "  " << r ;
// return 0;
// }

// Fix it so the function phil will square the number and return the result.  Then fix the + overload on the string so it works.

int phil(int i)
{
  return i * i;
};

double phil(double d)
{
  return d * d;
};

int main()
{
  int u;
  string r;
  cout << phil(4) << endl;
  cout << phil(7.8) << endl;
  u = 4 + 3;
  r = "Hi " + string("there");
  cout << u << "  " << r << endl;
  return 0;
}

// String literals are of const char* type. The + operator is not defined for const char* type.
// The std::string class has functionalities such as concatenating strings and calculating the size of a string.
// std::string can be used to convert const char* to std::string, allowing the + operator to concatenate the strings.
