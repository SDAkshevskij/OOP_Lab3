#include <gtest/gtest.h>
#include "../include/octagon.h"
#include <cmath>

class OctagonTest : public ::testing::Test {
protected:
    void SetUp() override {
        // Правильный восьмиугольник
        regularOctagon = new Octagon{
            Point(1,0), 
            Point(std::sqrt(2)/2, std::sqrt(2)/2), 
            Point(0,1),
            Point(-std::sqrt(2)/2, std::sqrt(2)/2), 
            Point(-1,0),
            Point(-std::sqrt(2)/2, -std::sqrt(2)/2), 
            Point(0,-1),
            Point(std::sqrt(2)/2, -std::sqrt(2)/2)
        };
        
        testOctagon = new Octagon{
            Point(3,1), Point(6,1), Point(2,3), Point(7,0),
            Point(2,5), Point(4,6), Point(7,4), Point(6,6)
        };
    }

    void TearDown() override {
        delete regularOctagon;
        delete testOctagon;
    }

    Octagon* regularOctagon;
    Octagon* testOctagon;
};

TEST_F(OctagonTest, AreaCalculationRegularOctagon) {
    double area = regularOctagon->calc_area();
    double expected = 2 * std::sqrt(2); // площадь правильного восьмиугольника со стороной 1
    EXPECT_NEAR(expected, area, 0.0001);
}

TEST_F(OctagonTest, DoubleConversion) {
    double area = (double)(*regularOctagon);
    double expected = 2 * std::sqrt(2);
    EXPECT_NEAR(expected, area, 0.0001);
}

TEST_F(OctagonTest, CenterCalculation) {
    Point center = testOctagon->calc_the_center_of_rotation();
    double expected_x = (3+6+2+7+2+4+7+6)/8.0;
    double expected_y = (1+1+3+0+5+6+4+6)/8.0;
    EXPECT_NEAR(expected_x, center.getX(), 0.0001);
    EXPECT_NEAR(expected_y, center.getY(), 0.0001);
}

TEST_F(OctagonTest, SetPointResortsPoints) {
    Octagon oct = *testOctagon;
    Point original_center = oct.calc_the_center_of_rotation();
    
    // Изменяем точку
    oct.setPoint(0, Point(10, 10));
    Point new_center = oct.calc_the_center_of_rotation();
    
    // Центр должен измениться
    EXPECT_NE(original_center.getX(), new_center.getX());
    EXPECT_NE(original_center.getY(), new_center.getY());
}

TEST_F(OctagonTest, ToString) {
    std::string result = testOctagon->to_string();
    EXPECT_TRUE(result.find("Octagon") != std::string::npos);
    for (int i = 0; i < 8; i++) {
        EXPECT_TRUE(result.find("V" + std::to_string(i) + ":") != std::string::npos);
    }
}