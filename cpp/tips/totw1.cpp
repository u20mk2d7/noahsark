// https://abseil.io/tips/1

#include <absl/strings/str_format.h>
#include <cstdio>
#include <iostream>
#include <string>

// C Convention
void TakesCharStar(const char *s) { // Legacy C API
  std::cout << s << "\n";           // Relies on '\0' to know where to stop!
}

// Old Standard C++ convention
void TakesString(const std::string &s) {}

// string_view C++ conventions
void TakesStringView1(absl::string_view s) {} // Abseil
void TakesStringView(std::string_view s) {}   // C++17

void AlreadyHasString(const std::string &s) {
  TakesCharStar(s.c_str()); // explicit conversion
}

void AlreadyHasString1(const std::string &s) {
  TakesStringView(s); // no explicit conversion; convenient!
}

void AlreadyHasCharStar(const char *s) {
  TakesStringView(s); // no copy; efficient!
}

int main() {
  std::string full_str = "hello_world_secret_data";
  std::string_view sv = full_str;         // Covers the whole string
  std::string_view sub = sv.substr(0, 5); // "hello"
  std::string temp(sub);
  // CRITICAL BUG:
  // sub.data() points to the 'h' in "hello".
  // But right after 'o' (at index 5), there is an underscore '_', NOT '\0'!
  // TakesCharStar will keep printing past "hello" into "_world_secret_data"
  // until it randomly finds a null byte in memory.
  std::cout << sub << '\n';
  TakesCharStar(temp.c_str());

  return 0;
}
