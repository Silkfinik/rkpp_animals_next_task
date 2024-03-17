#ifndef DOG_H
#define DOG_H

#include "Animal.h"

class Dog final : public Animal {
 private:
  std::optional<std::string> breed;

 public:
  using Animal::Animal;

  Dog(Owner _owner, std::string _name, const int16_t& _age, std::string _breed)
      : Animal(std::move(_owner), std::move(_name), _age),
        breed(std::move(_breed)){};

  Dog(const Dog& other) : Animal(other), breed(other.breed){};

  Dog(Dog&& other) noexcept
      : Animal(std::move(other)), breed(std::move(other.breed)){};

  Dog& operator=(const Dog& other);

  Dog& operator=(Dog&& other) noexcept;

  void MakeSound() const override;

  [[nodiscard]] std::string GetBreed() const;

  void SetBreed(const std::string& _breed);
};

#endif  // DOG_H