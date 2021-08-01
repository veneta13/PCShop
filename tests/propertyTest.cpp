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

TEST_CASE("OPERATOR ==")
{
    SECTION("NOT EQUAL - 3 differences")
    {
        Property property1("name1", 2, 3.4);
        Property property2("name2", 3, 4.5);

        REQUIRE(!(property1 == property2));
    }

    SECTION("NOT EQUAL - 2 differences")
    {
        Property property1("name1", 2, 3.4);
        Property property2("name2", 3, 3.4);

        REQUIRE(!(property1 == property2));
    }

    SECTION("NOT EQUAL - 2 differences")
    {
        Property property1("name1", 2, 3.4);
        Property property2("name1", 3, 6.8);

        REQUIRE(!(property1 == property2));
    }

    SECTION("NOT EQUAL - 1 difference - name")
    {
        Property property1("name1", 2, 6.8);
        Property property2("name2", 2, 6.8);

        REQUIRE(!(property1 == property2));
    }

    SECTION("NOT EQUAL - 1 difference - quantity")
    {
        Property property1("name1", 2, 3.4);
        Property property2("name1", 6, 3.4);

        REQUIRE(!(property1 == property2));
    }

    SECTION("NOT EQUAL - 1 difference - price")
    {
        Property property1("name1", 2, 3.4);
        Property property2("name1", 2, 6.8);

        REQUIRE(!(property1 == property2));
    }

    SECTION("EQUAL")
    {
        Property property1("name1", 2, 3.1415);
        Property property2("name1", 2, 3.1415);

    REQUIRE(property1 == property2);
    }
}