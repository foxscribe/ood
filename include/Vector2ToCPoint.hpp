#pragma once

#include "CPoint.hpp"

#include <SFML/System/Vector2.hpp>

namespace Shapes
{

template<typename T>
static inline CPoint Vector2ToCPoint(sf::Vector2<T> v)
{
	return CPoint{ v.x, v.y };
}

}
