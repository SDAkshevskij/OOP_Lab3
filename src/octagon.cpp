#include "../include/octagon.h"
#include "iostream"

Octagon::Octagon()
    : Figure(8) {}

Octagon::Octagon(const std::initializer_list<Point> &t): Figure(t){
    if(t.size() != 8) {
        throw new std::length_error("Expected 8 points!");
    }

    sortPoints();
}
Octagon::Octagon(const Octagon& other) : Figure(other) {};
Octagon::Octagon(Octagon&& other) noexcept : Figure(other) {};

std::string Octagon::to_string() const {
    std::string res = "Octagon: ";
    for (int i = 0; i < pointsAmo; i++) {
        res += "V" + std::to_string(i) + ": " + points[i].to_string() + " ";
    }

    return res;
}

double Octagon::calc_area() {
    double sum = 0;

    for (int i = 0; i < pointsAmo; i++) {
        sum += points[i].getX() * points[(i + 1) % pointsAmo].getY() - points[(i + 1) % pointsAmo].getX() * points[i].getY();
    }
    sum /= 2;

    return abs(sum);
}

void Octagon::setPoint(int index, Point point) {
    points[index] = point;
    sortPoints();
}

std::istream& operator>>(std::istream& is, Octagon& octagon) {
    for (int i = 0; i < 8; i++) {
        Point p;
        is >> p;
        octagon.setPoint(i, p);
    }
    return is;
}

Octagon& Octagon::operator=(Octagon& other) {
    Figure::operator=(other);
    return *this;
}

bool Octagon::operator==(Octagon& other) {
    return Figure::operator==(other);
}

Octagon::operator double() {
    return this->calc_area();
}

