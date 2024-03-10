#include "../include/Dog.h"
#include <iostream>

void Dog::MakeSound() const {
    std::cout << "Woof!" << std::endl;
}

void Dog::SetBreed(const std::string& _breed) {
    breed = _breed;
}

std::string Dog::GetBreed() const {
    return breed.value();
}

Dog& Dog::operator=(const Dog& other) {
    static_cast<Animal&>(*this) = other;
    breed = other.breed;
    return *this;
}

Dog& Dog::operator=(Dog&& other) noexcept {
    static_cast<Animal&>(*this) = std::move(other);
    breed = std::move(other.breed);
    return *this;
}