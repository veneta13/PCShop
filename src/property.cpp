#include "../inc/property.hpp"

    Property::Property(std::string name, int quantity, double price){
        this->name = name;
        this->quantity = quantity;
        this->price = price;
    }

    std::string Property::getName() const{
        return name;
    }

    int Property::getQuantity() const{
        return quantity;
    }

    double Property::getPrice() const{
        return price;
    }