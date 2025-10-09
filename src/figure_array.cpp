#include <stdlib.h>
#include <string>
#include <iostream>
#include <initializer_list>
#include <algorithm>
#include <vector>
#include "../include/figure_array.h"

FigureArray::FigureArray(){}

FigureArray::FigureArray(const std::initializer_list<Figure*> &t) {
    array = std::vector<Figure*>(t.size());
    int i = 0;
    for (Figure* val: t) {
        array[i] = val;
        i++;
    }
}


FigureArray::FigureArray(const FigureArray& other) {
    array = std::vector<Figure*>(other.array.size());
    
    int i = 0;
    for (Figure* fig: other.array) {
        array[i] = fig;
        i++;
    }
}

FigureArray::FigureArray(FigureArray&& other) noexcept
     : array(std::move(other.array)) {
        
    }



std::ostream& operator<<(std::ostream& os, const FigureArray& money){

    return os;
}

void FigureArray::print_the_center_of_rotation() {
    for(int i = 0; i < array.size(); i++) {
        std::cout << "Figure" << std::to_string(i) << ": " << array[i]->calc_the_center_of_rotation().to_string() << std::endl;
    }
}

void FigureArray::print_the_area_of_each() {
    for (int i = 0; i < array.size(); i++) {
        std::cout << "Figure" << std::to_string(i) << ": " << array[i]->calc_area() << std::endl;
    }
}

double FigureArray::calc_total_area() {
    double total_area = 0;

    for (int i = 0; i < array.size(); i++) {
        total_area += array[i]->calc_area();
    }
    return total_area;
}

void FigureArray::removeFigure(int index) {
    array.erase(array.begin() + index);
}
