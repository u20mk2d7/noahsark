#include <cassert>
#include <cstdint>
#include <cstdlib>
#include <iostream>
#include <numeric> // for std::gcd in C++17

// https://en.wikipedia.org/wiki/Greatest_common_divisor
int gcd_naive(int a, int b) {
  int current_gcd = 1; // common divisior always has val 1
  for (int d = 2; d <= a && d <= b; d++) {
    if (a % d == 0 && b % d == 0) {
      if (d > current_gcd) {
        current_gcd = d;
      }
    }
  }
  return current_gcd;
}

// https://en.wikipedia.org/wiki/Euclidean_algorithm
int gcd_euclidean(int a, int b) {
  if (a == 0) {
    return b;
  }

  if (b == 0) {
    return a;
  }

  while (a != b) {
    if (a < b) {
      b = b - a;
    } else if (a > b) {
      a = a - b;
    }
  }
  return a;
}

// https://en.wikipedia.org/wiki/Euclidean_division
int gcd_euclidean_remainder(int a, int b) {
  if (a == 0) {
    return b;
  }
  if (b == 0) {
    return a;
  }

  int temp = 0;
  while (b != 0) {
    temp = b;
    b = a % b;
    a = temp;
  }

  return a;
}

int gcd_steins_bin(int a, int b) {
  // base cases (1)
  if (a == 0)
    return b;
  if (b == 0)
    return a;
  if (a == b)
    return a;

  if (a % 2 == 0) {
    if (b % 2 == 0) // a is even, b is even (2)
      return 2 * gcd_steins_bin(a / 2, b / 2);
    else // a is even, b is odd (3)
      return gcd_steins_bin(a / 2, b);
  } else {
    if (b % 2 == 0) // a is odd, b is even (3)
      return gcd_steins_bin(a, b / 2);
    else // a is odd, b is odd (4)
      return gcd_steins_bin(std::abs(a - b), std::min(a, b));
  }
}

// https://en.wikipedia.org/wiki/Binary_GCD_algorithm
// Count Trailing Zeros(ctz). This is a pedagogical example only;
// for efficiency use __builtin_ctzll() or similar.
static int ctz(uint64_t n) {
  if (n == 0)
    return 64; // Guard against infinite loop
  int s = 0, t;
  while ((t = n & 15) == 0) {
    n >>= 4;
    s += 4;
  }
  return s + ((0x12131210 >> 2 * t) & 3);
}

uint64_t gcd_Steins_binary_ver1(uint64_t u, uint64_t v) {
  // Identity #1: Base cases: gcd(0, v) = v, gcd(u, 0) = u, gcd(0, 0) = 0
  if (!u || !v)
    return u | v;

  // Identity #3: gcd(u, 2v) = gcd(u, v) when u is odd
  // Count shared factors of 2 and make 'u' odd
  int shift = ctz(u | v);
  u >>= ctz(u);

  while (v) { // Identity #4: making the loop's body branch-free except for its
              // exit condition v == 0

    // Identity #3: Stripping factors of 2 from v
    v >>= ctz(v);

    // Identity #4:
    uint64_t min = (u < v) ? u : v;
    uint64_t max = (u > v) ? u : v;
    u = min;
    v = max - min; // Difference of two odd numbers is always even
  }

  return u << shift; // Identity #2 Restore shared powers of 2
}

uint64_t gcd_Steins_binary_ver2(uint64_t u, uint64_t v) {
  // Identity #1: Base cases: gcd(0, v) = v, gcd(u, 0) = u, gcd(0, 0) = 0
  if (!u || !v)
    return u | v;

  // Identity #3: gcd(u, 2v) = gcd(u, v) when u is odd
  // Count shared factors of 2 and make 'u' odd
  int shift = __builtin_ctzll(u | v);
  u >>= __builtin_ctzll(u);

  // Identity #4: making the loop's body branch-free except for its exit
  // condition v == 0
  while (v) {

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

// https://en.wikipedia.org/wiki/Lehmer%27s_GCD_algorithm
int gcd_Lehmers(int a, int b) {}

// https://en.wikipedia.org/wiki/Sch%C3%B6nhage%E2%80%93Strassen_algorithm
uint64_t gcd_Schonhage_Strassen(uint64_t u, uint64_t v) {}

void stressTest() {}

int main() {
  /* stressTest();

  uint64_t a = 48, b = 18;
  std::cout << gcd_euclidean_remainder(a, b) << std::endl;
  std::cout << "steins_algo: " << gcd_steins_binary(a, b) << "\n";  // Output: 6
  std::cout << "std::gcd:     " << std::gcd(a, b) << "\n";          // Output: 6
  assert(gcd_euclidean(a, b) == gcd_euclidean_remainder(a, b));
  assert(gcd_naive(a, b) == gcd_steins_binary(a, b));

  std::cout << (10 | 3) << '\n';
  a >>= __builtin_ctzll(a); // = 110000 (48) -> ctz(a)=4 => a >> 4 -> 000011
    std::cout << a << '\n'; // 000011 (3)

*/

  int a, b;
  std::cin >> a >> b;
  std::cout << gcd_Steins_binary(a, b) << std::endl;
  return 0;
}
