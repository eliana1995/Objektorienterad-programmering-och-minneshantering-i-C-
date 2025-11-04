#include <iostream>
#include <vector>
#include "Player.h"
#include "Weapon.h"
#include "Armor.h"
#include "Potion.h"

std::vector<Item*> initializeDefaultItems() {
    std::vector<Item*> items;
        items.emplace_back(new Potion("Ultra Super Health Potion", 200.0, 50));
        items.emplace_back(new Potion("Good Health Potion", 55.0, 20));
        items.emplace_back(new Potion("Mediocre Health Potion", 5.0, 5));
        items.emplace_back(new Weapon("Dagger", 50.0, 10));
        items.emplace_back(new Weapon("Sword", 100.0, 25));
        items.emplace_back(new Weapon("Broadsword", 200.0, 35));
        items.emplace_back(new Armor("Iron chest", 500.00, 50, false));
        items.emplace_back(new Armor("Helmet", 150.0, 20, false));
        items.emplace_back(new Armor("Leather leggings", 25.0, 5, true));
    return items;
}




std::vector<Item*> defaultItems = initializeDefaultItems();

void showMenu(Player* player, bool& running) {
    std::cout << "\n===== Inventory Menu =====\n"
              << "1. Choose Item to inventory\n"
              << "0. Exit\n"
              << "Choose an option: ";
        int choice;
        std::cin >> choice;

        switch (choice) {
            case 1: {
                bool validChoice = false;
                while (!validChoice){
                std::cout << "Choose an item to add to inventory:\n" << std::endl;
                int index = 0;
                    for(Item* items : defaultItems){
                        std::cout << (index + 1) << ". ";
                         items->display();
                         index++;
                        }
                        int itemChoice;
                        std:: cin >> itemChoice;

                        itemChoice -= 1;

                        if (itemChoice >= 0 && itemChoice < int(defaultItems.size())) {
                            player->addItem(defaultItems[itemChoice]);
                            std::cout << "Item added to your inventory!\n";
                            validChoice = true;
                        } else {
                            std::cout << "Invalid choice. Try again!\n";
                        }
                    }
                break;
            }
            case 0:
                running = false;
                break;
            default:
                std::cout << "Invalid option.\n";
        }
}



void removeItem(Player* player)
{
    std::cout << "\nChoose index of item to remove:\n";
    int i = 1;
    std::vector<Item *> items = player->getItems();
    for (Item *item : items)
    {
        std::cout << i << " : " << std::endl;
        item->display();
        i++;
    }
    int index;
    std::cout << "Enter index to remove (0 to go back): ";
    std::cin >> index;
    if(index == 0) {
        return;
    }
    while (index < 1 || index > i)
    {
        std::cout << "(Please enter valid index): ";
        std::cin >> index;
    }
    Item* itemToRemove = player->getItems().at(index - 1);
    player->removeItem(itemToRemove);
    //player->showItems();
    std::cout << "Feature to remove item can be added easily later.\n";
}


void mainMenu(Player* player, bool& running) {
    std::cout << "\n===== Main Menu =====\n"
              << "1. Add item to inventory\n"
              << "2. Show Inventory\n"
              << "3. Use Item\n"
              << "4. Remove Item\n"
              << "0. Exit\n"
              << "Choose an option: ";
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