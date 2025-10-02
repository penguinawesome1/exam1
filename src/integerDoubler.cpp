#include "integerDoubler.hpp"
#include <fstream>
#include <iostream>
#include <vector>

void integerDoubler(std::string input_file, std::string output_file) {
  std::ifstream in(input_file, std::ios::binary);
  if (!in) {
    std::cerr << "Invalid input path found for integerDoubler\n";
    return;
  }

  std::ofstream out(output_file, std::ios::binary);

  in.seekg(1);

  while (!in.eof()) {
    int n = 0;
    in.read(reinterpret_cast<char *>(&n), sizeof(int));
    n *= 2;
    out.write(reinterpret_cast<char *>(&n), sizeof(int));
  }
}
