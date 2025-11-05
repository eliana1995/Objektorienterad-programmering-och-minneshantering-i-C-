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

int getIntFromUser(const std::string& prompt){
    int value;
    while (true) {
        std::cout << prompt;
        std::string line;
        std::getline(std::cin, line);
        std::stringstream ss(line);
        if (ss >> value && ss.eof()) return value;
        std::cout << "Invalid input! Try again.\n";
    }
}

void showMenu(Player* player, bool& running) {
    std::cout << "\n===== Inventory Menu =====\n"
              << "1. Choose Item to inventory\n"
              << "0. Exit\n";

        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        int choice = getIntFromUser("Choose an option: ");

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
        std::cout << "\n===== Remove item from inventory =====\n";
    int i = 1;
    std::vector<Item *> items = player->getItems();
    if(items.empty()){
        std::cout << "Inventory is empty." << std::endl;
        return;
    } else {
    std::cout << "\nChoose index of item to remove:\n";
    for (Item *item : items)
    {
        std::cout << i << ". ";
        item->display();
        i++;
    }}
    int index;
    std::cout << "0. Go back): ";
    std::cout << "Enter index to remove: ";
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
                showMenu(player, running);
                break;
            }
            case 2: {
                player->showItems();
                break;
            }
            case 3: {
                // Hämta spelarens items
                std::vector<Item*> items = player->getItems();
                
                // Kontroll: tomt inventory
                if (items.empty()) {
                    std::cout << "Ditt inventarie är tomt. Lägg till ett föremål först.\n";
                break;
                }

                // Visa alla föremål
                std::cout << "\n=== Dina föremål ===\n";
                for (int i = 0; i < (int)items.size(); ++i) {
                    std::cout << (i + 1) << ") ";
                    items[i]->display();
                }

                // Låt användaren välja ett index
                std::cout << "Välj vilket föremål du vill använda (ange nummer): ";
                int index;
                std::cin >> index;

                // Kontrollera giltigt val
                if (std::cin.fail()){
                    std::cin.clear();
                    //std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::cout << "Ogiltigt inmatning";
                    break;
                }
                // Kontrollera giltig val
                if (index <= 0 || index > (int)items .size()) {
                    std::cout << "Ogiltig val, försök igen.\n";
                    break;
                } 
                // Anropa spelarens funktion för att använda itemet
                Item* item = player->getItem(index-1);
                item->use(*player);
                //player->useItem(index -1);
                break;
            }

            case 4: {
                removeItem(player);
                break;
            }
            case 0:
                running = false;
                break;
            default:
                std::cout << "Invalid option.\n";
        }
}

int main() {
    Player* player = new Player();
    bool running = true;


    while (running) {
        mainMenu(player, running);
    }

    // Free heap memory of player object and pointer
    delete player;
    player = nullptr;

    // Free heap memory of defaultItems objects and pointers
    for (Item* item : defaultItems) {
    delete item;
    item = nullptr;
    }
    std::cout << "Exiting program. Memory cleaned up.\n";
    return 0;
}