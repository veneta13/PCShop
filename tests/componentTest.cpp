#include "math.h"
#include "catch2.h"
#include "../inc/component.hpp"

const std::string name[] = {"MyComponentName1", "MyComponentName2", "MyComponentName3", "MyComponentName4"};
const int quantity[] = {1, 2, 3, 4};
const double price[] = {10.10, 20.20, 30.30, 40.40};

TEST_CASE("Update")
{
    SECTION("Updated quantity")
    {
        Property property(name[0], quantity[0], price[0]);
        std::shared_ptr<Component> component(new Component());
        component->addProperty(property);

        REQUIRE(component->getPropertyQuantity(name[0]) == quantity[0]);

        Property updatedProperty(name[0], quantity[1], price[0]);
        component->addProperty(updatedProperty);

        REQUIRE(component->getPropertyQuantity(name[0]) == quantity[1]);
    }

    SECTION("Updated price")
    {
        Property property(name[0], quantity[0], price[0]);
        std::shared_ptr<Component> component(new Component());
        component->addProperty(property);

        REQUIRE(ceil(component->getPrice()) == 11);

        Property updatedProperty(name[0], quantity[0], price[2]);
        component->addProperty(updatedProperty);
        REQUIRE(ceil(component->getPrice()) == 31);
    }
}

TEST_CASE("Remove")
{
    SECTION("Remove property quantity check")
    {
        Property removedProperty(name[1], quantity[1], price[1]);

        std::shared_ptr<Component> component(new Component());
        component->addProperty(removedProperty);
        REQUIRE(component->getPropertyQuantity(name[1]) == quantity[1]);

        component->removeProperty(removedProperty);
        REQUIRE(component->getPropertyQuantity(name[1]) == -1);
    }

    SECTION("Remove property price check")
    {
        Property removedProperty(name[1], quantity[1], price[1]);

        std::shared_ptr<Component> component(new Component());
        component->addProperty(removedProperty);
        REQUIRE(floor(component->getPrice()) == 40);
        REQUIRE(ceil(component->getPrice()) == 41);

        component->removeProperty(removedProperty);

        REQUIRE(floor(component->getPrice()) == 0);
    }
}

