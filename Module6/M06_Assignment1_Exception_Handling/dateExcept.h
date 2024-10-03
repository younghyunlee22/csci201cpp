//
// Created by Younghyun Lee on 10/2/24.
//

#ifndef DATEEXCEPT_H
#define DATEEXCEPT_H

#include <stdexcept>
#include <string>

// std::exception → std::logic_error → std::invalid_argument

// Exception for invalid month
class invalid_month : public std::invalid_argument {
public:
    // Constructor
    invalid_month(const std::string& message);
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
    invalid_year(const std::string& message);
};

#endif //DATEEXCEPT_H
