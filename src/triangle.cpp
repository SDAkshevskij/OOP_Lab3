#include "../include/triangle.h"

Triangle::Triangle()
    : Figure(3) {}

Triangle::Triangle(const std::initializer_list<Point> &t): Figure(t){
    if(t.size() != 3) {
        throw new std::length_error("Expected 3 points!");
    }
}
Triangle::Triangle(const Triangle& other) : Figure(other) {};
Triangle::Triangle(Triangle&& other) noexcept : Figure(other) {};

std::string Triangle::to_string() const {
    std::string res = "Triangle: ";
    for (int i = 0; i < pointsAmo; i++) {
        res += "V" + std::to_string(i) + ": " + points[i].to_string() + " ";
    }
    return res;
}

double Triangle::calc_area() {
    return (double)(*this);
}

std::istream& operator>>(std::istream& is, Triangle& triangle) {
    for (int i = 0; i < 3; i++) {
        Point p;
        is >> p;
        triangle.setPoint(i, p);
    }
    return is;
}

Triangle& Triangle::operator=(Triangle& other) {
    Figure::operator=(other);
    return *this;
}

Triangle::operator double() {
    Point pa = points[0];
    Point pb = points[1];
    Point pc = points[2];

    double a = pb.getDistTo(pc);
    double b = pa.getDistTo(pc);
    double c = pa.getDistTo(pb);

    double half_perimetr = (a + b + c) / 2;

    return sqrt(half_perimetr * (half_perimetr - a) * (half_perimetr - b) * (half_perimetr - c));
}