#ifndef POTION_H
#define POTION_H

#include "Item.h"
#include "Player.h"
#include <string>

class Potion : public Item {
private:
    int boost;

public:
    Potion(const std::string& name, double value, int boost);

    
    void display() const override;
    void usePotion(Player player);

};



#endif
