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

void staticcast(double a) {
  int b = static_cast<int>(a); // becomes integer number
  float largeValue = 3e10f;    // Way too big for a standard int

  if (largeValue > std::numeric_limits<int>::max() ||
      largeValue < std::numeric_limits<int>::lowest()) {
    // Handle the error safely before casting
    throw std::overflow_error("Float value is out of bounds for an int!");
  }

  int safeInt = static_cast<int>(largeValue);
}

void reinterpretcast(double a) {}
void constcast(double a) {}

void limits() {
  std::cout << "Min int: " << std::numeric_limits<int>::min() << "\n";
  std::cout << "Max int: " << std::numeric_limits<int>::max() << "\n";
}

void use_case() {
  int age = 30;
  float price = 9.99f;
  double precisionValue = 1.23456789;
  char initial = 'A';
  bool isAvailable = true;
  std::cout << "Age: " << age << ", Price: " << price
            << ", Precision Value: " << precisionValue
            << ", Initial: " << initial << ", Availability: " << isAvailable
            << std::endl;
}

int main() {
  int result = 5 + 3 * 2 > 10 && 4 - 1 < 5;
  std::cout << result << std::endl;
  return 0;
}