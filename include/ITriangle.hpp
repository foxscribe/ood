#pragma once

#include "IShape.hpp"
#include "CPoint.hpp"

namespace Shapes
{

class ITriangle : public IShape
{
public:
  virtual CPoint GetVertex1() const = 0;
  virtual CPoint GetVertex2() const = 0;
  virtual CPoint GetVertex3() const = 0;
};
  
}
