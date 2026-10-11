#include "CRenderWindowAdapter.hpp"

using namespace Render::Adapters;

CRenderWindowAdapter::CRenderWindowAdapter(uint32_t width, uint32_t height, std::string title)
	: sf::RenderWindow(sf::VideoMode{ width, height }, title)
	, m_polygon(3) {}

void CRenderWindowAdapter::DrawPolygon(std::array<Shapes::CPoint, 3>& vertices)
{
	for (int i = 0; i < vertices.size(); i++)
	{
		m_polygon.setPoint(i, sf::Vector2f{
				static_cast<float>(vertices[i].x),
				static_cast<float>(vertices[i].y)
			});
	}
	draw(m_polygon);
}
