#ifndef PROPERTY
#define PROPERTY

#include "libraries.hpp"

class Property {
    std::string name;
    int quantity;
    double price;

    public:
    Property(std::string name, int quantity, double price);
    std::string getName() const;
    int getQuantity() const;
    double getPrice() const;
};

#endif
