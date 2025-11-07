#include "Weapon.h"
#include "Player.h"
#include <iostream>

Weapon::Weapon(const std::string& name, double value, int damage)
    : Item(name, value), damage(damage), equipped(false) {}

void Weapon::display() const {
    std::cout << "Weapon: " << name
              << " | Value: " << value
              << " | Damage: " << damage
              << " | Equipped: " << (equipped ? "Yes" : "No")
              << std::endl;
} 

void Weapon::use(Player& player)
{
    equipped = !equipped;
    std::cout << name
              << (equipped ? " is now equipped!" : " is unequipped!")
              << std::endl;
}

Item* Weapon::clone() const
{
    return new Weapon(*this);
}
