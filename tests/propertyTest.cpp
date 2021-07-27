#include "catch2.h"
#include "../inc/property.hpp"

TEST_CASE("Constructor")
{
        std::string name = "MyComponentName";
        int quantity = 10;
        double price = 13.5;

    SECTION("Create object")
    {
        Property property(name, quantity, price);
    }

    SECTION("Get name")
    {
        Property property(name, quantity, price);
        REQUIRE(property.getName() == name);
    }

    SECTION("Get quantity")
    {
        Property property(name, quantity, price);
        REQUIRE(property.getQuantity() == quantity);
    }

    SECTION("Get price")
    {
        Property property(name, quantity, price);
        REQUIRE(property.getPrice() == price);
    }
}