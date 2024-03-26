#include <vector>

#include "../src/funcs.cpp"

int main() {
  std::vector<Animal*> pets;
  try {
    ReadFile("input.txt", pets);
    Menu(pets);
  } catch (const std::runtime_error& err) {
    std::cerr << "Caught a runtime error: " << err.what() << std::endl;
  } catch (...) {
    std::cerr << "Caught an unknown error" << std::endl;
  }
  return 0;
}