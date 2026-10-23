#include <cassert>
#include <cstdint>
#include <cstdlib>
#include <iostream>
#include <numeric>

uint64_t lcm_naive(int a, int b) {
  for (long l = 1; l <= (uint64_t)a * b; ++l)
    if (l % a == 0 && l % b == 0)
      return l;

  return (uint64_t)a * b;
}

// https://en.wikipedia.org/wiki/Binary_GCD_algorithm
uint64_t gcd_Steins_binary(uint64_t u, uint64_t v) {
  // Identity #1: Base cases: gcd(0, v) = v, gcd(u, 0) = u, gcd(0, 0) = 0
  if (!u || !v)
    return u | v;

  // Identity #3: gcd(u, 2v) = gcd(u, v) when u is odd
  // Count shared factors of 2 and make 'u' odd
  int shift = __builtin_ctzll(u | v); // int shift = ctz(u | v);
  u >>= __builtin_ctzll(u);           // u >>= ctz(u);

  while (v) { // Identity #4: making the loop's body branch-free except for its
              // exit condition v == 0

    // Identity #3: Stripping factors of 2 from v
    v >>= __builtin_ctzll(v); // v >>= ctz(v);

    // Identity #4:
    uint64_t min = std::min(u, v); // min = (u < v) ? u : v;
    uint64_t max = std::max(u, v); // max = (u > v) ? u : v;
    u = min;
    v = max - min; // Difference of two odd numbers is always even
  }

  return u << shift; // Identity #2 Restore shared powers of 2
}

uint64_t lcm_gcd_steins(int a, int b) {
  if (a == 0 || b == 0)
    return 0;
  return b * (a / gcd_Steins_binary(a, b));
}

uint64_t std_lcm(uint64_t a, uint64_t b) { return (a * b) / std::gcd(a, b); }

int main() {
  int a, b;
  std::cin >> a >> b;
  std::cout << lcm_gcd_steins(a, b) << std::endl;
  return 0;
}
