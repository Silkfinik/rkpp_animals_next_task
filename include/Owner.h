#ifndef OWNER_H
#define OWNER_H

#include <optional>
#include <string>


class Owner {
 private:
  std::optional<std::string> o_name;
  std::optional<std::string> adress;
  std::optional<std::string> phone;
  std::optional<std::string> b_date;

 public:
  Owner(std::string _name, std::string _adress, std::string _phone,
        std::string _b_date)
      : o_name(std::move(_name)),
        adress(std::move(_adress)),
        phone(std::move(_phone)),
        b_date(std::move(_b_date)){};

  Owner() = default;

  Owner(const Owner& other)
      : o_name(other.o_name),
        adress(other.adress),
        phone(other.phone),
        b_date(other.b_date){};

  Owner(Owner&& other) noexcept
      : o_name(std::move(other.o_name)),
        adress(std::move(other.adress)),
        phone(std::move(other.phone)),
        b_date(std::move(other.b_date)){};

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

#endif  // OWNER_H