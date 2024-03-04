#ifndef ANIMALS_H
#define ANIMALS_H


#include <string>
#include <optional>

class Owner {
private:
    std::optional<std::string> o_name;
    std::optional<std::string> adress;
    std::optional<std::string> phone;
    std::optional<std::string> b_date;
    public:
    Owner (std::string _name, std::string _adress, std::string _phone, std::string _b_date) :
    o_name(std::move(_name)), adress(std::move(_adress)),
    phone(std::move(_phone)), b_date(std::move(_b_date)) {};

    Owner() = default;

    Owner(const Owner& other) : o_name(other.o_name), adress(other.adress), phone(other.phone), b_date(other.b_date) {};

    Owner(Owner&& other) noexcept : o_name(std::move(other.o_name)), adress(std::move(other.adress)),
    phone(std::move(other.phone)), b_date(std::move(other.b_date)) {};

    Owner& operator=(const Owner& other);

    Owner& operator=(Owner&& other) noexcept;

    void SetOName(const std::string& _name);
    void SetAdress(const std::string& _adress);
    void SetPhone(const std::string& _phone);
    void SetBDate(const std::string& _b_date);

    [[nodiscard]] std::string GetOName() const;
    [[nodiscard]] std::string GetAdress() const;
    [[nodiscard]] std::string GetPhone() const;
    [[nodiscard]] std::string GetBDate() const;
};

class Animal {
private:
    static __int16 count;
protected:
    std::optional<Owner> owner;
    std::optional <std::string> a_name;
    std::optional <__int16> age;
    const __int16 id;
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

class Dog final : public Animal {
private:
    std::optional<std::string> breed;
public:
    using Animal::Animal;

    Dog (Owner _owner, std::string _name, const __int16& _age, std::string _breed) : Animal(std::move(_owner),
        std::move(_name), _age), breed(std::move(_breed)) {};

    Dog (const Dog& other) : Animal(other), breed(other.breed) {};

    Dog(Dog&& other) noexcept : Animal(std::move(other)), breed(std::move(other.breed)) {};

    Dog& operator=(const Dog& other);

    Dog& operator=(Dog&& other) noexcept;

    void MakeSound() const override;

    [[nodiscard]] std::string GetBreed() const;

    void SetBreed(const std::string& _breed);
};

class Cat final : public Animal {
private:
    std::optional<std::string> color;
public:
    using Animal::Animal;

    Cat (Owner _owner, std::string _name, const __int16& _age, std::string _color) : Animal(std::move(_owner),
        std::move(_name), _age), color(std::move(_color)) {};

    Cat (const Cat& other) : Animal(other), color(other.color) {};

    Cat(Cat&& other) noexcept : Animal(std::move(other)), color(std::move(other.color)) {};

    Cat& operator=(const Cat& other);

    Cat& operator=(Cat&& other) noexcept;

    void MakeSound() const override;

    [[nodiscard]] std::string GetColor() const;

    void SetColor(const std::string& _color);
};

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

class Pig final : public Animal {
private:
    std::optional<__int16> piglet_size;
public:
    using Animal::Animal;

    Pig (Owner _owner, std::string _name, const __int16& _age, const __int16& _piglet_size) : Animal(std::move(_owner),
        std::move(_name), _age), piglet_size(_piglet_size) {};

    Pig (const Pig& other) : Animal(other), piglet_size(other.piglet_size) {};

    Pig(Pig&& other) noexcept : Animal(std::move(other)), piglet_size(std::move(other.piglet_size)) {};

    Pig& operator=(const Pig& other);

    Pig& operator=(Pig&& other) noexcept;

    void MakeSound() const override;

    __int16 GetPigletSize() const;

    void SetPigletSize(const __int16& _piglet_size);
};


#endif //ANIMALS_H