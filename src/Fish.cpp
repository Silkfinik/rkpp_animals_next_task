#include "../include/Fish.h"
#include <iostream>

void Fish::MakeSound() const {
    std::cout << "Blub!" << std::endl;
}

void Fish::SetAvgDepth(const __int16& _avg_depth) {
    avg_depth = _avg_depth;
}

__int16 Fish::GetAvgDepth() const {
    return avg_depth.value();
}

Fish& Fish::operator=(const Fish& other) {
    static_cast<Animal&>(*this) = other;
    avg_depth = other.avg_depth;
    return *this;
}

Fish& Fish::operator=(Fish&& other) noexcept {
    static_cast<Animal&>(*this) = std::move(other);
    avg_depth = std::move(other.avg_depth);
    return *this;
}