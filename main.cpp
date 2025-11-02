#include <iostream>
#include <vector>
#include "Weapon.h"
using namespace std;

int main() {
    cout << "=== RPG Inventory Demo ===" << endl;

    // Stack-objekt
    Weapon sword("Iron Sword", 3.5, 50);
    sword.display();
    sword.use();

    // Heap-objekt
    vector<Item*> inventory;
    inventory.push_back(new Weapon("Magic Staff", 2.2, 70));
    inventory.push_back(new Weapon("Battle Axe", 5.0, 65));

    cout << "\n-- Inventory List --" << endl;
    for(auto item : inventory) {
        item->display();
        item->use();
    }

    for(auto item : inventory) delete item;
    inventory.clear();

    cout << "\nAll heap memory freed. Program finished!" << endl;
    return 0;
}
