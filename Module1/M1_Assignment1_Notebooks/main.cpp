/* Program name: notebook.cpp
 * Author: Younghyun Lee
 * Date Last updated: 8-25-24
 * Purpose: Make a class that describes a notebook
 */
#include <iostream>
#include <string>
#include "notebook.h"

// Generater and use class objects(class instances)

using namespace std;

int main()
{
  double w;
  double h;
  int p;
  string pt;
  string f;
  string pc;
  string ct;
  string cd;

  cout << "Enter the name of the cover color or design: ";
  getline(cin, cd);
  cout << "Enter the cover type: ";
  getline(cin, ct);
  cout << "Enter the paper color: ";
  getline(cin, pc);
  cout << "Enter the notebook format: ";
  getline(cin, f);
  cout << "Enter the type of paper: ";
  getline(cin, pt);
  cout << "Enter the number of pages: ";
  cin >> p;
  cout << "Enter the notebook height: ";
  cin >> h;
  cout << "Enter the notebook width: ";
  cin >> w;

  ClNotebook note(w, h, p, pt, f, pc, ct, cd);

  cout << note.toString() << endl;

  return 0;
}
