#include <iostream>
#include <vector>

template <typename T>
void printVectorInline(std::vector<T>& v) {
  for (auto& d : v) {
    std::cout << d << "  ";
  }
  std::cout << std::endl;
}

