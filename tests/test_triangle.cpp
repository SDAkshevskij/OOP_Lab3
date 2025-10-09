#include <gtest/gtest.h>
#include "../include/triangle.h"
#include <cmath>

class TriangleTest : public ::testing::Test {
protected:
    void SetUp() override {
        rightTriangle = new Triangle{Point(0,0), Point(1,0), Point(0,1)};
        equilateralTriangle = new Triangle{
            Point(0,0), 
            Point(1,0), 
            Point(0.5, std::sqrt(3)/2)
        };
    }

    void TearDown() override {
        delete rightTriangle;
        delete equilateralTriangle;
    }

    Triangle* rightTriangle;
    Triangle* equilateralTriangle;
};

TEST_F(TriangleTest, AreaCalculationRightTriangle) {
    double area = rightTriangle->calc_area();
    EXPECT_NEAR(0.5, area, 0.0001);
}

TEST_F(TriangleTest, AreaCalculationEquilateralTriangle) {
    double area = equilateralTriangle->calc_area();
    double expected = std::sqrt(3) / 4; // площадь равностороннего треугольника со стороной 1
    EXPECT_NEAR(expected, area, 0.0001);
}

TEST_F(TriangleTest, DoubleConversion) {
    double area = (double)(*rightTriangle);
    EXPECT_NEAR(0.5, area, 0.0001);
}

TEST_F(TriangleTest, ToString) {
    std::string result = rightTriangle->to_string();
    EXPECT_TRUE(result.find("Triangle") != std::string::npos);
    EXPECT_TRUE(result.find("V0:") != std::string::npos);
    EXPECT_TRUE(result.find("V1:") != std::string::npos);
    EXPECT_TRUE(result.find("V2:") != std::string::npos);
}

TEST_F(TriangleTest, StreamInput) {
    Triangle t;
    std::stringstream ss("0 0 1 0 0 1");
    ss >> t;
    
    // Проверяем, что треугольник создан с правильными точками
    double area = t.calc_area();
    EXPECT_NEAR(0.5, area, 0.0001);
}