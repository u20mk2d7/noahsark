#include <cassert>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <vector>

uint64_t fib(uint64_t n) {
  if (n <= 1)
    return n;

  return (fib(n - 1) + fib(n - 2));
}

// https://en.wikipedia.org/wiki/Fibonacci_sequence
// Binet's floating-point precision loss
uint64_t fib_binet(uint64_t n) {
  double phi = (1.0 + std::sqrt(5.0)) / 2.0;
  double psi = (1.0 - std::sqrt(5.0)) / 2.0;
  uint64_t Fn = (std::pow(phi, n) - std::pow(psi, n)) / (phi - psi);
  return Fn;
}

uint64_t fib_arr(uint64_t n) {
  // base case
  if (n < 2) {
    return n;
  }

  if (n < 0 || n >= 94)
    return 0; // Out of 64-bit bounds

  std::vector<uint64_t> F(n + 1);
  F[0] = 0;
  F[1] = 1;

  for (uint64_t i = 2; i <= n; ++i) {
    F[i] = F[i - 1] + F[i - 2];
  }
  return F[n];
}

void test_solution() {
  assert(fib_arr(3) == 2);
  assert(fib_arr(10) == 55);
  for (uint64_t n = 0; n < 20; ++n) {
    assert(fib_arr(n) == fib(n));
  }
}

int main() {
  uint64_t n = 0;
  std::cin >> n;

  std::cout << fib_arr(n) << '\n';
  // test_solution();
  return 0;
}
