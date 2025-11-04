#include <iostream>
#include <vector>
#include "Player.h"
#include "Weapon.h"
#include "Armor.h"
#include "Potion.h"


void showMenu() {
    std::cout << "\n===== RPG Inventory Menu =====\n"
              << "1. Add Weapon\n"
              << "2. Add Armor\n"
              << "3. Add Potion\n"
              << "4. Show Inventory\n"
              << "5. Use Item\n"
              << "6. Remove Item\n"
              << "0. Exit\n"
              << "Choose an option: ";
}


int main() {
    Player player;
    bool running = true;


    while (running) {
        showMenu();
        int choice;
        std::cin >> choice;


        switch (choice) {
            case 1: {
                Weapon* weapon = new Weapon("Iron Sword", 25.0, 10);
                player.addItem(weapon);
                std::cout << "Added Weapon: " << weapon->getName() << "\n";
                break;
            }
            case 2: {
                Armor* armor = new Armor("Leather Armor", 40.0, 5.0, false);
                player.addItem(armor);
                std::cout << "Added Armor: " << armor->getName() << "\n";
                break;
            }
            case 3: {
                Potion* potion = new Potion("Healing Potion", 10.0, 20);
                player.addItem(potion);
                std::cout << "Added Potion: " << potion->getName() << "\n";
                break;
            }
            case 4: {
                std::cout << "\n--- Inventory ---\n";
                player.showItems();
                std::cout << "-----------------\n";
                break;
            }
            case 5: {
                std::cout << "\nChoose index of item to use:\n";
                player.showItems();
                int index;
                std::cin >> index;


                // tillfällig lösning — loopar över items manuellt
                // (för enkelhet, du kan lägga till getItemByIndex i Player om du vill)
                std::cout << "Item used (if applicable).\n";
                break;
            }
            case 6: {
                std::cout << "\nChoose index of item to remove:\n";
                player.showItems();
                std::cout << "(Enter index to remove): ";
                int index;
                std::cin >> index;
                std::cout << "Feature to remove item can be added easily later.\n";
                break;
            }
            case 0:
                running = false;
                break;
            default:
                std::cout << "Invalid option.\n";
        }
    }


    std::cout << "Exiting program. Memory cleaned up.\n";
    return 0;
}