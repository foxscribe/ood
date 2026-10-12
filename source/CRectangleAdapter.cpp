#include "CRectangleAdapter.hpp"

using namespace Shapes::Adapters;

CRectangleAdapter::CRectangleAdapter(CPoint pos, float width, float height, uint32_t fill, uint32_t outline)
	: m_shape({ width, height })
{
	m_shape.setPosition(pos.x, pos.y);
	m_shape.setFillColor(sf::Color(fill));
	m_shape.setOutlineColor(sf::Color(outline));
}

double CRectangleAdapter::GetArea() const
{
	auto dimensions = m_shape.getSize();
	return dimensions.x * dimensions.y;
}

double CRectangleAdapter::GetPerimeter() const
{
	auto dimensions = m_shape.getSize();
	return 2 * (dimensions.x + dimensions.y);
}

uint32_t CRectangleAdapter::GetFillColor() const
{
	return m_shape.getFillColor().toInteger();
}

uint32_t CRectangleAdapter::GetOutlineColor() const
{
	return m_shape.getOutlineColor().toInteger();
}

void CRectangleAdapter::Draw(Render::ICanvas* canvas)
{
	if (sf::RenderWindow* window = dynamic_cast<sf::RenderWindow*>(canvas); window != nullptr)
	{
		window->draw(m_shape);
	}
	else throw std::invalid_argument(Errors::Rectangle::INVALID_CANVAS);
}

Shapes::CPoint CRectangleAdapter::GetLeftTop() const
{
	auto pos = m_shape.getPosition();
	return { pos.x, pos.y };
}

Shapes::CPoint CRectangleAdapter::GetRightBottom() const
{
	auto pos = m_shape.getPosition();
	auto size = m_shape.getSize();
	return { pos.x + size.x, pos.y + size.y };
}

double CRectangleAdapter::GetWidth() const
{
	return m_shape.getSize().x;
}

double CRectangleAdapter::GetHeight() const
{
  return m_shape.getSize().y;
}

std::string CRectangleAdapter::ToString() const
{
  return std::format(Constants::Rectangle::FORMAT, GetPerimeter(), GetArea());
}
