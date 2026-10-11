#include "CConvexAdapter.hpp"

using namespace Shapes::Adapters;

namespace Errors
{
	inline constexpr auto INVALID_CANVAS = "CConvexAdapter can be used only with CRenderWindowAdapter";
}

CConvexAdapter::CConvexAdapter(CPoint v1, CPoint v2, CPoint v3, uint32_t fill, uint32_t outline)
	: m_shape(3)
{
	m_shape.setPoint(0, { static_cast<float>(v1.x), static_cast<float>(v1.y) });
	m_shape.setPoint(1, { static_cast<float>(v2.x), static_cast<float>(v2.y) });
	m_shape.setPoint(2, { static_cast<float>(v3.x), static_cast<float>(v3.y) });
	m_shape.setFillColor(sf::Color(fill));
	m_shape.setOutlineColor(sf::Color(outline));
}

double CConvexAdapter::GetArea() const
{
	auto v1 = m_shape.getPoint(0);
	auto v2 = m_shape.getPoint(1);
	auto v3 = m_shape.getPoint(2);

	double a = v1.x * (v2.y - v3.y);
	double b = v2.x * (v3.y - v1.y);
	double c = v3.x * (v1.y - v2.y);

	return std::abs(a + b + c) / 2;
}

double CConvexAdapter::GetPerimeter() const
{
	Shapes::CPoint v1 = Shapes::Vector2ToCPoint(m_shape.getPoint(0));
	Shapes::CPoint v2 = Shapes::Vector2ToCPoint(m_shape.getPoint(1));
	Shapes::CPoint v3 = Shapes::Vector2ToCPoint(m_shape.getPoint(2));

	return v1.Distance(v2)
        + v2.Distance(v3)
        + v3.Distance(v1);
}

uint32_t CConvexAdapter::GetFillColor() const
{
	return m_shape.getFillColor().toInteger();
}

uint32_t CConvexAdapter::GetOutlineColor() const
{
	return m_shape.getOutlineColor().toInteger();
}

void CConvexAdapter::Draw(Render::ICanvas* canvas)
{
	if (sf::RenderWindow* window = dynamic_cast<sf::RenderWindow*>(canvas); window != nullptr)
	{
		window->draw(m_shape);
	}
	else throw std::invalid_argument(Errors::INVALID_CANVAS);
}

Shapes::CPoint CConvexAdapter::GetVertex1() const
{
	return Shapes::Vector2ToCPoint(m_shape.getPoint(0));
}

Shapes::CPoint CConvexAdapter::GetVertex2() const
{
	return Shapes::Vector2ToCPoint(m_shape.getPoint(1));
}

Shapes::CPoint CConvexAdapter::GetVertex3() const
{
	return Shapes::Vector2ToCPoint(m_shape.getPoint(2));
}
  
std::string CConvexAdapter::ToString() const
{
	return "Convex"; // TODO: implement
}
