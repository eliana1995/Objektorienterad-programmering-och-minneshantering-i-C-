#include <iostream>
#include <vector>
#include "Weapon.h"

#include "Potion.h"
#include <vector>

std::vector<Item*> initializeDefaultItems() {
    std::vector<Item*> items;
        items.emplace_back(new Potion("Ultra Super Health Potion", 200.0, 50));
        items.emplace_back(new Potion("Good Health Potion", 55.0, 20));
        items.emplace_back(new Potion("Mediocre Health Potion", 5.0, 5));
        items.emplace_back(new Weapon("Dagger", 50.0, 10));
        items.emplace_back(new Weapon("Sword", 100.0, 25));
        items.emplace_back(new Weapon("Broadsword", 200.0, 35));
    return items;
}


int main() {

    std::vector<Item*> defaultItems = initializeDefaultItems();

    std::cout << "=== RPG Inventory Demo ===" << std::endl;
        std::cout << "Deafult items: " << std::endl;
    for(Item* items : defaultItems){
        items->display();
    }

    for (Item* item : defaultItems) {
        delete item;
        item = nullptr;
    }
    return 0;
}
