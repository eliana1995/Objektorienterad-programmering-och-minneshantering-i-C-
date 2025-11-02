#include "Weapon.h"
#include <iostream>

Weapon::Weapon(const std::string& name, double weight, int damage)
    : Item(name, weight), damage(damage), equipped(false) {}

void Weapon::display() const {
    std::cout << "Weapon: " << name
              << " | Weight: " << weight
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
