#include "Item.h"

Item::Item(const std::string& name, double value)
    : name(name), value(value) {}

std::string Item::getName() const { return name; }
double Item::getValue() const { return value; }
