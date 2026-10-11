#pragma once

#include "ICanvas.hpp"
#include <cstdint>
#include <string>

namespace Shapes
{

class IShape
{
public:
  virtual ~IShape() = default;
  
  virtual double GetArea() const = 0;
  virtual double GetPerimeter() const = 0;
  virtual std::string ToString() const = 0;
  virtual uint32_t GetFillColor() const = 0;
  virtual uint32_t GetOutlineColor() const = 0;
  virtual void Draw(Render::ICanvas* canvas) = 0;
};

}
