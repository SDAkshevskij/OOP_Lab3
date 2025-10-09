#pragma once 
#include <string>
#include <iostream>
#include "point.h"
#include "figure.h"

class Square : public Figure{
    public:
        Square();
        Square(const std::initializer_list<Point> &t);
        Square(const Square& other);
        Square(Square&& other) noexcept;

        std::string to_string() const;
        double calc_area();

        friend std::istream& operator>>(std::istream& is, Square& square);
        Square& operator=(Square& other);

        operator double();
};