#include <algorithm>
#include <cstddef>
#include <iostream>
#include <iterator>
#include <ranges>
#include <span>
#include <vector>

void foo() {
  std::vector<int> v{1, 2, 3, 4, 5, 6};
  for (const auto &x : v) { /* do something with the value of x */
  }

  for (auto &x : v) { /* modify x */
  }

  // Classic C++11/17 compliant way to express the exact same intent
  std::for_each(v.cbegin(), v.cend(), [](int x) { std::cout << x << ' '; });

  std::cout << "3. Sequential ranges::for_each:\n";
  // Expresses Intent: Applying a specific function/lambda to all elements
  // sequentially
  std::ranges::for_each(v, [](int x) { std::cout << x << ' '; });
  std::cout << "\n\n";

  std::cout << "4. Parallel std::for_each:\n";
  // Expresses Intent: Execution order DOES NOT matter. Run this in parallel!
  // Note: Parallel algorithms require the classic (begin, end) syntax or
  // standard std::for_each
  std::for_each(std::execution::par, v.begin(), v.end(), [](int x) {
    // Safe to execute concurrently because there are no side effects between
    // elements (Note: std::cout inside parallel loops can jumble output text,
    // but it shows the execution mechanics working)
    // In your hot-path, you would do lock-free calculations here.
  });
}

int main() {
  foo();
  return 0;
}
