#include "integerDoubler.hpp"
#include <cstdint>
#include <fstream>
#include <iostream>
#include <vector>

void integerDoubler(std::string input_file, std::string output_file) {
  std::ifstream in(input_file);
  if (!in) {
    std::cerr << "Invalid input path found for integerDoubler\n";
  }

  std::ofstream out(output_file);

  while (!in.eof()) {
    int32_t n = 0;
    in.read(reinterpret_cast<char *>(&n), std::ios::binary);
    n *= 2;
    out.write(reinterpret_cast<char *>(&n), 32);
  }
}
