#include <iostream>
#include <memory>
#include <random>

// Nested Exceptions
//
class Test {
private:
public:
  Test() { std::cout << "Test(): Acquire resource\n"; }
  ~Test() { std::cout << "~Test(): Release resource\n"; };
};

void ProcesRecords(int count) {
  std::unique_ptr<Test> t(new Test);
  if (count < 10) {
    throw std::out_of_range("Count should be greater than 10");
  }

  std::vector<int> p;
  p.reserve(count);
  std::vector<int> records;
  records.reserve(count);

  for (int i = 0; i < count; ++i) {
    records.push_back(i);
  }

  std::default_random_engine eng;
  std::bernoulli_distribution dist;
  for (int i = 0; i < count; ++i) {
    try {
      std::cout << "Processing record #: " << i << " ";
      if (!dist(eng)) {
        throw std::runtime_error("Could not process the record");
      }
      std::cout << '\n';
    } catch (std::runtime_error &ex) {
      std::cout << "[ERROR]: " << ex.what() << '\n';
    }
  }
}

int main() {
  try {
    ProcesRecords(10);
  } catch (std::out_of_range &e) {
    std::cout << e.what() << std::endl;
  } catch (std::runtime_error &e) {
    std::cout << e.what() << std::endl;
  }

  return 0;
}
