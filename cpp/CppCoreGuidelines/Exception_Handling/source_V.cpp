#include <iostream>
#include <memory>
#include <vector>

class A {
public:
  A() { std::cout << "A()\n"; }
  ~A() { std::cout << "~A()\n"; }
};

class B {
public:
  B() { std::cout << "B()\n"; }
  ~B() { std::cout << "~B()\n"; }
};

class Test {
private:
  A *pA;
  B b{};
  int *pInt{};
  char *pStr{};
  int *pArr{};

public:
  Test() {
    std::cout << "Test()\n";
    pA = new A;
    pInt = new int;
    throw std::runtime_error("Failed to initialize");
    pStr = new char[10];
    pArr = new int[50];
  }

  ~Test() {
    std::cout << "~Test()\n";
    delete pA;
    delete pInt;
    delete pStr;
    delete pArr;
  }
};

int main() {
  try {
    Test t;
  } catch (std::runtime_error &ex) {
    std::cout << "[ERROR]: " << ex.what() << '\n';
  }
  return 0;
}
