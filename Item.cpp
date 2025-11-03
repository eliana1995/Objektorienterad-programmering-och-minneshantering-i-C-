#include "Item.h"
#include <iostream>

Item::Item(const std::string& name, double value)
    : name(name), value(value) {}

std::string Item::getName() const { return name; }
double Item::getValue() const { return value; }

void Item::use() {
    std::cout << name << " has no specific use." << std::endl;
}
