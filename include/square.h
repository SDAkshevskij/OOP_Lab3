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

        std::string to_string() const override;
        double calc_area() override;

        friend std::istream& operator>>(std::istream& is, Square& square);
        Square& operator=(Square& other);
        bool operator==(Square& other);

        operator double();
};