#include "Item.h"

Item::Item(const std::string& n, double w) : name(n), weight(w) {}

std::string Item::getName() const { return name; }
double Item::getWeight() const { return weight; }
