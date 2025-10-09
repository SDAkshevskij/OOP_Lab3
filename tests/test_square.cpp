#include <gtest/gtest.h>
#include "../include/square.h"

class SquareTest : public ::testing::Test {
protected:
    void SetUp() override {
        unitSquare = new Square{Point(0,0), Point(0,1), Point(1,1), Point(1,0)};
        largeSquare = new Square{Point(0,0), Point(0,5), Point(5,5), Point(5,0)};
    }

    void TearDown() override {
        delete unitSquare;
        delete largeSquare;
    }

    Square* unitSquare;
    Square* largeSquare;
};


TEST_F(SquareTest, AreaCalculationUnitSquare) {
    double area = unitSquare->calc_area();
    EXPECT_DOUBLE_EQ(1.0, area);
}

TEST_F(SquareTest, AreaCalculationLargeSquare) {
    double area = largeSquare->calc_area();
    EXPECT_DOUBLE_EQ(25.0, area);
}

TEST_F(SquareTest, DoubleConversion) {
    double area = (double)(*unitSquare);
    EXPECT_DOUBLE_EQ(1.0, area);
}

TEST_F(SquareTest, CenterCalculation) {
    Point center = unitSquare->calc_the_center_of_rotation();
    EXPECT_DOUBLE_EQ(0.5, center.getX());
    EXPECT_DOUBLE_EQ(0.5, center.getY());
}

TEST_F(SquareTest, ToString) {
    std::string result = unitSquare->to_string();
    EXPECT_TRUE(result.find("Square") != std::string::npos);
    EXPECT_TRUE(result.find("V0:") != std::string::npos);
    EXPECT_TRUE(result.find("V1:") != std::string::npos);
    EXPECT_TRUE(result.find("V2:") != std::string::npos);
    EXPECT_TRUE(result.find("V3:") != std::string::npos);
}