/* Program name: main.cpp
* Author: Younghyun Lee
* Date last updated: 10/2/2024
* Purpose: Create Date class
*/
#include <iostream>
#include "date.h"
#include "dateExcept.h"

using namespace std;

int main() {

    // Test if the exception classes are working properly
    try {
        date leapYr(2, 29, 2024);     // this won't throw an exception
        cout << "day " << leapYr.getDay() << " month " << leapYr.getMonth() << " year " << leapYr.getYear() << endl;
        date nonLeapYr(2, 29, 2023);  // this will throw an exception
        cout << "day " << nonLeapYr.getDay() << " month " << nonLeapYr.getMonth() << " year " << nonLeapYr.getYear() << endl;
    }
    catch (invalid_day& e) {
        cout << e.what() << endl;
    }
    catch (invalid_month& e) {
        cout << e.what() << endl;
    }
    catch (invalid_year& e) {
        cout << e.what() << endl;
    }

    // Test if the overloaded operator >> throws an exception properly
    date myDate(1, 1, 2024);  // January 1, 2024
    cout << "Current date: " << myDate << endl;

    cout << "Enter a new date (month day year): ";

    try {
        cin >> myDate;
        cout << "You entered: " << myDate << endl;
    }
    catch (const invalid_day& e) {
        cout << "Caught an exception: " << e.what() << endl;
    }
    catch (const invalid_month& e) {
        cout << "Caught an exception: " << e.what() << endl;
    }
    catch (const invalid_year& e) {
        cout << "Caught an exception: " << e.what() << endl;
    }

    return 0;
}
