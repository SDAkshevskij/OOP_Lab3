#include <stdlib.h>
#include <string>
#include <iostream>
#include <initializer_list>
#include <algorithm>
#include "../include/figure.h"
Figure::Figure(int pointsAmo)
    : pointsAmo(pointsAmo), points(new Point[pointsAmo]) {}
Figure::Figure(const std::initializer_list<Point> &t) {
    pointsAmo = t.size();
    points = new Point[pointsAmo];
    int i = 0;
    for (Point p: t) {
        points[i] = p;
        i++;
    }
    sortPoints();
}
Figure::Figure(const Figure& other) {
    pointsAmo = other.pointsAmo;
    points = new Point[other.pointsAmo];
    for (int i = 0; i < other.pointsAmo; i++) {
        points[i] = other.points[i];
    }
}
Figure::Figure(Figure&& other) noexcept
    : points(other.points), pointsAmo(other.pointsAmo) {
        other.points = nullptr;
        other.pointsAmo = 0;
}
Figure::~Figure() noexcept {
    delete[] points;
}
Point Figure::calc_the_center_of_rotation() {
    double xSum = 0;
    double ySum = 0;
    for (int i = 0; i < pointsAmo; i++) {
        xSum += points[i].getX();
        ySum += points[i].getY();
    }
    return Point(xSum / pointsAmo, ySum / pointsAmo);
}
std::string Figure::to_string() const {
    std::string res = "Figure: ";
    for (int i = 0; i < pointsAmo; i++) {
        res += "V" + std::to_string(i) + ": " + points[i].to_string() + " ";
    }
    return res;
}
void Figure::setPoint(int index, Point point) {
    points[index] = point;
}
std::ostream& operator<<(std::ostream& os, const Figure& figure){
    os << figure.to_string();
    return os;
}
std::istream& operator>>(std::istream& is, Figure& figure) {
    for (int i = 0; i < figure.pointsAmo; i++){
        is >> figure.points[i];
    }
    return is;
}
bool Figure::operator==(const Figure& other) const {
    if (this == &other) return true;
    if(pointsAmo != other.pointsAmo) {
        return false;
    }
    for (int i = 0; i < pointsAmo; i++) {
        if (points[i] != other.points[i]) {
            return false;
        }
    }
    return true;
}

Figure& Figure::operator=(const Figure& other) {
    if (this != &other) {
        Point* newPoints = new Point[other.pointsAmo];
        std::copy(other.points, other.points + other.pointsAmo, newPoints);
        delete[] points;
        points = newPoints;
        pointsAmo = other.pointsAmo;
    }
    return *this;
}

void Figure::sortPoints() {
    double angles[pointsAmo];
    Point center = getCenterPoint();
    for (int i = 0; i < pointsAmo; i++) {
        angles[i] = atan2(points[i].getY() - center.getY(), points[i].getX() - center.getX());
    }
    for (int i = 0; i < pointsAmo; i++) {
        for(int j = 1; j < pointsAmo; j++) {
            if (angles[j - 1] < angles[j]) {
                std::swap(angles[j - 1], angles[j]);
                std::swap(points[j - 1], points[j]);
            }
        }
    }
}
Point Figure::getCenterPoint() {
    double xSum = 0;
    double ySum = 0;
    for (int i = 0; i < pointsAmo; i++) {
        xSum += points[i].getX();
        ySum += points[i].getY();
    }
    return Point(xSum / pointsAmo, ySum / pointsAmo);
}
Figure::operator double() {
    return this->calc_area();
}