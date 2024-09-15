/* Program name: notebook.cpp
 * Author: Younghyun Lee
 * Date Last updated: 8-25-24
 * Purpose: Make a class that describes a notebook
 */

#ifndef NOTEBOOK_H // if not defined (true if not defined yet)
#define NOTEBOOK_H // then define

#include <string>

using namespace std;

// class declaration
// function prototype for member functions (instead of function definitions to hide information)

class ClNotebook
{
public:
  // Constructor
  ClNotebook(double w, double h, int p, string pt, string f, string pc, string ct, string cd);
  // Destructor
  ~ClNotebook();

  double getHeight() const;
  double getWidth() const;
  int getPages() const;
  string getCoverDesign() const;
  string getCoverType() const;
  string getFormat() const;
  string getPaperColor() const;
  string getPaperType() const;
  string toString() const;

  void setCoverDesign(string cd);
  void setCoverType(string ct);
  void setFormat(string f);
  void setHeight(double h);
  void setPages(int p);
  void setPaperColor(string pc);
  void setPaperType(string pt);
  void setWidth(double w);

private:
  double height;
  double width;
  int pages;
  string coverDesign;
  string coverType;
  string format;
  string paperColor;
  string paperType;
};

#endif
