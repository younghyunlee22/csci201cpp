/* Program name: dateExcept.h
* Author: Younghyun Lee
* Date last updated: 10/2/2024
* Purpose: Create Date Exception classes
*/

#ifndef DATEEXCEPT_H
#define DATEEXCEPT_H

#include <stdexcept>
#include <string>

// std::exception → std::logic_error → std::invalid_argument

// Exception for invalid month
class invalid_month : public std::invalid_argument {
public:
    // Constructor
    explicit invalid_month(const std::string& message);
};

// Exception for invalid day
class invalid_day : public std::invalid_argument {
public:
    // Constructor
    explicit invalid_day(const std::string& message);
};

// Exception for invalid year
class invalid_year : public std::invalid_argument {
public:
    // Constructor
    explicit invalid_year(const std::string& message);
};

#endif //DATEEXCEPT_H
