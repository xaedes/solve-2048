#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch/catch.hpp"
#include "catch/EqualsMat.hpp"

#include "game2048/Slider.h"

using namespace solve2048::game2048::slider;


TEST_CASE("Slide GameState Line", "[GameState]" ) 
{
    SECTION("{0,0,0,0} -- Empty Line")
    {
        std::vector<int> line = {0,0,0,0};
        std::vector<int> slided = slideLine(line);
        REQUIRE(slided[0] == 0);
        REQUIRE(slided[1] == 0);
        REQUIRE(slided[2] == 0);
        REQUIRE(slided[3] == 0);
    }

    SECTION("{0,0,2,4} -- Line With Empty Front")
    {
        std::vector<int> line = {0,0,2,4};
        std::vector<int> slided = slideLine(line);
        REQUIRE(slided[0] == 2);
        REQUIRE(slided[1] == 4);
        REQUIRE(slided[2] == 0);
        REQUIRE(slided[3] == 0);
    }

    SECTION("{2,4,0,0} -- Line With Empty Back")
    {
        std::vector<int> line = {2,4,0,0};
        std::vector<int> slided = slideLine(line);
        REQUIRE(slided[0] == 2);
        REQUIRE(slided[1] == 4);
        REQUIRE(slided[2] == 0);
        REQUIRE(slided[3] == 0);
    }

    SECTION("{0,2,0,4} -- Line With Back In Between #1")
    {
        std::vector<int> line = {0,2,0,4};
        std::vector<int> slided = slideLine(line);
        REQUIRE(slided[0] == 2);
        REQUIRE(slided[1] == 4);
        REQUIRE(slided[2] == 0);
        REQUIRE(slided[3] == 0);
    }

    SECTION("{2,0,4,0} -- Line With Back In Between #2")
    {
        std::vector<int> line = {2,0,4,0};
        std::vector<int> slided = slideLine(line);
        REQUIRE(slided[0] == 2);
        REQUIRE(slided[1] == 4);
        REQUIRE(slided[2] == 0);
        REQUIRE(slided[3] == 0);
    }

    SECTION("{0,2,4,0} -- Line With Back In Between #3")
    {
        std::vector<int> line = {0,2,4,0};
        std::vector<int> slided = slideLine(line);
        REQUIRE(slided[0] == 2);
        REQUIRE(slided[1] == 4);
        REQUIRE(slided[2] == 0);
        REQUIRE(slided[3] == 0);
    }

    SECTION("{2,4,8,16} -- Full Line")
    {
        std::vector<int> line = {2,4,8,16};
        std::vector<int> slided = slideLine(line);
        REQUIRE(slided[0] == 2);
        REQUIRE(slided[1] == 4);
        REQUIRE(slided[2] == 8);
        REQUIRE(slided[3] == 16);
    }

    SECTION("{2,2,8,16} -- Full Line, Merge a pair In Front")
    {
        std::vector<int> line = {2,2,8,16};
        std::vector<int> slided = slideLine(line);
        REQUIRE(slided[0] == 4);
        REQUIRE(slided[1] == 8);
        REQUIRE(slided[2] == 16);
        REQUIRE(slided[3] == 0);
    }

    SECTION("{8,16,2,2} -- Full Line, Merge a pair In Back")
    {
        std::vector<int> line = {8,16,2,2};
        std::vector<int> slided = slideLine(line);
        REQUIRE(slided[0] == 8);
        REQUIRE(slided[1] == 16);
        REQUIRE(slided[2] == 4);
        REQUIRE(slided[3] == 0);
    }

    SECTION("{2,2,2,2} -- Full Line, Merge line of identical numbers")
    {
        std::vector<int> line = {2,2,2,2};
        std::vector<int> slided = slideLine(line);
        REQUIRE(slided[0] == 4);
        REQUIRE(slided[1] == 4);
        REQUIRE(slided[2] == 0);
        REQUIRE(slided[3] == 0);
    }

    SECTION("{2,2,4,4} -- Full Line, Merge two not identical pairs #1")
    {
        std::vector<int> line = {2,2,4,4};
        std::vector<int> slided = slideLine(line);
        REQUIRE(slided[0] == 4);
        REQUIRE(slided[1] == 8);
        REQUIRE(slided[2] == 0);
        REQUIRE(slided[3] == 0);
    }

    SECTION("{2,2,8,8} -- Full Line, Merge two not identical pairs #2")
    {
        std::vector<int> line = {2,2,8,8};
        std::vector<int> slided = slideLine(line);
        REQUIRE(slided[0] == 4);
        REQUIRE(slided[1] == 16);
        REQUIRE(slided[2] == 0);
        REQUIRE(slided[3] == 0);
    }

    SECTION("{2,2,2,8} -- Full Line, Merge triple In Front")
    {
        std::vector<int> line = {2,2,2,8};
        std::vector<int> slided = slideLine(line);
        REQUIRE(slided[0] == 4);
        REQUIRE(slided[1] == 2);
        REQUIRE(slided[2] == 8);
        REQUIRE(slided[3] == 0);
    }

    SECTION("{8,2,2,2} -- Full Line, Merge triple In Back")
    {
        std::vector<int> line = {8,2,2,2};
        std::vector<int> slided = slideLine(line);
        REQUIRE(slided[0] == 8);
        REQUIRE(slided[1] == 4);
        REQUIRE(slided[2] == 2);
        REQUIRE(slided[3] == 0);
    }

    SECTION("{2,2,0,0} -- With Empties, Merge a pair In Front")
    {
        std::vector<int> line = {2,2,0,0};
        std::vector<int> slided = slideLine(line);
        REQUIRE(slided[0] == 4);
        REQUIRE(slided[1] == 0);
        REQUIRE(slided[2] == 0);
        REQUIRE(slided[3] == 0);
    }

    SECTION("{0,0,2,2} -- With Empties, Merge a pair In Back")
    {
        std::vector<int> line = {0,0,2,2};
        std::vector<int> slided = slideLine(line);
        REQUIRE(slided[0] == 4);
        REQUIRE(slided[1] == 0);
        REQUIRE(slided[2] == 0);
        REQUIRE(slided[3] == 0);
    }

    SECTION("{0,2,2,0} -- With Empties, Merge a pair In Middle")
    {
        std::vector<int> line = {0,2,2,0};
        std::vector<int> slided = slideLine(line);
        REQUIRE(slided[0] == 4);
        REQUIRE(slided[1] == 0);
        REQUIRE(slided[2] == 0);
        REQUIRE(slided[3] == 0);
    }

    SECTION("{2,2,2,0} -- With Empties, Merge triple In Front")
    {
        std::vector<int> line = {2,2,2,0};
        std::vector<int> slided = slideLine(line);
        REQUIRE(slided[0] == 4);
        REQUIRE(slided[1] == 2);
        REQUIRE(slided[2] == 0);
        REQUIRE(slided[3] == 0);
    }

    SECTION("{0,2,2,2} -- With Empties, Merge triple In Back")
    {
        std::vector<int> line = {0,2,2,2};
        std::vector<int> slided = slideLine(line);
        REQUIRE(slided[0] == 4);
        REQUIRE(slided[1] == 2);
        REQUIRE(slided[2] == 0);
        REQUIRE(slided[3] == 0);
    }

    SECTION("{2,2,0,0} -- 2+2=4")
    {
        std::vector<int> line = {2,2,0,0};
        std::vector<int> slided = slideLine(line);
        REQUIRE(slided[0] == 4);
        REQUIRE(slided[1] == 0);
        REQUIRE(slided[2] == 0);
        REQUIRE(slided[3] == 0);
    }

    SECTION("{4,4,0,0} -- 4+4=8")
    {
        std::vector<int> line = {4,4,0,0};
        std::vector<int> slided = slideLine(line);
        REQUIRE(slided[0] == 8);
        REQUIRE(slided[1] == 0);
        REQUIRE(slided[2] == 0);
        REQUIRE(slided[3] == 0);
    }

    SECTION("{8,8,0,0} -- 8+8=16")
    {
        std::vector<int> line = {8,8,0,0};
        std::vector<int> slided = slideLine(line);
        REQUIRE(slided[0] == 16);
        REQUIRE(slided[1] == 0);
        REQUIRE(slided[2] == 0);
        REQUIRE(slided[3] == 0);
    }

    SECTION("{16,16,0,0} -- 16+16=32")
    {
        std::vector<int> line = {16,16,0,0};
        std::vector<int> slided = slideLine(line);
        REQUIRE(slided[0] == 32);
        REQUIRE(slided[1] == 0);
        REQUIRE(slided[2] == 0);
        REQUIRE(slided[3] == 0);
    }

    SECTION("{32,32,0,0} -- 32+32=64")
    {
        std::vector<int> line = {32,32,0,0};
        std::vector<int> slided = slideLine(line);
        REQUIRE(slided[0] == 64);
        REQUIRE(slided[1] == 0);
        REQUIRE(slided[2] == 0);
        REQUIRE(slided[3] == 0);
    }

    SECTION("{64,64,0,0} -- 64+64=128")
    {
        std::vector<int> line = {64,64,0,0};
        std::vector<int> slided = slideLine(line);
        REQUIRE(slided[0] == 128);
        REQUIRE(slided[1] == 0);
        REQUIRE(slided[2] == 0);
        REQUIRE(slided[3] == 0);
    }

    SECTION("{128,128,0,0} -- 128+128=256")
    {
        std::vector<int> line = {128,128,0,0};
        std::vector<int> slided = slideLine(line);
        REQUIRE(slided[0] == 256);
        REQUIRE(slided[1] == 0);
        REQUIRE(slided[2] == 0);
        REQUIRE(slided[3] == 0);
    }

    SECTION("{256,256,0,0} -- 256+256=512")
    {
        std::vector<int> line = {256,256,0,0};
        std::vector<int> slided = slideLine(line);
        REQUIRE(slided[0] == 512);
        REQUIRE(slided[1] == 0);
        REQUIRE(slided[2] == 0);
        REQUIRE(slided[3] == 0);
    }
}
