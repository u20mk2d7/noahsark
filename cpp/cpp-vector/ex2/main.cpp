/**
 * C++ program using the std::vector class.
 *
 * @author
 *   Wade Fagen-Ulmschneider <waf@illinois.edu>
 */

#include <iostream>
#include <vector>

int main() {
  std::vector<int> v;
  for (int i = 0; i < 100; i++) {
    v.push_back(i * i);
  }

  std::cout << v[12] << std::endl;

  return 0;
}