TEST_CASE("OPERATOR ==")
{
    SECTION("EQUAL - no properties")
    {

        std::shared_ptr<Component> component1(new Component());
        std::shared_ptr<Component> component2(new Component());

        REQUIRE(*component1 == *component2);
    }

    SECTION("EQUAL - 1 property")
    {
        Property property(name[1], quantity[1], price[1]);

        std::shared_ptr<Component> component1(new Component());
        component1->addProperty(property);

        std::shared_ptr<Component> component2(new Component());
        component2->addProperty(property);

        REQUIRE(*component1 == *component2);
    }

    SECTION("EQUAL - 2 properties")
    {
        Property property1(name[1], quantity[1], price[1]);
        Property property2(name[2], quantity[2], price[2]);

        std::shared_ptr<Component> component1(new Component());
        component1->addProperty(property1);
        component1->addProperty(property2);

        std::shared_ptr<Component> component2(new Component());
        component2->addProperty(property1);
        component2->addProperty(property2);

        REQUIRE(*component1 == *component2);
    }

    SECTION("EQUAL - 3 properties")
    {
        Property property1(name[1], quantity[1], price[1]);
        Property property2(name[2], quantity[2], price[2]);
        Property property3(name[3], quantity[3], price[3]);

        std::shared_ptr<Component> component1(new Component());
        component1->addProperty(property1);
        component1->addProperty(property2);
        component1->addProperty(property3);

        std::shared_ptr<Component> component2(new Component());
        component2->addProperty(property1);
        component2->addProperty(property2);
        component2->addProperty(property3);

        REQUIRE(*component1 == *component2);
    }
    
    SECTION("NOT EQUAL - 1 property")
    {
        Property property1(name[1], quantity[1], price[1]);
        Property property2(name[2], quantity[2], price[2]);

        std::shared_ptr<Component> component1(new Component());
        component1->addProperty(property1);

        std::shared_ptr<Component> component2(new Component());
        component2->addProperty(property2);

        REQUIRE(!(*component1 == *component2));
    }

    SECTION("NOT EQUAL - 1 property matching and 1 not")
    {
        Property property1(name[1], quantity[1], price[1]);
        Property property2(name[2], quantity[2], price[2]);
        Property property3(name[0], quantity[0], price[0]);

        std::shared_ptr<Component> component1(new Component());
        component1->addProperty(property1);
        component1->addProperty(property2);

        std::shared_ptr<Component> component2(new Component());
        component2->addProperty(property2);
        component2->addProperty(property3);

        REQUIRE(!(*component1 == *component2));
    }

    SECTION("NOT EQUAL - 1 property matching and 1 not - different order")
    {
        Property property1(name[1], quantity[1], price[1]);
        Property property2(name[2], quantity[2], price[2]);
        Property property3(name[0], quantity[0], price[0]);

        std::shared_ptr<Component> component1(new Component());
        component1->addProperty(property1);
        component1->addProperty(property2);

        std::shared_ptr<Component> component2(new Component());
        component2->addProperty(property3);
        component2->addProperty(property1);

        REQUIRE(!(*component1 == *component2));
    }

    SECTION("NOT EQUAL - 2 properties not matching")
    {
        Property property0(name[0], quantity[0], price[0]);
        Property property1(name[1], quantity[1], price[1]);
        Property property2(name[2], quantity[2], price[2]);
        Property property3(name[3], quantity[3], price[3]);

        std::shared_ptr<Component> component1(new Component());
        component1->addProperty(property0);
        component1->addProperty(property1);

        std::shared_ptr<Component> component2(new Component());
        component2->addProperty(property2);
        component2->addProperty(property3);

        REQUIRE(!(*component1 == *component2));
    }

    SECTION("NOT EQUAL - different operator count")
    {
        Property property1(name[1], quantity[1], price[1]);
        Property property2(name[2], quantity[2], price[2]);
        Property property3(name[3], quantity[3], price[3]);

        std::shared_ptr<Component> component1(new Component());
        component1->addProperty(property1);
        component1->addProperty(property2);
        component1->addProperty(property3);

        std::shared_ptr<Component> component2(new Component());
        component2->addProperty(property1);
        component2->addProperty(property2);

        REQUIRE(!(*component1 == *component2));
    }

}

