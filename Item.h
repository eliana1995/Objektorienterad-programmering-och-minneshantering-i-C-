#ifndef ITEM_H
#define ITEM_H

#include <string>

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

    // Gör use virtuell för polymorf användning
    virtual void use();
};

#endif

