#include "CCircleAdapter.hpp"

using namespace Shapes::Adapters;

CCircleAdapter::CCircleAdapter(CPoint pos, double r, uint32_t fill, uint32_t outline)
	: m_shape(r)
{
  m_shape.setPosition(pos.x - r, pos.y - r);
  m_shape.setFillColor(sf::Color(fill));
  m_shape.setOutlineColor(sf::Color(outline));
}

double CCircleAdapter::GetArea() const
{
	auto radius = m_shape.getRadius();
	return std::numbers::pi * radius * radius;
}

double CCircleAdapter::GetPerimeter() const
{
	auto radius = m_shape.getRadius();
	return 2 * std::numbers::pi * radius;
}

uint32_t CCircleAdapter::GetFillColor() const
{
	return m_shape.getFillColor().toInteger();
}

uint32_t CCircleAdapter::GetOutlineColor() const
{
	return m_shape.getOutlineColor().toInteger();
}

void CCircleAdapter::Draw(Render::ICanvas* canvas)
{
	if (sf::RenderWindow* window = dynamic_cast<sf::RenderWindow*>(canvas); window != nullptr)
	{
		window->draw(m_shape);
	}
	else throw std::invalid_argument(Errors::Circle::INVALID_CANVAS);
}

Shapes::CPoint CCircleAdapter::GetCenter() const
{
    auto pos = m_shape.getPosition();
    auto r = m_shape.getRadius();
    return { pos.x + r, pos.y + r };
}

double CCircleAdapter::GetRadius() const
{
	return m_shape.getRadius();
}

std::string CCircleAdapter::ToString() const
{
	return std::format(Constants::Circle::FORMAT, GetPerimeter(), GetArea());
}
