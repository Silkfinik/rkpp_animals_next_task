#include "../include/Animal.h"

__int16 Animal::count = 1;

void Animal::SetOwner(const Owner& _owner) {
    owner = _owner;
}

void Animal::SetAName(const std::string& _name) {
    a_name = _name;
}

void Animal::SetAge(const __int16& _age) {
    age = _age;
}

std::string Animal::GetAName() const {
    return a_name.value();
}

__int16 Animal::GetAge() const {
    return age.value();
}

Owner& Animal::GetOwnerRef() {
    return owner.value();
}

Owner Animal::GetOwner() const {
    return owner.value();
}

__int16 Animal::GetId() const {
    return id;
}

Animal& Animal::operator=(const Animal& other) {
    id = other.id;
    owner = other.owner;
    a_name = other.a_name;
    age = other.age;
    return *this;
}

Animal& Animal::operator=(Animal&& other) noexcept {
    id = std::move(other.id);
    owner = std::move(other.owner);
    a_name = std::move(other.a_name);
    age = std::move(other.age);
    return *this;
}