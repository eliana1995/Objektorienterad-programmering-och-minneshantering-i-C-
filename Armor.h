#ifndef ARMOR_H
#define ARMOR_H

#include "Item.h"
#include <string>

class Armor : public Item {
public: 
    // ArmorItem + damageReduction
    Armor(const std::string& name, double value, double damageReduction, bool equipped );

   // Deklarationer 
    double getDamageReduction () const;
    bool isEquipped () const;
    void setEuipped(bool on); 

    void display() const override;  

private:
    double damageReduction{0.0};
    bool equipped{false};
   
};

#endif