#include "CShapeParser.hpp"

#include "CCircleAdapter.hpp"
#include "CRectangleAdapter.hpp"
#include "CConvexAdapter.hpp"

#include <cstdint>
#include <iostream>
#include <memory>
#include <sstream>
#include <stdexcept>
#include <string>
#include <unordered_map>
#include <vector>

void CShapeParser::Parse(std::istream& input, VectorOfShapes& shapes)
{
    using ParseFunc = void(*)(std::istream&, VectorOfShapes& shapes);
    static const std::unordered_map<std::string, ParseFunc> parsers = {
        {ShapeNames::CIRCLE,    ParseCircle},
        {ShapeNames::RECTANGLE, ParseRectangle},
        {ShapeNames::TRIANGLE,  ParseTriangle}
    };

	std::string line;

	while (std::getline(input, line))
	{
		if (line.empty())
		{
			continue;
		}

		std::stringstream stream(line);
		std::string shapeType;
		stream >> shapeType;

		auto it = parsers.find(shapeType);
        if (it != parsers.end())
        {
            it->second(stream, shapes);
        }
        else
        {
					throw std::invalid_argument(Errors::Parser::UNKNOWN_SHAPE);
        }
	}
}

bool CShapeParser::CheckStream(const std::istream& input)
{
	if (input.fail())
	{
		throw std::invalid_argument(Errors::Parser::INVALID_PARAMETERS);
		return false;
	}

	return true;
}

void CShapeParser::ParseCircle(std::istream& input, VectorOfShapes& shapes)
{
	Shapes::CPoint center;
	double radius;
	uint32_t outlineColor = Constants::DEFAULT_COLOR;
	uint32_t fillColor = Constants::DEFAULT_COLOR;

	if (!(input >> center.x >> center.y >> radius))
	{
		CheckStream(input);
		return;
	}

	uint32_t colorValue;
	if (input >> std::hex >> colorValue)
	{
		outlineColor = colorValue;
	}

	if (input >> std::hex >> colorValue)
	{
		fillColor = colorValue;
	}

	auto circle = std::make_unique<Shapes::Adapters::CCircleAdapter>(center, radius, outlineColor, fillColor);
	shapes.push_back(std::move(circle));
}

void CShapeParser::ParseRectangle(std::istream& input, VectorOfShapes& shapes)
{
	Shapes::CPoint startPoint;
	double width, height;
	uint32_t outlineColor = Constants::DEFAULT_COLOR;
	uint32_t fillColor = Constants::DEFAULT_COLOR;

	if (!(input >> startPoint.x >> startPoint.y >> width >> height))
	{
		CheckStream(input);
		return;
	}

	uint32_t colorValue;
	if (input >> std::hex >> colorValue)
	{
		outlineColor = colorValue;
	}

	if (input >> std::hex >> colorValue)
	{
		fillColor = colorValue;
	}

	auto rectangle = std::make_unique<Shapes::Adapters::CRectangleAdapter>(startPoint, width, height, outlineColor, fillColor);
	shapes.push_back(std::move(rectangle));
}

void CShapeParser::ParseTriangle(std::istream& input, VectorOfShapes& shapes)
{
	Shapes::CPoint point1;
	Shapes::CPoint point2;
	Shapes::CPoint point3;
	uint32_t outlineColor = Constants::DEFAULT_COLOR;
	uint32_t fillColor = Constants::DEFAULT_COLOR;

	if (!(input >> point1.x >> point1.y >> point2.x >> point2.y >> point3.x >> point3.y))
	{
		CheckStream(input);
		return;
	}

	uint32_t colorValue;
	if (input >> std::hex >> colorValue)
	{
		outlineColor = colorValue;
	}

	if (input >> std::hex >> colorValue)
	{
		fillColor = colorValue;
	}

	auto triangle = std::make_unique<Shapes::Adapters::CConvexAdapter>(point1, point2, point3, outlineColor, fillColor);
	shapes.push_back(std::move(triangle));
}
