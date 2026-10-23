#include <algorithm>
#include <boost/filesystem.hpp>
#include <dlfcn.h>
#include <iostream>
#include <iterator>
#include <jemalloc/jemalloc.h>

#include <iostream>
#include <jemalloc/jemalloc.h>

// Callback function to write stats to standard output (or a log file)
void write_stats(void *opaque, const char *str) {
  // You can write to your low-latency logging framework here
  std::cout << str;
}

void printJemallocStats() {
  std::cout << "=== JEMALLOC STATS START ===\n";
  // The flags string can include things like 'J' (omit general stats), 'g'
  // (omit central stats), etc. Passing nullptr uses default settings.
  malloc_stats_print(write_stats, nullptr, "");
  std::cout << "=== JEMALLOC STATS END ===\n";
}

int main() {
  // Verify it's active
  const char *version = nullptr;
  size_t sz = sizeof(version);
  if (mallctl("version", &version, &sz, nullptr, 0) == 0) {
    std::cout << "jemalloc is ACTIVE. Version: " << version << '\n';
  }

  // Print detailed stats
  printJemallocStats();

  return 0;
}