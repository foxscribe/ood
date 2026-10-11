#pragma once

#include "ITriangle.hpp"
#include "Vector2ToCPoint.hpp"

#include <SFML/Graphics/ConvexShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

namespace Shapes::Adapters
{
  
class CConvexAdapter : public ITriangle
{
public:
	CConvexAdapter(CPoint v1, CPoint v2, CPoint v3, uint32_t fill, uint32_t outline);

	double GetArea() const override;
	double GetPerimeter() const override;
	std::string ToString() const override;
	uint32_t GetFillColor() const override;
	uint32_t GetOutlineColor() const override;
	void Draw(Render::ICanvas* canvas) override;

  CPoint GetVertex1() const override;
  CPoint GetVertex2() const override;
  CPoint GetVertex3() const override;
  
private:
  sf::ConvexShape m_shape;
};
  
}
