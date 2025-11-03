#include "Armor.h"
#include <iostream>


Armor::Armor(const std::string& name, double value,double damageReduction, bool equipped)
  : Item(name, value), damageReduction(damageReduction), equipped(equipped) {}

double Armor::getDamageReduction() const {
    return damageReduction;
}

bool Armor::isEquipped() const {
    return equipped;
}

void Armor::setEuipped(bool on) {
    equipped = on;
}

void Armor::display() const {
    std::cout << "Armor: " << name << "\n"
              << "Value: " << value << "\n"
              << "Damage Reduction: " << damageReduction << "\n"
              << "Equipped: " << (equipped ? "Yes" : "No")
              << std::endl;
}
