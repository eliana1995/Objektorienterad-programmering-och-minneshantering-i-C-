#ifndef PLAYER_H
#define PLAYER_H 

#include <vector>
#include "Item.h"

class Player 
{
    public:
    Player();
    ~Player();
    void addItem(Item* item);
    void showItems();
    //void useItem(Player& player);
    void removeItem(Item* item);
    int getHealth();
    Item* getItem(int i);
    void setHealth(int newHealth);
    std::vector<Item*> getItems();

    private:
        int health ;
        std::vector<Item*> items;
};

#endif