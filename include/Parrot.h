#ifndef PARROT_H
#define PARROT_H

#include "Animal.h"

class Parrot final : public Animal {
private:
    std::optional<__int16> lexicon;
public:
    using Animal::Animal;

    Parrot (Owner _owner, std::string _name, const __int16& _age, const __int16& _lexicon) : Animal(std::move(_owner),
        std::move(_name), _age), lexicon(_lexicon) {};

    Parrot (const Parrot& other) : Animal(other), lexicon(other.lexicon) {};

    Parrot(Parrot&& other) noexcept : Animal(std::move(other)), lexicon(std::move(other.lexicon)) {};

    Parrot& operator=(const Parrot& other);

    Parrot& operator=(Parrot&& other) noexcept;

    void MakeSound() const override;

    __int16 GetLexicon() const;

    void SetLexicon(const __int16& _lexicon);
};

#endif //PARROT_H