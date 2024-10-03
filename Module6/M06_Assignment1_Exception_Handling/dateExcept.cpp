//
// Created by Younghyun Lee on 10/2/24.
//

#include "dateExcept.h"

// Constructor for invalid month
invalid_month::invalid_month(const std::string& message) : std::invalid_argument(message) {}

// Constructor for invalid day
invalid_day::invalid_day(const std::string& message) : std::invalid_argument(message) {}

// Constructor for invalid year
invalid_year::invalid_year(const std::string& message) : std::invalid_argument(message) {}
