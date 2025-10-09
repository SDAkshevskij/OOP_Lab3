#pragma once 

#include <stdlib.h>
#include <string>
#include <initializer_list>
#include <vector>
#include "figure.h"

class FigureArray {
    public:
        FigureArray();
        FigureArray(const std::initializer_list<Figure*> &t);
        FigureArray(const FigureArray& other);
        FigureArray(FigureArray&& other) noexcept;


        friend std::ostream& operator<<(std::ostream& os, const FigureArray& money);

        void print_the_center_of_rotation();
        void print_the_area_of_each();
        double calc_total_area();
        void removeFigure(int index);
        
    private:

        std::vector<Figure*> array;
        
};