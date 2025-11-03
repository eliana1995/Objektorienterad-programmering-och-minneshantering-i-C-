#include "Player.h"
#include "Item.h"

Player::Player() = default;

Player::~Player() {
    for(Item* item : items) {
        delete item;
        item = nullptr;
    }
}

void Player::addItem(Item* item) {
    items.push_back(item);
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
};

void Player::setHealth(int newHealth) {
    health = newHealth;
};