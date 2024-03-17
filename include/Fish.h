#ifndef FISH_H
#define FISH_H

#include "Animal.h"

class Fish final : public Animal {
 private:
  std::optional<int16_t> avg_depth;

 public:
  using Animal::Animal;

  Fish(Owner _owner, std::string _name, const int16_t& _age,
       const int16_t& _avg_depth)
      : Animal(std::move(_owner), std::move(_name), _age),
        avg_depth(_avg_depth){};

  Fish(const Fish& other) : Animal(other), avg_depth(other.avg_depth){};

  Fish(Fish&& other) noexcept
      : Animal(std::move(other)), avg_depth(std::move(other.avg_depth)){};

  Fish& operator=(const Fish& other);

  Fish& operator=(Fish&& other) noexcept;

  void MakeSound() const override;

  int16_t GetAvgDepth() const;

  void SetAvgDepth(const int16_t& _avg_depth);
};

#endif  // FISH_H