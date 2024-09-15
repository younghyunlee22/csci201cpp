/* Program name: notebook.cpp
 * Author: Younghyun Lee
 * Date Last updated: 8-25-24
 * Purpose: Make a class that describes a notebook
 */

#include "notebook.h"

// class definition
// function definition (define the member functions)
// Class functions are implemented here

#include <string>

using namespace std;

// Constructor (same name as the class name)
// Classname::ConstructorName(Formal Parameter List) {Constructor Body}

ClNotebook::ClNotebook(double w, double h, int p, string pt, string f, string pc, string ct, string cd)
{
  setHeight(h);
  setWidth(w);
  setPages(p);
  setPaperType(pt);
  setFormat(f);
  setPaperColor(pc);
  setCoverType(ct);
  setCoverDesign(cd);
}

double ClNotebook::getHeight() const
{
  return height;
}

double ClNotebook::getWidth() const
{
  return width;
}

int ClNotebook::getPages() const
{
  return pages;
}

string ClNotebook::getCoverDesign() const
{
  return coverDesign;
}

string ClNotebook::getCoverType() const
{
  return coverType;
}

string ClNotebook::getFormat() const
{
  return format;
}

string ClNotebook::getPaperColor() const
{
  return paperColor;
}

string ClNotebook::getPaperType() const
{
  return paperType;
}

string ClNotebook::toString() const
{
  return "Here is your notebook:\nDimensions: " + to_string(width) + "x" + to_string(height) + "\nNumber of Pages: " + to_string(pages) + "\nPaper Type: " + paperType + "\nPaper Color: " + paperColor + "\nPage Format: " + format + "\nCover Type: " + coverType + "\nCover Design: " + coverDesign;
}

void ClNotebook::setCoverDesign(string cd)
{
  coverDesign = cd;
}

void ClNotebook::setCoverType(string ct)
{
  coverType = ct;
}

void ClNotebook::setFormat(string f)
{
  format = f;
}

void ClNotebook::setHeight(double h)
{
  height = h;
}

void ClNotebook::setPages(int p)
{
  pages = p;
}

void ClNotebook::setPaperColor(string pc)
{
  paperColor = pc;
}

void ClNotebook::setPaperType(string pt)
{
  paperType = pt;
}

void ClNotebook::setWidth(double w)
{
  width = w;
}

// Destructor (same name as the class name with a tilde sign)

ClNotebook::~ClNotebook()
{
}
