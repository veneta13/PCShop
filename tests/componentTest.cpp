#include "math.h"
#include "catch2.h"
#include "../inc/property.hpp"
#include "../inc/component.hpp"


const std::string name[] = {"MyComponentName1", "MyComponentName2", "MyComponentName3"};
const int quantity[] = {1, 2, 3};
const double price[] = {10.10, 20.20, 30.30};

TEST_CASE("Update")
{
    SECTION("Updated quantity")
    {
        Property property(name[0], quantity[0], price[0]);
        Component component;
        component.addProperty(property);

        REQUIRE(component.getPropertyQuantity(name[0]) == quantity[0]);

        Property updatedProperty(name[0], quantity[1], price[0]);
        component.addProperty(updatedProperty);

        REQUIRE(component.getPropertyQuantity(name[0]) == quantity[1]);
    }

    SECTION("Updated price")
    {
        Property property(name[0], quantity[0], price[0]);
        Component component;
        component.addProperty(property);

        REQUIRE(ceil(component.getPrice()) == 11);

        Property updatedProperty(name[0], quantity[0], price[2]);
        component.addProperty(updatedProperty);
        REQUIRE(ceil(component.getPrice()) == 31);
    }
}

TEST_CASE("Remove")
{
    SECTION("Remove property quantity check")
    {
        Property removedProperty(name[1], quantity[1], price[1]);

        Component component;
        component.addProperty(removedProperty);
        REQUIRE(component.getPropertyQuantity(name[1]) == quantity[1]);

        component.removeProperty(removedProperty);
        REQUIRE(component.getPropertyQuantity(name[1]) == -1);
    }

    SECTION("Remove property price check")
    {
        Property removedProperty(name[1], quantity[1], price[1]);

        Component component;
        component.addProperty(removedProperty);
        REQUIRE(floor(component.getPrice()) == 40);
        REQUIRE(ceil(component.getPrice()) == 41);

        component.removeProperty(removedProperty);

        REQUIRE(floor(component.getPrice()) == 0);
    }
}