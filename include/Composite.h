#ifndef COMPOSITE_H
#define COMPOSITE_H

#include <vector>

#include "Animal.h"

class CompositeAnimal {
 private:
  std::vector<Animal*> zoo;

 public:
  void addAnimal(Animal* pet) { zoo.push_back(pet); }
  std::vector<Animal*> getZoo() { return zoo; }
};

#endif  // COMPOSITE_H