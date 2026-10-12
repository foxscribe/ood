#pragma once

#include "IShape.hpp"

#include <iostream>
#include <memory>
#include <vector>

namespace ShapeNames
{
	inline constexpr auto CIRCLE = "circle";
	inline constexpr auto RECTANGLE = "rectangle";
	inline constexpr auto TRIANGLE = "triangle";
}

namespace Errors::Parser
{
    inline constexpr auto UNKNOWN_SHAPE = "unknown shape type";
    inline constexpr auto INVALID_PARAMETERS = "invalid parameters";
}

namespace Constants
{
    inline constexpr auto DEFAULT_COLOR = 0x00FF00FF;
}

class CShapeParser
{
	using VectorOfShapes = std::vector<std::unique_ptr<Shapes::IShape>>;

public:
  CShapeParser() = default;

	static void Parse(std::istream& input, VectorOfShapes& shapes);

private:
	static bool CheckStream(const std::istream& input);
	static void ParseCircle(std::istream& input, VectorOfShapes& shapes);
	static void ParseLine(std::istream& input, VectorOfShapes& shapes);
	static void ParseRectangle(std::istream& input, VectorOfShapes& shapes);
	static void ParseTriangle(std::istream& input, VectorOfShapes& shapes);
};
