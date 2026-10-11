#pragma once

#include "IShape.hpp"
#include "CPoint.hpp"

namespace Shapes
{

class ICircle : public IShape
{
public:
  virtual CPoint GetCenter() const = 0;
  virtual double GetRadius() const = 0;
};
  
}
