/* Program name: date.cpp
* Author: Younghyun Lee
* Date last updated: 10/2/2024
* Purpose: Create Date class
*/
#ifndef DATE_H
#define DATE_H

#include <iostream>

class date {
public:
    // Constructor
    date(int month, int day, int year);
    // Destructor
    ~date();

    // Getters
    int getDay() const;
    int getMonth() const;
    int getYear() const;

    // Setters
    void setDay(int day);
    void setMonth(int month);
    void setYear(int year);

    // Other
    bool isLeapYear();

    // Operator functions
    bool operator!=(const date& otherDate) const;
    bool operator<(const date& otherDate) const;
    bool operator<=(const date& otherDate) const;
    bool operator==(const date& otherDate) const;
    bool operator>(const date& otherDate) const;
    bool operator>=(const date& otherDate) const;

    date operator++();      // Pre-increment
    date operator++(int);   // Post-increment with dummy int parameter
    date operator--();      // Pre-decrement
    date operator--(int);   // Post-decrement with dummy int parameter

    date& operator+(int daysToAdd);
    date& operator-(int daysToSub);

    // Friend functions
    friend date& operator+(int daysToAdd, date& addToDate);
    friend date& operator-(int daysToSub, date& subFromDate);
    friend std::istream& operator>>(std::istream& in, date& dateToFill);
    friend std::ostream& operator<<(std::ostream& out, date& dateToPrint);

    int daysInMonth(int month, int year);

private:
    int day;
    int month;
    int year;

    // Helper methods
    void isValidDate(int month, int day, int year);
    bool isLeapYearHelper(int year);
    void incrementDate();
    void decrementDate();
};

#endif // DATE_H
