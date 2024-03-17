#ifndef ANIMAL_H
#define ANIMAL_H

#include "Owner.h"

class Animal {
 private:
  static int16_t count;

 protected:
  std::optional<Owner> owner;
  std::optional<std::string> a_name;
  std::optional<int16_t> age;
  int16_t id;

 public:
  Animal() : id(count++){};

  explicit Animal(Owner _owner) : owner(std::move(_owner)), id(count++){};

  explicit Animal(std::string _name) : a_name(std::move(_name)), id(count++){};

  Animal(Owner _owner, std::string _name)
      : owner(std::move(_owner)), a_name(std::move(_name)), id(count++){};

  Animal(Owner _owner, std::string _name, const int16_t& _age)
      : owner(std::move(_owner)),
        a_name(std::move(_name)),
        age(_age),
        id(count++){};

  Animal(const Animal& other)
      : owner(other.owner), a_name(other.a_name), age(other.age), id(count++){};

  Animal(Animal&& other) noexcept
      : owner(std::move(other.owner)),
        a_name(std::move(other.a_name)),
        age(std::move(other.age)),
        id(count++){};

  virtual ~Animal() = default;

  Animal& operator=(const Animal& other);

  Animal& operator=(Animal&& other) noexcept;

  virtual void MakeSound() const = 0;

  void SetOwner(const Owner& _owner);
  void SetAName(const std::string& _name);
  void SetAge(const int16_t& _age);

  [[nodiscard]] std::string GetAName() const;
  int16_t GetAge() const;
  [[nodiscard]] Owner& GetOwnerRef();
  [[nodiscard]] Owner GetOwner() const;
  int16_t GetId() const;
};

#endif  // ANIMAL_H