#include <cassert>
#include <cmath>
#include <iostream>
#include <random>
#include <vector>

uint64_t get_fibonacci_huge_naive(uint64_t n, uint64_t m) {
  if (n <= 1)
    return n;

  uint64_t previous = 0;
  uint64_t current = 1;

  for (uint64_t i = 0; i < n - 1; ++i) {
    uint64_t tmp_previous = previous;
    previous = current;
    current = tmp_previous + current;
  }

  return current % m;
}

// https://en.wikipedia.org/wiki/Pisano_period
uint64_t pisano_period(uint64_t m) {
  if (m <= 1)
    return 1;

  uint64_t prev = 0;
  uint64_t curr = 1;

  for (uint64_t i = 0; i < 6 * m; ++i) {
    uint64_t temp = (prev + curr) % m;
    prev = curr;
    curr = temp;

    if (prev == 0 && curr == 1) {
      return i + 1; // return period length
    }
  }

  return 0;
}

uint64_t fib_modulo_pisano_period(uint64_t n, uint64_t m) {
  if (m == 0 || m == 1)
    return 0;

  uint64_t period = pisano_period(m);

  uint64_t n_prime = n % period;

  if (n_prime < 2)
    return n_prime;

  uint64_t prev = 0;
  uint64_t curr = 1;

  for (uint64_t i = 2; i <= n_prime; ++i) {
    uint64_t temp = (prev + curr) % m;
    prev = curr;
    curr = temp;
  }

  return curr;
}

void stress_test() {
  // 1. Seed the engine with hardware entropy (std::random_device)
  std::random_device rd;

  // 2. Initialize the Mersenne Twister generator
  std::mt19937 gen(rd());

  // 3. Define the distribution range [inclusive, inclusive]
  std::uniform_int_distribution<uint64_t> distrib_n(0, 100);
  // Restrict m to >= 1 to prevent division by zero
  std::uniform_int_distribution<uint64_t> distrib_m(1, 100);

  for (int i = 0; i < std::pow(10, 2); ++i) {
    // 4. Generate a random number
    uint64_t n = distrib_n(gen);
    uint64_t m = distrib_m(gen);

    assert(get_fibonacci_huge_naive(n, m) == fib_modulo_pisano_period(n, m));
  }
}

int main() {
  // stress_test();
  uint64_t n, m;
  std::cin >> n >> m;
  std::cout << fib_modulo_pisano_period(n, m) << '\n';

  return 0;
}
