#include "catch2.h"
#include "../inc/availableComponents.hpp"
#define private public //to access private methods 
#include "../inc/requirementBuilder.hpp"

//define EPSILON for double comparison
#define EPSILON 0.000001

TEST_CASE("Create component of different object types")
{
    SECTION("CPU")
    {
        RequirementBuilder builder;
        std::shared_ptr<Component> c = builder.createComponent("CPU");
        Cpu cpu;

        REQUIRE(typeid(*c) == typeid(cpu));
    }

    SECTION("RAM")
    {
        RequirementBuilder builder;
        std::shared_ptr<Component> c = builder.createComponent("RAM");
        Ram ram;

        REQUIRE(typeid(*c) == typeid(ram));
    }

    SECTION("HDD")
    {
        RequirementBuilder builder;
        std::shared_ptr<Component> c = builder.createComponent("HDD");
        Hdd hdd;

        REQUIRE(typeid(*c) == typeid(hdd));
    }

    SECTION("Error")
    {
        RequirementBuilder builder;
        std::shared_ptr<Component> c = builder.createComponent("other");

        REQUIRE(c == nullptr);
    }
}

TEST_CASE("Build property")
{
    SECTION("Name - no space")
    {
        RequirementBuilder builder;

        RequirementBuilder::PropertyStruct propertyStr;
        propertyStr.name = "cores";
        propertyStr.quantity = 2;
        propertyStr.price = 100.2;

        Property property = builder.buildProperty(propertyStr);
        
        REQUIRE(property.getName() == "cores");
        REQUIRE(property.getQuantity() == 2);
        REQUIRE(abs(property.getPrice() - 100.2) < EPSILON);
    }

    SECTION("Name - 1 space")
    {
        RequirementBuilder builder;

        RequirementBuilder::PropertyStruct propertyStr;
        propertyStr.name = "core count";
        propertyStr.quantity = 5;
        propertyStr.price = 10.2;

        Property property = builder.buildProperty(propertyStr);
        
        REQUIRE(property.getName() == "core count");
        REQUIRE(property.getQuantity() == 5);
        REQUIRE(abs(property.getPrice() - 10.2) < EPSILON);
    }
}