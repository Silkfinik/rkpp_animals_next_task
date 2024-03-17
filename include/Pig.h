#ifndef PIG_H
#define PIG_H

#include "Animal.h"

class Pig final : public Animal {
private:
    std::optional<int16_t> piglet_size;
public:
    using Animal::Animal;

    Pig (Owner _owner, std::string _name, const int16_t& _age, const int16_t& _piglet_size) : Animal(std::move(_owner),
        std::move(_name), _age), piglet_size(_piglet_size) {};

    Pig (const Pig& other) : Animal(other), piglet_size(other.piglet_size) {};

    Pig(Pig&& other) noexcept : Animal(std::move(other)), piglet_size(std::move(other.piglet_size)) {};

    Pig& operator=(const Pig& other);

    Pig& operator=(Pig&& other) noexcept;

    void MakeSound() const override;

    int16_t GetPigletSize() const;

    void SetPigletSize(const int16_t& _piglet_size);
};

#endif //PIG_H