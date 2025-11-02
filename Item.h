#ifndef ITEM_H
#define ITEM_H

#include <string>

class Item {
protected:
    std::string name;
    double weight;

public:
    Item(const std::string& name, double weight);
    virtual ~Item() {}
    std::string getName() const;
    double getWeight() const;
    virtual void display() const = 0;
    virtual void use() = 0;
};

#endif
