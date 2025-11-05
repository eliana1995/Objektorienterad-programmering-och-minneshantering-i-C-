#ifndef ITEM_H
#define ITEM_H

#include <string>

class Player;

class Item {
protected:
    std::string name;
    double value;

public:
    Item(const std::string& name, double value);
    virtual ~Item() {}
    std::string getName() const;
    double getValue() const;
    virtual void display() const = 0;
    virtual void use(Player& player) = 0;
    virtual Item* clone() const = 0;
};

#endif
