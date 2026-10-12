#pragma once

#include "CShapeParser.hpp"
#include "CRenderWindowAdapter.hpp"

#include <iostream>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>

namespace Constants
{
	inline constexpr auto WINDOW_TITLE = "Visualisation";
}


class Main
{
public:
  static Main& Instance();

  void Run();

  Main& operator=(const Main&) = delete;
	Main(const Main&) = delete;

protected:
	Main(std::istream& in, std::ostream& out);
	
private:	
	std::istream& m_in;
  std::ostream& m_out;
};
