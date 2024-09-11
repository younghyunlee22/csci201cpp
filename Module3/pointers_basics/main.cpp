//
// Created by Younghyun Lee on 9/11/24.
//
#include <iostream>

using namespace std;

int main() {

    int x = 1;
    int *xptr;
    xptr = &x;

    cout << "x: " << x << ", y: (not yet declared), *xptr: " << *xptr << ", *yptr: (not yet declared), xptr: " << xptr << ", yptr: (not yet declared)" << endl;

    int y = 2;
    int *yptr = &y;

    cout << "x: " << x << ", y: " << y << ", *xptr: " << *xptr << ", *yptr: " << *yptr << ", xptr: " << xptr << ", yptr: " << yptr << endl;

    x = y;
    cout << "x: " << x << ", y: " << y << ", *xptr: " << *xptr << ", *yptr: " << *yptr << ", xptr: " << xptr << ", yptr: " << yptr << endl;

    x = 3;
    y = 4;
    cout << "x: " << x << ", y: " << y << ", *xptr: " << *xptr << ", *yptr: " << *yptr << ", xptr: " << xptr << ", yptr: " << yptr << endl;

    *xptr = *yptr;
    cout << "x: " << x << ", y: " << y << ", *xptr: " << *xptr << ", *yptr: " << *yptr << ", xptr: " << xptr << ", yptr: " << yptr << endl;

    x = 5;
    y = 6;

    xptr = yptr;
    cout << "x: " << x << ", y: " << y << ", *xptr: " << *xptr << ", *yptr: " << *yptr << ", xptr: " << xptr << ", yptr: " << yptr << endl;

    *xptr = 7;
    cout << "x: " << x << ", y: " << y << ", *xptr: " << *xptr << ", *yptr: " << *yptr << ", xptr: " << xptr << ", yptr: " << yptr << endl;

    return 0;
}

