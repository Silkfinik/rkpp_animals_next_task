#ifndef CAT_H
#define CAT_H

#include "Animal.h"

class Cat final : public Animal {
private:
    std::optional<std::string> color;
public:
    using Animal::Animal;

    Cat (Owner _owner, std::string _name, const int16_t& _age, std::string _color) : Animal(std::move(_owner),
        std::move(_name), _age), color(std::move(_color)) {};

    Cat (const Cat& other) : Animal(other), color(other.color) {};

    Cat(Cat&& other) noexcept : Animal(std::move(other)), color(std::move(other.color)) {};

    Cat& operator=(const Cat& other);

    Cat& operator=(Cat&& other) noexcept;

    void MakeSound() const override;

    [[nodiscard]] std::string GetColor() const;

    void SetColor(const std::string& _color);
};

#endif //CAT_H