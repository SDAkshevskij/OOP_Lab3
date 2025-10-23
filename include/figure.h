#pragma once 

#include "point.h"
#include <stdlib.h>
#include <string>
#include <initializer_list>

class Figure {
    public:
        Figure(int pointsAmo);
        Figure(const std::initializer_list<Point> &t);
        Figure(const Figure& other);
        Figure(Figure&& other) noexcept;
        virtual ~Figure() noexcept;

        virtual std::string to_string() const;
        std::istream& read_from_stream(std::istream &is);
        Point calc_the_center_of_rotation();
        virtual double calc_area() = 0;

        void setPoint(int index, Point point);

        friend std::ostream& operator<<(std::ostream& os, const Figure& figure);
        friend std::istream& operator>>(std::istream& is, Figure& figure);

        bool operator==(const Figure& other) const; 
        virtual Figure& operator=(const Figure& other);

        operator double();


        
    protected:
        Point *points = nullptr;
        int pointsAmo = 0;

        void sortPoints();
        Point getCenterPoint();

};