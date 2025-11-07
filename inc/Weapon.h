#ifndef WEAPON_H
#define WEAPON_H

#include "Item.h"
#include "Player.h"

class Weapon : public Item {
private:
    int damage;
    bool equipped;

public:
    Weapon(const std::string& name, double value, int damage);
    void display() const override;
    void use(Player& player) override;
    Item* clone() const override;

};

#endif
