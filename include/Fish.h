#ifndef FISH_H
#define FISH_H

#include "Animal.h"

class Fish final : public Animal {
private:
    std::optional<__int16> avg_depth;
public:
    using Animal::Animal;

    Fish (Owner _owner, std::string _name, const __int16& _age, const __int16& _avg_depth) : Animal(std::move(_owner),
        std::move(_name), _age), avg_depth(_avg_depth) {};

    Fish (const Fish& other) : Animal(other), avg_depth(other.avg_depth) {};

    Fish(Fish&& other) noexcept : Animal(std::move(other)), avg_depth(std::move(other.avg_depth)) {};

    Fish& operator=(const Fish& other);

    Fish& operator=(Fish&& other) noexcept;

    void MakeSound() const override;

    __int16 GetAvgDepth() const;

    void SetAvgDepth(const __int16& _avg_depth);
};

#endif //FISH_H