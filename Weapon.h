#ifndef WEAPON_H
#define WEAPON_H

#include "Item.h"

class Weapon : public Item {
private:
    int damage;
    bool equipped;

public:
    Weapon(const std::string& name, double value, int damage);
    void display() const override;

    // gör override korrekt
    void use() override;
};

#endif
