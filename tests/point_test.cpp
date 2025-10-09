#include <gtest/gtest.h>
#include "../include/point.h"

class PointTest : public ::testing::Test {
protected:
    void SetUp() override {
        p1 = Point(0, 0);
        p2 = Point(3, 4);
        p3 = Point(1.5, 2.5);
    }

    Point p1, p2, p3;
};

TEST_F(PointTest, DefaultConstructor) {
    Point p;
    EXPECT_DOUBLE_EQ(0, p.getX());
    EXPECT_DOUBLE_EQ(0, p.getY());
}

TEST_F(PointTest, ParameterizedConstructor) {
    EXPECT_DOUBLE_EQ(0, p1.getX());
    EXPECT_DOUBLE_EQ(0, p1.getY());
    EXPECT_DOUBLE_EQ(3, p2.getX());
    EXPECT_DOUBLE_EQ(4, p2.getY());
}

TEST_F(PointTest, SettersAndGetters) {
    p1.setX(5.5);
    p1.setY(6.6);
    EXPECT_DOUBLE_EQ(5.5, p1.getX());
    EXPECT_DOUBLE_EQ(6.6, p1.getY());
}

TEST_F(PointTest, DistanceCalculation) {
    Point p1(0, 0);
    Point p2(3, 4);
    EXPECT_DOUBLE_EQ(5.0, p1.getDistTo(p2));
    
    Point p3(1, 1);
    Point p4(4, 5);
    EXPECT_DOUBLE_EQ(5.0, p3.getDistTo(p4));
}

TEST_F(PointTest, ComparisonOperators) {
    Point p1(1.0, 2.0);
    Point p2(1.0, 2.0);
    Point p3(1.1, 2.0);
    
    EXPECT_TRUE(p1 == p2);
    EXPECT_FALSE(p1 == p3);
    EXPECT_FALSE(p1 != p2);
    EXPECT_TRUE(p1 != p3);
}

TEST_F(PointTest, StreamOutput) {
    Point p(1.5, 2.5);
    std::stringstream ss;
    ss << p;
    std::string result = ss.str();
    
    EXPECT_TRUE(result.find("1.5") != std::string::npos);
    EXPECT_TRUE(result.find("2.5") != std::string::npos);
}

TEST_F(PointTest, StreamInput) {
    Point p;
    std::stringstream ss("3.25 4.75");
    ss >> p;
    
    EXPECT_DOUBLE_EQ(3.25, p.getX());
    EXPECT_DOUBLE_EQ(4.75, p.getY());
}