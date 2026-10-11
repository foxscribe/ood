#include <gtest/gtest.h>
#include <numbers>
#include "CCircleAdapter.hpp"

using namespace Shapes;
using namespace Shapes::Adapters;

TEST(CCircleAdapterTest, GetCenter_ReturnsCorrectPoint)
{
    CCircleAdapter circle({1.0, 2.0}, 5.0, 0xFF0000, 0x00FF00);
    CPoint expected{1.0, 2.0};
    EXPECT_EQ(circle.GetCenter(), expected);
}

TEST(CCircleAdapterTest, GetRadius_ReturnsCorrectRadius)
{
    CCircleAdapter circle({1.0, 2.0}, 5.0, 0xFF0000, 0x00FF00);
    EXPECT_DOUBLE_EQ(circle.GetRadius(), 5.0);
}

TEST(CCircleAdapterTest, GetOutlineColor_ReturnsCorrectColor)
{
    CCircleAdapter circle({1.0, 2.0}, 5.0, 0xFF000000, 0x00FF0000);
    EXPECT_EQ(circle.GetOutlineColor(), 0x00FF0000u); 
}

TEST(CCircleAdapterTest, GetFillColor_ReturnsCorrectColor)
{
    CCircleAdapter circle({1.0, 2.0}, 5.0, 0xFF000000, 0x00FF0000);
    EXPECT_EQ(circle.GetFillColor(), 0xFF000000u); 
}

TEST(CCircleAdapterTest, GetArea_ReturnsCorrectArea)
{
    CCircleAdapter circle({0.0, 0.0}, 2.0, 0xFF0000, 0x00FF00);
    double expectedArea = std::numbers::pi * 2.0 * 2.0;
    EXPECT_DOUBLE_EQ(circle.GetArea(), expectedArea);
}

TEST(CCircleAdapterTest, GetPerimeter_ReturnsCorrectPerimeter)
{
    CCircleAdapter circle({0.0, 0.0}, 2.0, 0xFF0000, 0x00FF00);
    double expectedPerimeter = 2.0 * std::numbers::pi * 2.0;
    EXPECT_DOUBLE_EQ(circle.GetPerimeter(), expectedPerimeter);
}
