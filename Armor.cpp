#include "Armor.h"
#include "Player.h"
#include "Item.h"
#include <iostream>


Armor::Armor(const std::string& name, double value,double damageReduction, bool equipped)
  : Item(name, value), damageReduction(damageReduction), equipped(equipped) {}

double Armor::getDamageReduction() const {
    return damageReduction;
}

bool Armor::isEquipped() const {
    return equipped;
}

void Armor::setEquipped(bool on) {
    equipped = on;
}

void Armor::display() const {
    std::cout << "Armor: " << name 
                << " | Value: " << value
                << " | Damage Reduction: " << damageReduction 
                << " | Equipped: " << (equipped ? "Yes" : "No") 
                << std::endl;
}

void Armor::use(Player& player) {
     if(equipped){

     std::cout << "Armor" << name << "equipped! Defense + "  << damageReduction << std::endl;
    }else{
     std::cout << "Armor" << name << "unequipped! "<< std::endl;  
}
}

Item* Armor::clone() const
{
    return new Armor(*this);
}

