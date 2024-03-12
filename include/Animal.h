#ifndef ANIMAL_H
#define ANIMAL_H

#include "Owner.h"

class Animal {
private:
    static __int16 count;
protected:
    std::optional<Owner> owner;
    std::optional <std::string> a_name;
    std::optional <__int16> age;
    __int16 id;
public:
    Animal() : id(count++) {};

    explicit Animal(Owner _owner) : owner(std::move(_owner)), id(count++) {};

    explicit Animal(std::string _name) : a_name(std::move(_name)), id(count++) {};

    Animal (Owner _owner, std::string _name) : owner(std::move(_owner)), a_name(std::move(_name)), id(count++) {};

    Animal (Owner _owner, std::string _name, const __int16& _age) : owner(std::move(_owner)),
    a_name(std::move(_name)), age(_age), id(count++) {};

    Animal (const Animal& other) : owner(other.owner), a_name(other.a_name), age(other.age), id(count++) {};

    Animal(Animal&& other) noexcept : owner(std::move(other.owner)), a_name(std::move(other.a_name)),
    age(std::move(other.age)), id(count++) {};

    virtual ~Animal() = default;

    Animal& operator=(const Animal& other);

    Animal& operator=(Animal&& other) noexcept;

    virtual void MakeSound() const = 0;

    void SetOwner(const Owner& _owner);
    void SetAName(const std::string& _name);
    void SetAge(const __int16& _age);

    [[nodiscard]] std::string GetAName() const;
    __int16 GetAge() const;
    [[nodiscard]] Owner& GetOwnerRef();
    [[nodiscard]] Owner GetOwner() const;
    __int16 GetId() const;
};


#endif //ANIMAL_H