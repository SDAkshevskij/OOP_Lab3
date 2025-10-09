#include "../include/square.h"


Square::Square()
    : Figure(4) {}

Square::Square(const std::initializer_list<Point> &t): Figure(t){
    if(t.size() != 4) {
        throw new std::length_error("Expected 4 points!");
    }
}
Square::Square(const Square& other) : Figure(other) {};
Square::Square(Square&& other) noexcept : Figure(other) {};

std::string Square::to_string() const {
    std::string res = "Square: ";
    for (int i = 0; i < pointsAmo; i++) {
        res += "V" + std::to_string(i) + ": " + points[i].to_string() + " ";
    }
    return res;
}

double Square::calc_area() {
    return (double)(*this);
}



std::istream& operator>>(std::istream& is, Square& square) {
    for (int i = 0; i < 3; i++) {
        Point p;
        is >> p;
        square.setPoint(i, p);
    }
    return is;
}

Square& Square::operator=(Square& other) {
    Figure::operator=(other);
    return *this;
}

Square::operator double() {
    Point p1 = points[0];
    Point p2 = points[1];

    double sideLen = std::max(abs(p1.getX() - p2.getX()), abs(p1.getY() - p2.getY()));
    return sideLen * sideLen; 
}