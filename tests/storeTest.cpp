#include "math.h"
#include "catch2.h"
#include "../inc/property.hpp"
#include "../inc/component.hpp"
#include "../inc/componentKeeper.hpp"
#include "../inc/store.hpp"

TEST_CASE("Components")
{
    Property property1("name 1", 5, 4.6);
    Property property2("name 2", 8, 0.9);
    Property property4("name 4", 1, 32.1);
    Property property5("name 5", 8, 14.2);
    Property property6("name 6", 15, 3.8);

    Component component1;
    Component component2;
    Component component3;
    Component component4;

    component1.addProperty(property1);
    component1.addProperty(property2);

    component2.addProperty(property5);
    component2.addProperty(property2);
    component2.addProperty(property1);

    component3.addProperty(property4);

    component4.addProperty(property5);
    component4.addProperty(property6);

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
        REQUIRE(store.findComponent(component2) == -1);
        store.removeComponent(component1);
        REQUIRE(store.findComponent(component1) == 0);
        store.removeComponent(component1);
        REQUIRE(store.findComponent(component1) == -1);
    }

    SECTION("FIND")
    {
        Store& store = Store::getInstance();
        store.insertComponent(component2);
        store.insertComponent(component3);
        store.insertComponent(component4);

        REQUIRE(store.count() == 3);
        REQUIRE(store.findComponent(component1) == -1);
        REQUIRE(store.findComponent(component2) == 0);
        REQUIRE(store.findComponent(component3) == 1);
        REQUIRE(store.findComponent(component4) == 2);
    }
}
