#pragma once
#include "figure.h"
#include <iostream>

class Triangle : public Figure {

    public:
        Triangle();
        Triangle(const std::initializer_list<Point> &t);
        Triangle(const Triangle& other);
        Triangle(Triangle&& other) noexcept;

        std::string to_string() const;
        double calc_area();

        friend std::istream& operator>>(std::istream& is, Triangle& triangle);
        Triangle& operator=(Triangle& other);

        operator double();
};