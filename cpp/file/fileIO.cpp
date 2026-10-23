#include <fstream>
#include <iostream>
#include <string>

void readFile(const std::string &pathToFile) {
  std::ifstream file(pathToFile);
  if (!file.is_open()) {
    std::cerr << "Error load file: " << pathToFile << '\n';
  }

  std::string line;
  while (std::getline(file, line)) {
    std::cout << line << '\n';
  }

  file.close();
}

int main(int argc, char **argv) {
  const std::string pathToFile(argv[1]);
  readFile(pathToFile);
  return 0;
}
