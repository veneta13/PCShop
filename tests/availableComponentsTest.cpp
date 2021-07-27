#include "math.h"
#include "catch2.h"
#include "../inc/property.hpp"
#include "../inc/component.hpp"
#include "../inc/availableComponents.hpp"

TEST_CASE("Inheritance")
{
    SECTION("CPU")
    {
        Property cores("core count", 4, 120);
        Property frequency("frequency", 5300, 0.05);


        Cpu myCPU;
        myCPU.addProperty(cores);
        myCPU.addProperty(frequency);

        REQUIRE(floor(myCPU.getPrice()) == 745);
    }

    SECTION("RAM")
    {
        Property gigabytes("GB", 8, 20);
        Property chips("chip count", 5, 30);
        Property rgb("colors", 10, 5);


        Cpu myCPU;
        myCPU.addProperty(gigabytes);
        myCPU.addProperty(chips);
        myCPU.addProperty(rgb);

        REQUIRE(floor(myCPU.getPrice()) == 360);
    }

    SECTION("HDD")
    {
        Property terabytes("TB", 1, 300);
        Property readingSpeed("reading speed", 150, 0.5);
        Property writingSpeed("writing speed", 140, 0.6);


        Cpu myCPU;
        myCPU.addProperty(terabytes);
        myCPU.addProperty(readingSpeed);
        myCPU.addProperty(writingSpeed);

        REQUIRE(floor(myCPU.getPrice()) == 459);
    }
}