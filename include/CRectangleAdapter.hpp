#pragma once

#include "IRectangle.hpp"

#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

namespace Shapes::Adapters
{
  
class CRectangleAdapter : public IRectangle
{
public:
	CRectangleAdapter(CPoint pos, float width, float height, uint32_t fill, uint32_t outline);

	double GetArea() const override;
	double GetPerimeter() const override;
	std::string ToString() const override;
	uint32_t GetFillColor() const override;
	uint32_t GetOutlineColor() const override;
	void Draw(Render::ICanvas* canvas) override;

  CPoint GetLeftTop() const override;
  CPoint GetRightBottom() const override;
  double GetWidth() const override;
	double GetHeight() const override;
  
private:
  sf::RectangleShape m_shape;
};
  
}
