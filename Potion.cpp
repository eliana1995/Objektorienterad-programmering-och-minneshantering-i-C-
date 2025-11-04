#include "Potion.h"
#include "Player.h"
#include <iostream>


Potion::Potion(const std::string& name, double value, int boost)
    : Item (name, value), boost(boost){}


void Potion::display() const {
    std::cout << "Potion: " << name 
                << " | Value: " << value 
                << " | Health Boost: " << boost 
                << std::endl;
}



void Potion::use(Player& player){
    int currentHealth = player.getHealth();
    int newHealth = currentHealth + boost;

    if (newHealth > 100) {
        newHealth = 100;
    }

    player.setHealth(newHealth);

    std::cout << "You used potion: " << name 
                << " and gained: " << boost 
                << " in health!" << std::endl;
}