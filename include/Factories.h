#include "Cat.h"
#include "Dog.h"
#include "Fish.h"
#include "Owner.h"
#include "Parrot.h"
#include "Pig.h"


class AnimalFactry {
 public:
  virtual Animal* CreateAnimal(Owner owner, std::string name, int16_t age) = 0;
};

class CatFactory : public AnimalFactry {
 public:
  Animal* CreateAnimal(Owner owner, std::string name, int16_t age) override {
    return new Cat(owner, name, age);
  }
};

class DogFactory : public AnimalFactry {
 public:
  Animal* CreateAnimal(Owner owner, std::string name, int16_t age) override {
    return new Dog(owner, name, age);
  }
};

class FishFactory : public AnimalFactry {
 public:
  Animal* CreateAnimal(Owner owner, std::string name, int16_t age) override {
    return new Fish(owner, name, age);
  }
};

class ParrotFactory : public AnimalFactry {
 public:
  Animal* CreateAnimal(Owner owner, std::string name, int16_t age) override {
    return new Parrot(owner, name, age);
  }
};

class PigFactory : public AnimalFactry {
 public:
  Animal* CreateAnimal(Owner owner, std::string name, int16_t age) override {
    return new Pig(owner, name, age);
  }
};