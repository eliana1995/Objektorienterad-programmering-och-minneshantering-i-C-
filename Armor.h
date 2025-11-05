#ifndef ARMOR_H
#define ARMOR_H

#include "Item.h"
#include "Player.h"
#include <string>

class Armor : public Item {
public: 
    // ArmorItem + damageReduction
    Armor(const std::string& name, double value, double damageReduction, bool equipped);

   // Deklarationer 
    double getDamageReduction () const;
    bool isEquipped () const;
    void setEquipped(bool on); 
    void display() const override;
    void use(Player& player) override;
    Item* clone() const override;

private:
    double damageReduction;
    bool equipped;
   
};

#endif