#include "../include/Parrot.h"
#include <iostream>

void Parrot::MakeSound() const {
    std::cout << "Squawk!" << std::endl;
}

void Parrot::SetLexicon(const __int16& _lexicon) {
    lexicon = _lexicon;
}

__int16 Parrot::GetLexicon() const {
    return lexicon.value();
}

Parrot& Parrot::operator=(const Parrot& other) {
    Animal::operator=(other);
    lexicon = other.lexicon;
    return *this;
}

Parrot& Parrot::operator=(Parrot&& other) noexcept {
    Animal::operator=(std::move(other));
    lexicon = std::move(other.lexicon);
    return *this;
}