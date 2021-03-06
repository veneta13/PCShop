#include "math.h"
#include "catch2.h"
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
        REQUIRE(myCPU.tellType() == "CPU");
        REQUIRE(myCPU.stringify() == "CPU \"core count\" 4 120.00 frequency 5300 0.05 ");
    }

    SECTION("RAM")
    {
        Property gigabytes("GB", 8, 20);
        Property chips("chip count", 5, 30);
        Property rgb("colors", 10, 5);


        Ram myRAM;
        myRAM.addProperty(gigabytes);
        myRAM.addProperty(chips);
        myRAM.addProperty(rgb);

        REQUIRE(floor(myRAM.getPrice()) == 360);
        REQUIRE(myRAM.tellType() == "RAM");
        REQUIRE(myRAM.stringify() == "RAM GB 8 20.00 \"chip count\" 5 30.00 colors 10 5.00 ");
    }

    SECTION("HDD")
    {
        Property terabytes("TB", 1, 300);
        Property readingSpeed("reading speed", 150, 0.5);
        Property writingSpeed("writing speed", 140, 0.6);


        Hdd myHDD;
        myHDD.addProperty(terabytes);
        myHDD.addProperty(readingSpeed);
        myHDD.addProperty(writingSpeed);

        REQUIRE(floor(myHDD.getPrice()) == 459);
        REQUIRE(myHDD.tellType() == "HDD");
        REQUIRE(myHDD.stringify() == "HDD TB 1 300.00 \"reading speed\" 150 0.50 \"writing speed\" 140 0.60 ");
    }
}