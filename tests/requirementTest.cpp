#include "catch2.h"
#define private public //to access private methods
#include "../inc/requirement.hpp"

TEST_CASE("Requirement")
{
    Property property1("name 1", 5, 4.6);
    Property property2("name 2", 8, 0.9);
    Property property3("name 3", 15, 3.8);
    Property property4("name 4", 1, 32.1);
    Property property5("name 5", 8, 14.2);
   

    std::shared_ptr<Component> component1(new Cpu());
    std::shared_ptr<Component> component2(new Ram());
    std::shared_ptr<Component> component3(new Hdd());
    std::shared_ptr<Component> component4(new Component());

    component1->addProperty(property1);
    component1->addProperty(property2);

    component2->addProperty(property5);
    component2->addProperty(property2);
    component2->addProperty(property1);

    component3->addProperty(property4);

    component4->addProperty(property5);
    component4->addProperty(property3);

    SECTION("INSERT COMPONENTS")
    {
        Requirement dummyRequirement;
        REQUIRE(dummyRequirement.count() == 0);
        dummyRequirement.insertComponent(component1);
        REQUIRE(dummyRequirement.count() == 1);
        dummyRequirement.insertComponent(component2);
        REQUIRE(dummyRequirement.count() == 2);
        dummyRequirement.insertComponent(component3);
        REQUIRE(dummyRequirement.count() == 3);
    }

    SECTION("REMOVE COMPONENTS")
    {
        Requirement dummyRequirement;
        REQUIRE(dummyRequirement.count() == 0);
        dummyRequirement.insertComponent(component1);
        dummyRequirement.insertComponent(component2);
        dummyRequirement.insertComponent(component3);
        REQUIRE(dummyRequirement.count() == 3);

        REQUIRE(dummyRequirement.getComponent(*component1) != nullptr);
        dummyRequirement.removeComponent(component1);
        REQUIRE(dummyRequirement.count() == 2);
        REQUIRE(dummyRequirement.getComponent(*component1) == nullptr);

        REQUIRE(dummyRequirement.getComponent(*component2) != nullptr);
        dummyRequirement.removeComponent(component2);
        REQUIRE(dummyRequirement.count() == 1);
        REQUIRE(dummyRequirement.getComponent(*component2) == nullptr);

        REQUIRE(dummyRequirement.getComponent(*component3) != nullptr);
        dummyRequirement.removeComponent(component3);
        REQUIRE(dummyRequirement.count() == 0);
        REQUIRE(dummyRequirement.getComponent(*component3) == nullptr);

        REQUIRE(dummyRequirement.getComponent(*component4) == nullptr);
    }

    SECTION("INSERT VALIDATION")
    {
        Requirement dummyRequirement;
        REQUIRE(dummyRequirement.count() == 0);

        std::shared_ptr<Component> myCpu2(new Cpu());

        myCpu2->addProperty(property5);
        myCpu2->addProperty(property1);

        dummyRequirement.insertComponent(component1);
        dummyRequirement.insertComponent(component2);
        REQUIRE(dummyRequirement.count() == 2);
        dummyRequirement.insertComponent(myCpu2);

        REQUIRE(dummyRequirement.count() == 2);
        REQUIRE(dummyRequirement.getComponent(*myCpu2) == nullptr);
    }

    SECTION("GET BY ID")
    {
        Requirement dummyRequirement;
        REQUIRE(dummyRequirement.count() == 0);

        dummyRequirement.insertComponent(component1);
        dummyRequirement.insertComponent(component2);

        REQUIRE(dummyRequirement.getComponentById(-1) == nullptr);
        REQUIRE(dummyRequirement.getComponentById(0) == component1);
        REQUIRE(dummyRequirement.getComponentById(1) == component2);
        REQUIRE(dummyRequirement.getComponentById(2) == nullptr);
    }
}