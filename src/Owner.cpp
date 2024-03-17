#include "../include/Owner.h"

void Owner::SetOName(const std::string& _name) { o_name = _name; }

void Owner::SetAdress(const std::string& _adress) { adress = _adress; }

void Owner::SetPhone(const std::string& _phone) { phone = _phone; }

void Owner::SetBDate(const std::string& _b_date) { b_date = _b_date; }

std::string Owner::GetOName() const { return o_name.value(); }

std::string Owner::GetAdress() const { return adress.value(); }

std::string Owner::GetPhone() const { return phone.value(); }

std::string Owner::GetBDate() const { return b_date.value(); }

Owner& Owner::operator=(const Owner& other) {
  o_name = other.o_name;
  adress = other.adress;
  phone = other.phone;
  b_date = other.b_date;
  return *this;
}

Owner& Owner::operator=(Owner&& other) noexcept {
  o_name = std::move(other.o_name);
  adress = std::move(other.adress);
  phone = std::move(other.phone);
  b_date = std::move(other.b_date);
  return *this;
}