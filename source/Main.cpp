#include "Main.hpp"

Main::Main(std::istream& in, std::ostream& out)
	: m_in(in), m_out(out) {}

void Main::Run()
{
	std::vector<std::unique_ptr<Shapes::IShape>> shapes;
	Render::Adapters::CRenderWindowAdapter window(800, 600, "Visualisation"); 
	CShapeParser parser;

	parser.Parse(m_in, shapes);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
		}
		
		window.clear();
		for (auto& shape : shapes)
		{
			shape->Draw(&window);
		}
		window.display();
	}
}

Main& Main::Instance()
{
	static Main instance{ std::cin, std::cout };
  return instance;	
}
