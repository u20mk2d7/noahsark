#include <algorithm>
#include <iostream>
#include <vector>

int main() {
  std::vector<int> v{3, -4, 2, -8, 15, 267};
  auto print = [](const int &n) { std::cout << n << ' '; };

  std::cout << "before:\t";
  std::for_each(v.cbegin(), v.cend(), print);
  std::cout << '\n';
  // // Passing the lambda directly as the third argument
  std::for_each(v.cbegin(), v.cend(),
                [](const int &n) { std::cout << n << ' '; });

  return 0;
}
