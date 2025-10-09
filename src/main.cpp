#include <iostream>
#include "../include/triangle.h"
#include "../include/square.h"
#include "../include/octagon.h"
#include "../include/figure_array.h"

using namespace std;


int main(int argc, char** argv){
    Octagon oct = {Point(3,1), Point(6, 1), 
        Point(2, 3), Point(7, 0), 
        Point(2, 5), Point(4, 6), 
        Point(7, 4), Point(6,6)};

    Square sq = {Point(1, 1), Point(1, 2), Point(2, 2), Point(2, 1)};
    cout << sq << endl;
    Square sq2 = {Point(1, 2), Point(2, 1), Point(2, 2), Point(1, 1)};
    sq = sq2;

    FigureArray figArr{&oct, &sq};


    cout << (sq == sq2);
}