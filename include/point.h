#pragma once
#include <string>
#include <iostream>
#include <cmath>


class Point {
    public:
        Point() {}
        Point(double x, double y)
            : x(x), y(y) {}

        double getX(){
            return x;
        }
        double getY(){
            return y;
        }
        void setX(double x){
            this->x = x;
        }
        void setY(double y) {
            this->y = y;
        }

        double getDistTo(Point &other) {
            double xDiff = abs(other.x - x);
            double yDiff = abs(other.y - y);

            return sqrt(xDiff * xDiff + yDiff * yDiff);
        }

        std::string to_string() {
            return "x: " + std::to_string(x) + " y: " + std::to_string(y);
        }

        bool operator==(Point &other) {
            double eps = 0.00001;
            return abs(x - other.x) < eps && abs(y - other.y) < eps;
        }

        
        bool operator!=(Point &other) {
            return !(*this == other);
        }

        friend std::istream& operator>>(std::istream& is, Point& point) {
            is >> point.x >> point.y;
            return is;
        }
        friend std::ostream& operator<<(std::ostream& os, Point& point) {
            os << "x: " << std::to_string(point.x) << " y: " << std::to_string(point.y);
            return os;
        }
    private:
        double x = 0;
        double y = 0;
};