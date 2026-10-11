#pragma once

#include "ICircle.hpp"

#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

namespace Shapes::Adapters
{
  
class CCircleAdapter : public ICircle
{
public:
	CCircleAdapter(CPoint pos, double r, uint32_t fill, uint32_t outline);

	double GetArea() const override;
	double GetPerimeter() const override;
	std::string ToString() const override;
	uint32_t GetFillColor() const override;
	uint32_t GetOutlineColor() const override;
	void Draw(Render::ICanvas* canvas) override;

	CPoint GetCenter() const override;
	double GetRadius() const override;
  
private:
  sf::CircleShape m_shape;
};
  
}
