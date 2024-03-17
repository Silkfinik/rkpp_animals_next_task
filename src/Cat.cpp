#include "../include/Cat.h"

#include <iostream>


void Cat::MakeSound() const { std::cout << "Meow!" << std::endl; }

void Cat::SetColor(const std::string& _color) { color = _color; }

std::string Cat::GetColor() const { return color.value(); }

Cat& Cat::operator=(const Cat& other) {
  Animal::operator=(other);
  color = other.color;
  return *this;
}

Cat& Cat::operator=(Cat&& other) noexcept {
  Animal::operator=(std::move(other));
  color = std::move(other.color);
  return *this;
}