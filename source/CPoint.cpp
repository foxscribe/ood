#include "CPoint.hpp"

using namespace Shapes;

bool CPoint::operator==(const CPoint& other) const
{
    return x == other.x && y == other.y;
}

bool CPoint::operator!=(const CPoint& other) const
{
    return x != other.x || y != other.y;
}

double CPoint::Distance(const CPoint& other) const
{
    return std::hypot(x - other.x, y - other.y);
}
