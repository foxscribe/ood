#pragma once

#include "IShape.hpp"

#include <iostream>
#include <memory>
#include <vector>

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
