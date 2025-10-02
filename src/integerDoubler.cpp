#include "integerDoubler.hpp"
#include <cstdint>
#include <fstream>
#include <iostream>
#include <vector>

void integerDoubler(std::string input_file, std::string output_file) {
  std::ifstream in(input_file);
  if (!in) {
    std::cerr << "Invalid input path found for integerDoubler\n";
    return;
  }

  std::ofstream out(output_file);

  while (!in.eof()) {
    int32_t n = 0;
    in.read(reinterpret_cast<char *>(&n), 32);
    int64_t n2 = static_cast<int64_t>(n) * 2;
    std::cout << "2x: " << n << " " << n2 << "\n";
    out.write(reinterpret_cast<char *>(&n2), 64);
  }
}
