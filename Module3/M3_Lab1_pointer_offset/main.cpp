//
// Created by Younghyun Lee on 9/9/24.
//
#include <iostream>

using namespace std;

int main() {

    int h = 7;
    int *hptr;
    // the system gaves *hptr a zero and when I try to print it, it won't show anything.

    int x = 1;

    int *xptr;
    // xptr is not initialized and might have a garbage value
    xptr = &x;
    // xptr is now pointing to the address of x
    cout << "x value: " << x << ", x pointer address: " << xptr << endl;

    int y = 3;
    int *yptr = &y;
    // declare and initialize yptr at the same time
    cout << "y value: " << y << ", y pointer address: " << yptr << endl;

    int z = 5;
    int *zptr = nullptr;
    // or we can initialize it to nullptr
    zptr = &z;
    cout << "z value: " << z << ", z pointer address: " << zptr << endl;

    // adding 1 to a pointer offsets it by the datatype pointed to, and not 1
    int *offsetYptr = yptr + 1;
    cout << "yptr + 1: " << offsetYptr << endl;

    int arr[5] = {1, 2, 3, 4, 5};
    int *appPtr = arr;
    cout << *(appPtr + 2) << endl;

    return 0;
}
