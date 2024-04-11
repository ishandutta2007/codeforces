#include <iostream>

int main() {
  srand(233543733);
  int cnt = 0;
  for (int it = 0; it < 100000; ++it) {
    std::cout << rand() % 10 << std::endl;
    std::string s;
    std::getline(std::cin, s);
    if (s == "no") ++cnt;
    if (s == "worse" || s == "no way" || s == "terrible" || s == "go die in a hole" || s == "are you serious?" || s == "don't even") {
      std::cout << "grumpy" << std::endl;
      return 0;
    }
    if (s == "cool" || s == "don't think so" || s == "not bad" || s == "don't touch me!" || s == "great!") {
      std::cout << "normal" << std::endl;
      return 0;
    }
  }
  if (cnt > 40000) {
    std::cout << "normal" << std::endl;
  } else {
    std::cout << "grumpy" << std::endl;
  }
  return 0;
}