#include <gtest/gtest.h>
#include "CRectangleAdapter.hpp"

using namespace Shapes;
using namespace Shapes::Adapters;

TEST(CRectangleAdapterTest, GetLeftTop_ReturnsCorrectPoint)
{
    CRectangleAdapter rect({1.0, 2.0}, 3.0, 4.0, 0xFF0000, 0x00FF00);
    CPoint expected{1.0, 2.0};
    EXPECT_EQ(rect.GetLeftTop(), expected);
}

TEST(CRectangleAdapterTest, GetRightBottom_ReturnsCorrectPoint)
{
    CRectangleAdapter rect({1.0, 2.0}, 3.0, 4.0, 0xFF0000, 0x00FF00);
    CPoint expected{4.0, 6.0};
    EXPECT_EQ(rect.GetRightBottom(), expected);
}

TEST(CRectangleAdapterTest, GetWidth_ReturnsCorrectWidth)
{
    CRectangleAdapter rect({1.0, 2.0}, 3.0, 4.0, 0xFF0000, 0x00FF00);
    EXPECT_DOUBLE_EQ(rect.GetWidth(), 3.0);
}

TEST(CRectangleAdapterTest, GetHeight_ReturnsCorrectHeight)
{
    CRectangleAdapter rect({1.0, 2.0}, 3.0, 4.0, 0xFF0000, 0x00FF00);
    EXPECT_DOUBLE_EQ(rect.GetHeight(), 4.0);
}

TEST(CRectangleAdapterTest, GetOutlineColor_ReturnsCorrectColor)
{
    CRectangleAdapter rect({1.0, 2.0}, 3.0, 4.0, 0xFF000000, 0x00FF0000);
    EXPECT_EQ(rect.GetOutlineColor(), 0x00FF0000u); 
}

TEST(CRectangleAdapterTest, GetFillColor_ReturnsCorrectColor)
{
    CRectangleAdapter rect({1.0, 2.0}, 3.0, 4.0, 0xFF000000, 0x00FF0000);
    EXPECT_EQ(rect.GetFillColor(), 0xFF000000u); 
}

TEST(CRectangleAdapterTest, GetArea_ReturnsCorrectArea)
{
    CRectangleAdapter rect({0.0, 0.0}, 3.0, 4.0, 0xFF0000, 0x00FF00);
    EXPECT_DOUBLE_EQ(rect.GetArea(), 12.0);
}

TEST(CRectangleAdapterTest, GetPerimeter_ReturnsCorrectPerimeter)
{
    CRectangleAdapter rect({0.0, 0.0}, 3.0, 4.0, 0xFF0000, 0x00FF00);
    EXPECT_DOUBLE_EQ(rect.GetPerimeter(), 14.0);
}
