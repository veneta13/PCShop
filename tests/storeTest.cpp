#include "math.h"
#include "catch2.h"
#define private public //to access private methods
#include "../inc/store.hpp"

TEST_CASE("Components")
{
    Property property1("name 1", 5, 4.6);
    Property property2("name 2", 8, 0.9);
    Property property4("name 4", 1, 32.1);
    Property property5("name 5", 8, 14.2);
    Property property6("name 6", 15, 3.8);

    std::shared_ptr<Component> component1(new Component());
    std::shared_ptr<Component> component2(new Component());
    std::shared_ptr<Component> component3(new Component());
    std::shared_ptr<Component> component4(new Component());

    component1->addProperty(property1);
    component1->addProperty(property2);

    component2->addProperty(property5);
    component2->addProperty(property2);
    component2->addProperty(property1);

    component3->addProperty(property4);

    component4->addProperty(property5);
    component4->addProperty(property6);

    SECTION("Insert")
    {
        Store& store = Store::getInstance();
        REQUIRE(store.count() == 0);

        store.insertComponent(component1);
        REQUIRE(store.count() == 1);

        store.insertComponent(component1);
        REQUIRE(store.count() == 2);
        
        store.insertComponent(component2);
        REQUIRE(store.count() == 3);
    }

    SECTION("REMOVE")
    {
        Store& store = Store::getInstance();
        store.removeComponent(component2);
        REQUIRE(store.findComponent(*component2) == -1);
        store.removeComponent(component1);
        REQUIRE(store.findComponent(*component1) == 0);
        store.removeComponent(component1);
        REQUIRE(store.findComponent(*component1) == -1);
    }

    SECTION("FIND")
    {
        Store& store = Store::getInstance();
        store.insertComponent(component2);
        store.insertComponent(component3);
        store.insertComponent(component4);

        REQUIRE(store.count() == 3);
        REQUIRE(store.findComponent(*component1) == -1);
        REQUIRE(store.findComponent(*component2) == 0);
        REQUIRE(store.findComponent(*component3) == 1);
        REQUIRE(store.findComponent(*component4) == 2);
    }

    SECTION("GET BY ID")
    {
        Store& store = Store::getInstance();

        REQUIRE(store.count() == 3);
        REQUIRE(store.getComponentById(-1) == nullptr);
        REQUIRE(*(store.getComponentById(0)) == *component2);
        REQUIRE(*(store.getComponentById(1)) == *component3);
        REQUIRE(*(store.getComponentById(2)) == *component4);
        REQUIRE(store.getComponentById(3) == nullptr);
    }
}
