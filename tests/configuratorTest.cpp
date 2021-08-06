#include "math.h"
#include "catch2.h"
#define private public //to access private methods 
#include "../inc/configurator.hpp"

TEST_CASE("Create Configuration")
{

    SECTION("Empty requirement")
    {
        Property property1("property1", 5, 4.6);
        Property property2("property2", 8, 0.9);
    
        std::shared_ptr<Component> component1(new Cpu());

        component1->addProperty(property1);
        component1->addProperty(property2);

        Store& store = Store::getInstance();

        store.insertComponent(component1);

        Requirement requirement;
        Configurator configurator(&store);
        std::shared_ptr<Configuration> dummyConfiguration;
        dummyConfiguration = configurator.createConfiguration(requirement);

        REQUIRE(dummyConfiguration == nullptr);
        REQUIRE(store.count() == 1);
        REQUIRE(store.findComponent(*component1) != -1);
        store.removeComponent(component1);
        REQUIRE(store.count() == 0);
    }

    //using separate variable to fix some Catch2 bug
    bool result;

    SECTION("1 component in requirement")
    {
        Store& store = Store::getInstance();
        REQUIRE(store.count() == 0);

        std::shared_ptr<Component> component2(new Ram());
        Property property1("property1", 5, 4.6);
        Property property2("property2", 8, 0.9);
        Property property5("property5", 8, 14.2);
        component2->addProperty(property1);
	    component2->addProperty(property2);
	    component2->addProperty(property5);

        store.insertComponent(component2);

        Requirement requirement;
        requirement.insertComponent(component2);

        Configurator configurator(&store);
        std::shared_ptr<Configuration> dummyConfiguration;

        dummyConfiguration = configurator.createConfiguration(requirement);

        if (*dummyConfiguration->getComponentById(0) == *component2) {result = true;}
        else {result = false;}
        REQUIRE(result == true);

        REQUIRE(dummyConfiguration->count() == 1);
        REQUIRE(store.count() == 0);
        REQUIRE(store.findComponent(*component2) == -1);
    }

    SECTION("2 components in requirement")
    {
        Store& store = Store::getInstance();
        REQUIRE(store.count() == 0);

        std::shared_ptr<Component> component3(new Hdd());
        std::shared_ptr<Component> component4(new Ram());

        Property property3("property3", 15, 3.8);
        Property property4("property4", 1, 32.1);
        Property property5("property5", 8, 14.2);

        component3->addProperty(property4);
        component4->addProperty(property5);
        component4->addProperty(property3);

        store.insertComponent(component3);
        store.insertComponent(component4);
        REQUIRE(store.count() == 2);
        Requirement requirement;
        requirement.insertComponent(component3);
        requirement.insertComponent(component4);

        Configurator configurator(&store);
        std::shared_ptr<Configuration> dummyConfiguration;

        dummyConfiguration = configurator.createConfiguration(requirement);

        if (*dummyConfiguration->getComponentById(0) == *component3) {result = true;}
        else {result = false;}
        REQUIRE(result == true);
        result = false;

        if (*dummyConfiguration->getComponentById(1) == *component4) {result = true;}
        else {result = false;}
        REQUIRE(result == true);
        
        REQUIRE(dummyConfiguration->count() == 2);
        REQUIRE(store.count() == 0);
        REQUIRE(store.findComponent(*component3) == -1);
        REQUIRE(store.findComponent(*component4) == -1);
    }

    SECTION("2 components in requirement || test with better configuration")
    {
        Store& store = Store::getInstance();
        REQUIRE(store.count() == 0);

        std::shared_ptr<Component> component1(new Ram());
        std::shared_ptr<Component> component2(new Hdd());
        std::shared_ptr<Component> component3(new Ram());

        Property propertyram1("core", 6, 30.8);
        Property propertyram1_1("core", 8, 32.1);
        Property propertyram2("frequency", 6800, 0.02);
        Property propertyram2_1("frequency", 8000, 0.03);
        Property propertyhdd1("property3", 15, 3.8);
        Property propertyhdd2("property5", 8, 14.2);

        component1->addProperty(propertyram1);
        component2->addProperty(propertyhdd1);
        component3->addProperty(propertyram1_1);
        component1->addProperty(propertyram2);
        component2->addProperty(propertyhdd2);
        component3->addProperty(propertyram2_1);

        store.insertComponent(component2);
        store.insertComponent(component3);
        REQUIRE(store.count() == 2);

        Requirement requirement;
        requirement.insertComponent(component1);
        requirement.insertComponent(component2);

        Configurator configurator(&store);
        std::shared_ptr<Configuration> dummyConfiguration;

        dummyConfiguration = configurator.createConfiguration(requirement);

        if (*dummyConfiguration->getComponentById(0) == *component3) {result = true;}
        else {result = false;}
        REQUIRE(result == true);
        result = false;

        if (*dummyConfiguration->getComponentById(1) == *component2) {result = true;}
        else {result = false;}
        REQUIRE(result == true);
        
        REQUIRE(dummyConfiguration->count() == 2);
        REQUIRE(store.count() == 0);
        REQUIRE(store.findComponent(*component3) == -1);
        REQUIRE(store.findComponent(*component1) == -1);
    }

    SECTION("2 components in requirement || test with better configuration")
    {
        Store& store = Store::getInstance();
        REQUIRE(store.count() == 0);

        std::shared_ptr<Component> component1(new Ram());
        std::shared_ptr<Component> component2(new Hdd());

        Property propertyram1("core", 6, 30.8);
        Property propertyram2("frequency", 6800, 0.02);
        Property propertyhdd1("property3", 15, 3.8);
        Property propertyhdd2("property5", 8, 14.2);

        component1->addProperty(propertyram1);
        component2->addProperty(propertyhdd1);
        component1->addProperty(propertyram2);
        component2->addProperty(propertyhdd2);

        store.insertComponent(component2);
        REQUIRE(store.count() == 1);

        Requirement requirement;
        requirement.insertComponent(component1);
        requirement.insertComponent(component2);

        Configurator configurator(&store);
        std::shared_ptr<Configuration> dummyConfiguration;

        dummyConfiguration = configurator.createConfiguration(requirement);
        
        REQUIRE(dummyConfiguration == nullptr);
        REQUIRE(store.count() == 1);
        REQUIRE(store.findComponent(*component2) == 0);
    }
}