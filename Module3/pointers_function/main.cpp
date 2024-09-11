//
// Created by Younghyun Lee on 9/11/24.
//
#include <iostream>

using namespace std;

void pointerFunction (int*&, double*);

int main() {

    int a = 10;
    double b = 3.14;
    int *p = &a;
    double *q = &b;

    cout << "--------main--------" << endl;
    cout << "Before function call:" << endl;
    cout << "a: " << a << ", b: " << b << endl;
    cout << "p: " << p << " (points to a)\n";
    cout << "q: " << q << " (points to b)\n";

    pointerFunction(p, q);

    cout << "--------main--------" << endl;
    cout << "After function call:" << endl;
    cout << "a: " << a << ", b: " << b << endl;
    cout << "p: " << p << " (p memory address in main changed via pointerFunction)\n";
    cout << "q: " << q << " (q memory address didn't change in main)\n";

    return 0;
}

void pointerFunction (int *&p, double *q) {
    cout << "\n--------function--------" << endl;
    cout << "In function before modifying:" << endl;
    cout << "p (points to a): " << p << endl;
    cout << "q (points to b): " << q << endl;

    // p와 q가 가리키는 값을 변경
    *p = 99;
    *q = 99.99;

    // 포인터 자체를 변경
    int temp = 500;
    double temp2 = 600.0;
    p = &temp;  // p의 포인터를 다른 주소로 변경
    q = &temp2; // q의 포인터를 다른 주소로 변경

    cout << "In function after modifying:" << endl;
    cout << "p: " << p << " (now points to temp)\n";
    cout << "q: " << q << " (now points to temp2)\n";
    cout << "--------function ends--------\n\n";
}
