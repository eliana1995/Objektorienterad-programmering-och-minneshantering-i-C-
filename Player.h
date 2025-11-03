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
    void useItem(Item* item);
    void removeItem(Item* item);
    int getHealth();
    void setHealth(int newHealth);

    private:
        int health;
        std::vector<Item*> items;
};

#endif