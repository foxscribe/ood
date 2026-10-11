#include <gtest/gtest.h>
#include "CConvexAdapter.hpp"

using namespace Shapes;
using namespace Shapes::Adapters;

TEST(CConvexAdapterTest, GetVertex1_ReturnsCorrectPoint)
{
    CConvexAdapter triangle({0.0, 0.0}, {4.0, 0.0}, {0.0, 3.0}, 0xFF0000, 0x00FF00);
    CPoint expected{0.0, 0.0};
    EXPECT_EQ(triangle.GetVertex1(), expected);
}

TEST(CConvexAdapterTest, GetVertex2_ReturnsCorrectPoint)
{
    CConvexAdapter triangle({0.0, 0.0}, {4.0, 0.0}, {0.0, 3.0}, 0xFF0000, 0x00FF00);
    CPoint expected{4.0, 0.0};
    EXPECT_EQ(triangle.GetVertex2(), expected);
}

TEST(CConvexAdapterTest, GetVertex3_ReturnsCorrectPoint)
{
    CConvexAdapter triangle({0.0, 0.0}, {4.0, 0.0}, {0.0, 3.0}, 0xFF0000, 0x00FF00);
    CPoint expected{0.0, 3.0};
    EXPECT_EQ(triangle.GetVertex3(), expected);
}

TEST(CConvexAdapterTest, GetOutlineColor_ReturnsCorrectColor)
{
    CConvexAdapter triangle({0.0, 0.0}, {4.0, 0.0}, {0.0, 3.0}, 0xFF000000, 0x00FF0000);
    EXPECT_EQ(triangle.GetOutlineColor(), 0x00FF0000u);
}

TEST(CConvexAdapterTest, GetFillColor_ReturnsCorrectColor)
{
    CConvexAdapter triangle({0.0, 0.0}, {4.0, 0.0}, {0.0, 3.0}, 0xFF000000, 0x00FF0000);
    EXPECT_EQ(triangle.GetFillColor(), 0xFF000000u);
}

TEST(CConvexAdapterTest, GetArea_ReturnsCorrectArea)
{
    CConvexAdapter triangle({0.0, 0.0}, {4.0, 0.0}, {0.0, 3.0}, 0xFF0000, 0x00FF00);
    EXPECT_DOUBLE_EQ(triangle.GetArea(), 6.0);
}

// [x] TODO: протестировать на ненулевой периметр
TEST(CConvexAdapterTest, GetArea_ReturnsZero)
{
    CConvexAdapter triangle({0.0, 0.0}, {2.0, 0.0}, {4.0, 0.0}, 0xFF0000, 0x00FF00);
    EXPECT_DOUBLE_EQ(triangle.GetPerimeter(), 8.0);
    EXPECT_DOUBLE_EQ(triangle.GetArea(), 0.0);
}

TEST(CConvexAdapterTest, GetPerimeter_ReturnsCorrectPerimeter)
{
    CConvexAdapter triangle({0.0, 0.0}, {4.0, 0.0}, {0.0, 3.0}, 0xFF0000, 0x00FF00);
    EXPECT_DOUBLE_EQ(triangle.GetPerimeter(), 12.0);
}
