#pragma once

#include "ICanvas.hpp"
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/ConvexShape.hpp>

namespace Render::Adapters
{

class CRenderWindowAdapter : public ICanvas, public sf::RenderWindow
{
public:
	CRenderWindowAdapter(uint32_t width, uint32_t height, std::string title);

	void DrawPolygon(std::array<Shapes::CPoint, 3>& vertices) override;

private:
	sf::ConvexShape m_polygon;
};

}