TEST_CASE("OPERATOR >=")
{
    // ---  using separate variable to fix some Catch2 bug ----
    bool result;

    SECTION ("Empty components")
    {
        std::shared_ptr<Component> component1(new Component());
        std::shared_ptr<Component> component2(new Component());

        if (*component1 >= *component2) {result = true;}
        else { result = false;}
        REQUIRE(result == false);

        if (*component2 >= *component1) {result = true;}
        else { result = false;}
        REQUIRE(result == false);
    }

    SECTION ("1 property with the same name || same quantity")
    {
        Property property1(name[0], quantity[1], price[0]);
        Property property2(name[0], quantity[1], price[0]);

        std::shared_ptr<Component> component1(new Component());
        std::shared_ptr<Component> component2(new Component());
        component1->addProperty(property1);
        component2->addProperty(property2); 

        if (*component1 >= *component2) {result = true;}
        else { result = false;}
        REQUIRE(result == true);

        if (*component2 >= *component1) {result = true;}
        else { result = false;}
        REQUIRE(result == true);
    }

    SECTION ("1 property with the same name")
    {
        Property property1(name[0], quantity[0], price[0]);
        Property property2(name[0], quantity[1], price[0]);

        std::shared_ptr<Component> component1(new Component());
        std::shared_ptr<Component> component2(new Component());
        component1->addProperty(property1);
        component2->addProperty(property2); 

        if (*component1 >= *component2) {result = true;}
        else { result = false;}
        REQUIRE(result == false);

        if (*component2 >= *component1) {result = true;}
        else { result = false;}
        REQUIRE(result == true);
    }

    SECTION ("1 property with the different name || same quantity")
    {
        Property property1(name[0], quantity[1], price[0]);
        Property property2(name[1], quantity[1], price[0]);

        std::shared_ptr<Component> component1(new Component());
        std::shared_ptr<Component> component2(new Component());
        component1->addProperty(property1);
        component2->addProperty(property2); 

        if (*component1 >= *component2) {result = true;}
        else { result = false;}
        REQUIRE(result == false);

        if (*component2 >= *component1) {result = true;}
        else { result = false;}
        REQUIRE(result == false);
    }

    SECTION ("1 property with the different name")
    {
        Property property1(name[0], quantity[1], price[0]);
        Property property2(name[1], quantity[2], price[0]);

        std::shared_ptr<Component> component1(new Component());
        std::shared_ptr<Component> component2(new Component());
        component1->addProperty(property1);
        component2->addProperty(property2); 

        if (*component1 >= *component2) {result = true;}
        else { result = false;}
        REQUIRE(result == false);

        if (*component1 >= *component1) {result = true;}
        else { result = false;}
        REQUIRE(result == true);

        if (*component2 >= *component1) {result = true;}
        else { result = false;}
        REQUIRE(result == false);
    }

    SECTION ("2 property with the same name")
    {
        Property property1(name[0], quantity[0], price[0]);
        Property property2(name[1], quantity[1], price[0]);
        Property property3(name[0], quantity[3], price[0]);
        Property property4(name[1], quantity[1], price[0]);

        std::shared_ptr<Component> component1(new Component());
        std::shared_ptr<Component> component2(new Component());
        component1->addProperty(property1);
        component1->addProperty(property2); 
        component2->addProperty(property3);
        component2->addProperty(property4); 

        if (*component1 >= *component2) {result = true;}
        else { result = false;}
        REQUIRE(result == false);

        if (*component1 >= *component1) {result = true;}
        else { result = false;}
        REQUIRE(result == true);

        if (*component2 >= *component1) {result = true;}
        else { result = false;}
        REQUIRE(result == true);
    }

    SECTION ("2 properties - not matching")
    {
        Property property1(name[0], quantity[1], price[0]);
        Property property2(name[1], quantity[1], price[0]);
        Property property3(name[2], quantity[2], price[0]);
        Property property4(name[1], quantity[2], price[0]);

        std::shared_ptr<Component> component1(new Component());
        std::shared_ptr<Component> component2(new Component());
        component1->addProperty(property1);
        component1->addProperty(property2); 
        component2->addProperty(property3);
        component2->addProperty(property4); 

        if (*component1 >= *component2) {result = true;}
        else { result = false;}
        REQUIRE(result == false);

        if (*component2 >= *component1) {result = true;}
        else { result = false;}
        REQUIRE(result == false);
    }

    SECTION ("2 properties - not matching")
    {
        Property property1(name[0], quantity[1], price[0]);
        Property property2(name[1], quantity[1], price[0]);
        Property property3(name[1], quantity[2], price[0]);
        Property property4(name[1], quantity[2], price[0]);

        std::shared_ptr<Component> component1(new Component());
        std::shared_ptr<Component> component2(new Component());
        component1->addProperty(property1);
        component1->addProperty(property2); 
        component2->addProperty(property3);
        component2->addProperty(property4); 

        if (*component1 >= *component2) {result = true;}
        else { result = false;}
        REQUIRE(result == false);

        if (*component2 >= *component1) {result = true;}
        else { result = false;}
        REQUIRE(result == false);
    }

    SECTION ("Different property count")
    {
        Property property1(name[0], quantity[1], price[0]);
        Property property2(name[1], quantity[2], price[0]);

        std::shared_ptr<Component> component1(new Component());
        std::shared_ptr<Component> component2(new Component());
        component1->addProperty(property1);
        component2->addProperty(property2); 
        component2->addProperty(property1); 

        if (*component1 >= *component2) {result = true;}
        else { result = false;}
        REQUIRE(result == false);

        if (*component2 >= *component1) {result = true;}
        else { result = false;}
        REQUIRE(result == false);
    }
}