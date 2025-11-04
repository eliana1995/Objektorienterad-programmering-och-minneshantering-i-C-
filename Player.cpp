#include "Player.h"
#include "Item.h"
#include "Weapon.h"
#include <typeinfo>
#include <iostream>

Player::Player():
health(45){};

Player::~Player() {
    for(Item* item : items) {
        delete item;
        item = nullptr;
    }
}

void Player::addItem(Item* item) {
    items.emplace_back(item);
};

void Player::showItems() {
    for (Item* item : items) {
        item->display();
    }
};

void Player::removeItem(Item* item){
    delete item;
    item = nullptr;
};

int Player::getHealth() {
    return health;
}
Item* Player::getItem(int i)
{
   return items.at(i);
};

void Player::setHealth(int newHealth) {
    health = newHealth;
};

std::vector<Item*> Player::getItems() {
    return items;
}

//void Player::useItem(Item& item, Player& player) {
//    item->use(player);
//}