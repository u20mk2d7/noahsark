/**
 * C++ program using the & operator to find the address of a variable in memory.
 *
 * @author
 *   Wade Fagen-Ulmschneider <waf@illinois.edu>
 */

#include <format>
#include <iostream>
#include <memory>
#include <stdexcept>
#include <string>
#include <string_view>

struct Base {
  virtual ~Base() = default;
  virtual double calcArea() const noexcept = 0;
};

struct Rectangle : Base {
  double a_{0.0};
  double b_{0.0};
  Rectangle() : a_{0}, b_{0} {}
  Rectangle(double a, double b) : a_(a), b_(b) {}
  double calcArea() const noexcept override { return a_ * b_; }

  void crashing_noexcept() noexcept {
    throw std::runtime_error("This will crash the program!");
  }
};

int main() {
  int num = 7;

  std::cout << "Value: " << num << std::endl;
  std::cout << "Address: " << &num << std::endl;
  std::cout << std::format("{} {}! {}", "Hello", "world", "something")
            << std::endl; // C++20+: std::format

  std::unique_ptr<Rectangle> retangle = std::make_unique<Rectangle>();
  retangle->crashing_noexcept();

  return 0;
}
