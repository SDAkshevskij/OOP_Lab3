#include <gtest/gtest.h>
#include "../include/figure_array.h"
#include "../include/triangle.h"
#include "../include/square.h"
#include "../include/octagon.h"

class FigureArrayTest : public ::testing::Test {
protected:
    void SetUp() override {
        triangle = new Triangle{Point(0,0), Point(3,0), Point(0,4)};
        square = new Square{Point(0,0), Point(0,2), Point(2,2), Point(2,0)};
        octagon = new Octagon{
            Point(3,1), Point(6,1), Point(2,3), Point(7,0),
            Point(2,5), Point(4,6), Point(7,4), Point(6,6)
        };
    }

    void TearDown() override {
        delete triangle;
        delete square;
        delete octagon;
    }

    Triangle* triangle;
    Square* square;
    Octagon* octagon;
};

TEST_F(FigureArrayTest, DefaultConstructor) {
    FigureArray arr;
    EXPECT_DOUBLE_EQ(0.0, arr.calc_total_area());
}

TEST_F(FigureArrayTest, InitializerListConstructor) {
    FigureArray arr{triangle, square, octagon};
    EXPECT_GT(arr.calc_total_area(), 0.0);
}

TEST_F(FigureArrayTest, TotalAreaCalculation) {
    FigureArray arr{triangle, square};
    double triangle_area = 6.0; // 3*4/2
    double square_area = 4.0;   // 2*2
    double expected_total = triangle_area + square_area;
    
    EXPECT_NEAR(expected_total, arr.calc_total_area(), 0.0001);
}

TEST_F(FigureArrayTest, RemoveFigure) {
    FigureArray arr{triangle, square, octagon};
    double initial_area = arr.calc_total_area();
    
    arr.removeFigure(0); // Удаляем треугольник
    double area_after_removal = arr.calc_total_area();
    
    EXPECT_LT(area_after_removal, initial_area);
    
    // Удаляем еще одну фигуру
    arr.removeFigure(0); // Теперь удаляем квадрат
    double final_area = arr.calc_total_area();
    
    EXPECT_LT(final_area, area_after_removal);
}

TEST_F(FigureArrayTest, CopyConstructor) {
    FigureArray original{triangle, square};
    FigureArray copy(original);
    
    // Проверяем, что площади совпадают
    EXPECT_DOUBLE_EQ(original.calc_total_area(), copy.calc_total_area());
}

TEST_F(FigureArrayTest, MoveConstructor) {
    FigureArray original{triangle, square};
    double original_area = original.calc_total_area();
    
    FigureArray moved(std::move(original));
    
    EXPECT_DOUBLE_EQ(original_area, moved.calc_total_area());
}

TEST_F(FigureArrayTest, PrintFunctionsDoNotCrash) {
    FigureArray arr{triangle, square};
    
    // Эти функции должны выполняться без падения
    EXPECT_NO_THROW(arr.print_the_center_of_rotation());
    EXPECT_NO_THROW(arr.print_the_area_of_each());
}

TEST_F(FigureArrayTest, EmptyArrayOperations) {
    FigureArray arr;
    
    EXPECT_DOUBLE_EQ(0.0, arr.calc_total_area());
    EXPECT_NO_THROW(arr.print_the_center_of_rotation());
    EXPECT_NO_THROW(arr.print_the_area_of_each());
    EXPECT_NO_THROW(arr.removeFigure(0)); // Не должно падать при удалении из пустого массива
}