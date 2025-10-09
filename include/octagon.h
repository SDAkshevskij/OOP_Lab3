#include "figure.h"
#include <algorithm>

class Octagon : public Figure {
    public:
        Octagon();
        Octagon(const std::initializer_list<Point> &t);
        Octagon(const Octagon& other);
        Octagon(Octagon&& other) noexcept;

        std::string to_string() const;
        void setPoint(int index, Point point);
        double calc_area();

        friend std::istream& operator>>(std::istream& is, Octagon& square);
        Octagon& operator=(Octagon& other);

        operator double();
    
};