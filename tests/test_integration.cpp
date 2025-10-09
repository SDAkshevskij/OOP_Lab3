#include <gtest/gtest.h>
#include "../include/figure_array.h"
#include "../include/triangle.h"
#include "../include/square.h"
#include "../include/octagon.h"

class IntegrationTest : public ::testing::Test {
protected:
    void SetUp() override {
        t1 = new Triangle{Point(0,0), Point(3,0), Point(0,4)};
        t2 = new Triangle{Point(0,0), Point(4,0), Point(0,3)};
        s1 = new Square{Point(0,0), Point(0,2), Point(2,2), Point(2,0)};
        s2 = new Square{Point(0,0), Point(0,3), Point(3,3), Point(3,0)};
        oct = new Octagon{
            Point(1,0), Point(std::sqrt(2)/2, std::sqrt(2)/2), Point(0,1),
            Point(-std::sqrt(2)/2, std::sqrt(2)/2), Point(-1,0),
            Point(-std::sqrt(2)/2, -std::sqrt(2)/2), Point(0,-1),
            Point(std::sqrt(2)/2, -std::sqrt(2)/2)
        };
    }

    void TearDown() override {
        delete t1;
        delete t2;
        delete s1;
        delete s2;
        delete oct;
    }

    Triangle* t1;
    Triangle* t2;
    Square* s1;
    Square* s2;
    Octagon* oct;
};

TEST_F(IntegrationTest, ComplexFigureArrayScenario) {
    FigureArray figures{t1, s1, t2, s2, oct};
    
    double total_area = figures.calc_total_area();
    double expected = 6.0 + 4.0 + 6.0 + 9.0 + (2 * std::sqrt(2));
    
    EXPECT_NEAR(expected, total_area, 0.0001);
    
    // Удаляем несколько фигур и проверяем обновленную площадь
    figures.removeFigure(0); // Удаляем первый треугольник
    figures.removeFigure(1); // Удаляем второй треугольник (теперь он на позиции 1)
    
    double new_total = figures.calc_total_area();
    double new_expected = 4.0 + 9.0 + (2 * std::sqrt(2));
    
    EXPECT_NEAR(new_expected, new_total, 0.0001);
}

TEST_F(IntegrationTest, CopyAndAssignmentBetweenFigures) {
    Triangle original{Point(0,0), Point(1,0), Point(0,1)};
    
    // Тест конструктора копирования
    Triangle copy(original);
    EXPECT_TRUE(copy == original);
    
    // Тест оператора присваивания
    Triangle assigned{Point(0,0), Point(2,0), Point(0,2)};
    assigned = original;
    EXPECT_TRUE(assigned == original);
}

TEST_F(IntegrationTest, MixedFigureTypes) {
    FigureArray mixed{t1, s1, oct};
    
    // Все функции должны работать с разными типами фигур
    EXPECT_NO_THROW(mixed.print_the_center_of_rotation());
    EXPECT_NO_THROW(mixed.print_the_area_of_each());
    EXPECT_GT(mixed.calc_total_area(), 0.0);
}
