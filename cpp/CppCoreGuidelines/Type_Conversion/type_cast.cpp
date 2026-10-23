/*
-Wconversion: This is essential. It flags implicit conversions that may alter a
value (e.g., double to int, or unsigned to signed).

-Wshadow: This prevents "shadowing," where a local variable hides a member
variable or a global, which often leads to accidental use of the wrong type or
scope.

-Werror: Force the compiler to stop the build if any warning occurs. This forces
you to address potential conversion issues immediately rather than leaving
"TODOs" in your code. Sanitizer-Driven Development

#TODO:
dynamic_cast

static_cast

reinterpret_cast

const_cast
*/
#include <iostream>
#include <limits>
#include <numeric>

void dynamiccast(double a) {}

void staticcast(double a) {}

void reinterpretcast(double a) {}
void constcast(double a) {}

void limits() {
  std::cout << "Min int: " << std::numeric_limits<int>::min() << "\n";
  std::cout << "Max int: " << std::numeric_limits<int>::max() << "\n";
}

int main() { return 0; }