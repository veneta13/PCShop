#include "math.h"
#include "catch2.h"
#include "../inc/property.hpp"
#include "../inc/component.hpp"


const std::string name[] = {"MyComponentName1", "MyComponentName2", "MyComponentName3"};
const int quantity[] = {1, 2, 3, 4};
const double price[] = {10.10, 20.20, 30.30, 40.40};

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

TEST_CASE("OPERATOR ==")
{
    SECTION("EQUAL - no properties")
    {

        Component component1;
        Component component2;

        REQUIRE(component1 == component2);
    }

    SECTION("EQUAL - 1 property")
    {
        Property property(name[1], quantity[1], price[1]);

        Component component1;
        component1.addProperty(property);

        Component component2;
        component2.addProperty(property);

        REQUIRE(component1 == component2);
    }

    SECTION("EQUAL - 2 properties")
    {
        Property property1(name[1], quantity[1], price[1]);
        Property property2(name[2], quantity[2], price[2]);

        Component component1;
        component1.addProperty(property1);
        component1.addProperty(property2);

        Component component2;
        component2.addProperty(property1);
        component2.addProperty(property2);

        REQUIRE(component1 == component2);
    }

    SECTION("EQUAL - 3 properties")
    {
        Property property1(name[1], quantity[1], price[1]);
        Property property2(name[2], quantity[2], price[2]);
        Property property3(name[3], quantity[3], price[3]);

        Component component1;
        component1.addProperty(property1);
        component1.addProperty(property2);
        component1.addProperty(property3);

        Component component2;
        component2.addProperty(property1);
        component2.addProperty(property2);
        component2.addProperty(property3);

        REQUIRE(component1 == component2);
    }
    
    SECTION("NOT EQUAL - 1 property")
    {
        Property property1(name[1], quantity[1], price[1]);
        Property property2(name[2], quantity[2], price[2]);

        Component component1;
        component1.addProperty(property1);

        Component component2;
        component2.addProperty(property2);

        REQUIRE(!(component1 == component2));
    }

    SECTION("NOT EQUAL - 1 property matching and 1 not")
    {
        Property property1(name[1], quantity[1], price[1]);
        Property property2(name[2], quantity[2], price[2]);
        Property property3(name[0], quantity[0], price[0]);

        Component component1;
        component1.addProperty(property1);
        component1.addProperty(property2);

        Component component2;
        component2.addProperty(property2);
        component2.addProperty(property3);

        REQUIRE(!(component1 == component2));
    }

    SECTION("NOT EQUAL - 2 properties not matching")
    {
        Property property0(name[0], quantity[0], price[0]);
        Property property1(name[1], quantity[1], price[1]);
        Property property2(name[2], quantity[2], price[2]);
        Property property3(name[3], quantity[3], price[3]);

        Component component1;
        component1.addProperty(property0);
        component1.addProperty(property1);

        Component component2;
        component2.addProperty(property2);
        component2.addProperty(property3);

        REQUIRE(!(component1 == component2));
    }

    SECTION("NOT EQUAL - different operator count")
    {
        Property property1(name[1], quantity[1], price[1]);
        Property property2(name[2], quantity[2], price[2]);
        Property property3(name[3], quantity[3], price[3]);

        Component component1;
        component1.addProperty(property1);
        component1.addProperty(property2);
        component1.addProperty(property3);

        Component component2;
        component2.addProperty(property1);
        component2.addProperty(property2);

        REQUIRE(!(component1 == component2));
    }
}