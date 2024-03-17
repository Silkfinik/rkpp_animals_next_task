#include "../include/Fish.h"

#include <iostream>


void Fish::MakeSound() const { std::cout << "Blub!" << std::endl; }

void Fish::SetAvgDepth(const int16_t& _avg_depth) { avg_depth = _avg_depth; }

int16_t Fish::GetAvgDepth() const { return avg_depth.value(); }

Fish& Fish::operator=(const Fish& other) {
  Animal::operator=(other);
  avg_depth = other.avg_depth;
  return *this;
}

Fish& Fish::operator=(Fish&& other) noexcept {
  Animal::operator=(std::move(other));
  avg_depth = std::move(other.avg_depth);
  return *this;
}