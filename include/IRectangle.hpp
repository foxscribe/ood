#pragma once

#include "IShape.hpp"
#include "CPoint.hpp"

namespace Shapes
{

class IRectangle : public IShape
{
public:
	virtual CPoint GetLeftTop() const = 0;
  virtual CPoint GetRightBottom() const = 0;
  virtual double GetWidth() const = 0;
	virtual double GetHeight() const = 0;
};
  
}
