#pragma once

#include "CPoint.hpp"
#include <array>

namespace Render
{

class ICanvas
{
public:
	virtual void DrawPolygon(std::array<Shapes::CPoint, 3>& vertices) = 0;
};
	
}
