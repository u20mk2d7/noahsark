#include <iostream>
#include <string>
#include <string_view>

int main() {
  const std::string sv = " ho st= www.binance.com n";
  auto start = sv.find_first_not_of(" \t\r\n");
  auto end = sv.find_last_not_of(" \t\r\n");
  std::cout << start << '\n';
  std::cout << end << '\n';
  std::cout << sv.substr(start, end - start + 1) << '\n';
}
