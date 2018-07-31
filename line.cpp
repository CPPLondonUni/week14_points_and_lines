//
// Created by Tristan Brindle on 24/07/2018.
//

#include "line.hpp"

line::line(const point& start, const point& end)
    : start_{start},
      end_{end}
{}


std::ostream& operator<<(std::ostream& os, const line& l)
{
    os << "Line from " << l.start_ << " to " << l.end_;
    return os;
}