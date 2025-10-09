#include <gtest/gtest.h>
#include "../include/figure.h"
#include "../include/triangle.h"

class FigureTest : public ::testing::Test {
protected:
    void SetUp() override {
        triangle = new Triangle{Point(0,0), Point(1,0), Point(0,1)};
    }

    void TearDown() override {
        delete triangle;
    }

    Triangle* triangle;
};

TEST_F(FigureTest, CenterCalculation) {
    Point center = triangle->calc_the_center_of_rotation();
    EXPECT_NEAR(0.3333, center.getX(), 0.001);
    EXPECT_NEAR(0.3333, center.getY(), 0.001);
}

TEST_F(FigureTest, CopyConstructor) {
    Triangle copy(*triangle);
    EXPECT_TRUE(copy == *triangle);
}

TEST_F(FigureTest, AssignmentOperator) {
    Triangle other{Point(0,0), Point(2,0), Point(0,2)};
    other = *triangle;
    EXPECT_TRUE(other == *triangle);
}
