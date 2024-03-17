#include "../include/Dog.h"

#include <iostream>


void Dog::MakeSound() const { std::cout << "Woof!" << std::endl; }

void Dog::SetBreed(const std::string& _breed) { breed = _breed; }

std::string Dog::GetBreed() const { return breed.value(); }

Dog& Dog::operator=(const Dog& other) {
  Animal::operator=(other);
  breed = other.breed;
  return *this;
}

Dog& Dog::operator=(Dog&& other) noexcept {
  Animal::operator=(std::move(other));
  breed = std::move(other.breed);
  return *this;
}