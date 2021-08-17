#include "commodity.hpp"
#include <string>

using namespace std;

double SALES_TAX = 1.25;

Commodity::Commodity(const string &name_, int id_, double price_) : name(name_), id(id_), price(price_){};

const string &Commodity::get_name() const {
  return name;
}

int Commodity::get_id() const {
  return id;
}

double Commodity::get_price() const {
  return price;
}

double Commodity::get_price(double quantity) const {
  return price * quantity;
}

double Commodity::get_price_with_sales_tax() const {
  return price * SALES_TAX;
}

double Commodity::get_price_with_sales_tax(double quantity) const {
  return price * SALES_TAX * quantity;
}

void Commodity::set_price(double new_price) {
  price = new_price;
}