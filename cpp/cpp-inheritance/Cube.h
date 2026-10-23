/**
 * A `Cube` class inheriting from a `Shape`
 *
 * @author
 *   Wade Fagen-Ulmschneider <waf@illinois.edu>
 */

#pragma once

#include "HSLAPixel.h"
#include "Shape.h"

namespace uiuc {
class Cube : public Shape {
public:
  Cube(double width, uiuc::HSLAPixel color);
  double getVolume() const;

private:
  uiuc::HSLAPixel color_;
};
} // namespace uiuc