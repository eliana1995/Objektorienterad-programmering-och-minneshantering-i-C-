#include "Weapon.h"
#include <iostream>

Weapon::Weapon(const std::string& name, double value, int damage)
    : Item(name, value), damage(damage), equipped(false) {}

void Weapon::display() const {
    std::cout << "Weapon: " << name
              << " | Value: " << value
              << " | Damage: " << damage
              << (equipped ? " [Equipped]" : "")
              << std::endl;
}

void Weapon::use() {
    equipped = !equipped;
    std::cout << name
              << (equipped ? " is now equipped!" : " is unequipped!")
              << std::endl;
}
