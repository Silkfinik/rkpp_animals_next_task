#include "../include/Pig.h"
#include <iostream>

void Pig::MakeSound() const {
    std::cout << "Oink!" << std::endl;
}

void Pig::SetPigletSize(const __int16& _piglet_size) {
    piglet_size = _piglet_size;
}

__int16 Pig::GetPigletSize() const {
    return piglet_size.value();
}

Pig& Pig::operator=(const Pig& other) {
    Animal::operator=(other);
    piglet_size = other.piglet_size;
    return *this;
}

Pig& Pig::operator=(Pig&& other) noexcept {
    Animal::operator=(std::move(other));
    piglet_size = std::move(other.piglet_size);
    return *this;
}