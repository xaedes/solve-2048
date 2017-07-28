#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch/catch.hpp"
#include "catch/EqualsMat.hpp"

#include "game2048/GameState.h"

using namespace solve2048::game2048;

TEST_CASE("Starting with an empty GameState", "[GameState]" ) 
{
    GameState gameState;

    SECTION("all cells are empty")
    {
        for (int y=0; y<4; y++)
        {
            for (int x=0; x<4; x++)
            {
                REQUIRE(gameState.cell(x,y) == 0);
            }
        }
    }

    SECTION("all cells can be set and get")
    {
        int k=1;
        for (int y=0; y<4; y++)
        {
            for (int x=0; x<4; x++)
            {
                gameState.cell(x,y)=k;
                REQUIRE(gameState.cell(x,y) == k);
                k++;
            }
        }
    }
}

TEST_CASE("GameState Copy Constructor and Assignment", "[GameState]" )
{
    GameState gameState;

    int k=1;
    for (int y=0; y<4; y++)
    {
        for (int x=0; x<4; x++)
        {
            gameState.cell(x,y)=k;
            k++;
        }
    }

    SECTION("Copy by assignment/decleration")
    {
        GameState gameStateCopy = gameState;
        REQUIRE_THAT(gameState.state, EqualsMat(gameStateCopy.state));
    }

    SECTION("Copy by assignment")
    {
        GameState gameStateCopy;
        gameStateCopy = gameState;
        REQUIRE_THAT(gameState.state, EqualsMat(gameStateCopy.state));
    }
    SECTION("Copy by copy constructor")
    {
        GameState gameStateCopy(gameState);
        REQUIRE_THAT(gameState.state, EqualsMat(gameStateCopy.state));
    }

}
TEST_CASE("Starting with two identically filled GameStates", "[GameState]" ) 
{
    GameState gameState;

    int k=1;
    for (int y=0; y<4; y++)
    {
        for (int x=0; x<4; x++)
        {
            gameState.cell(x,y)=k;
            k++;
        }
    }
    GameState gameStateCopy = gameState;

    SECTION("Rotation Verify CW")
    {
        gameState.rotateClockwise();
        int k=1;
        REQUIRE(gameState.cell(3,0) == k++);
        REQUIRE(gameState.cell(3,1) == k++);
        REQUIRE(gameState.cell(3,2) == k++);
        REQUIRE(gameState.cell(3,3) == k++);
        REQUIRE(gameState.cell(2,0) == k++);
        REQUIRE(gameState.cell(2,1) == k++);
        REQUIRE(gameState.cell(2,2) == k++);
        REQUIRE(gameState.cell(2,3) == k++);
        REQUIRE(gameState.cell(1,0) == k++);
        REQUIRE(gameState.cell(1,1) == k++);
        REQUIRE(gameState.cell(1,2) == k++);
        REQUIRE(gameState.cell(1,3) == k++);
        REQUIRE(gameState.cell(0,0) == k++);
        REQUIRE(gameState.cell(0,1) == k++);
        REQUIRE(gameState.cell(0,2) == k++);
        REQUIRE(gameState.cell(0,3) == k++);
    }
    SECTION("Rotation CW+CCW=0")
    {
        
        gameState.rotateClockwise();
        gameState.rotateCounterClockwise();
        REQUIRE_THAT(gameState.state, EqualsMat(gameStateCopy.state));
    }
    SECTION("Rotation CCW+CW=0")
    {
        gameState.rotateCounterClockwise();
        gameState.rotateClockwise();
        REQUIRE_THAT(gameState.state, EqualsMat(gameStateCopy.state));
    }
    SECTION("Rotation 4*CW=0")
    {
        gameState.rotateClockwise();
        gameState.rotateClockwise();
        gameState.rotateClockwise();
        gameState.rotateClockwise();
        REQUIRE_THAT(gameState.state, EqualsMat(gameStateCopy.state));
    }
    SECTION("Rotation 4*CCW=0")
    {
        gameState.rotateCounterClockwise();
        gameState.rotateCounterClockwise();
        gameState.rotateCounterClockwise();
        gameState.rotateCounterClockwise();
        REQUIRE_THAT(gameState.state, EqualsMat(gameStateCopy.state));
    }

}
TEST_CASE("Get GameState Lines", "[GameState]" ) 
{
    GameState gameState;

    int k=1;
    for (int y=0; y<4; y++)
    {
        for (int x=0; x<4; x++)
        {
            gameState.cell(x,y)=k;
            k++;
        }
    }

    SECTION("test row 0")
    {
        std::vector<int> row = gameState.row(0);
        REQUIRE(row[0] == 1);
        REQUIRE(row[1] == 2);
        REQUIRE(row[2] == 3);
        REQUIRE(row[3] == 4);
    }

    SECTION("test row 1")
    {
        std::vector<int> row = gameState.row(1);
        REQUIRE(row[0] == 5);
        REQUIRE(row[1] == 6);
        REQUIRE(row[2] == 7);
        REQUIRE(row[3] == 8);
    }

    SECTION("test row 2")
    {
        std::vector<int> row = gameState.row(2);
        REQUIRE(row[0] == 9);
        REQUIRE(row[1] == 10);
        REQUIRE(row[2] == 11);
        REQUIRE(row[3] == 12);
    }

    SECTION("test row 3")
    {
        std::vector<int> row = gameState.row(3);
        REQUIRE(row[0] == 13);
        REQUIRE(row[1] == 14);
        REQUIRE(row[2] == 15);
        REQUIRE(row[3] == 16);
    }
    SECTION("test col 0")
    {
        std::vector<int> col = gameState.col(0);
        REQUIRE(col[0] == 1);
        REQUIRE(col[1] == 5);
        REQUIRE(col[2] == 9);
        REQUIRE(col[3] == 13);
    }

    SECTION("test col 1")
    {
        std::vector<int> col = gameState.col(1);
        REQUIRE(col[0] == 2);
        REQUIRE(col[1] == 6);
        REQUIRE(col[2] == 10);
        REQUIRE(col[3] == 14);
    }

    SECTION("test col 2")
    {
        std::vector<int> col = gameState.col(2);
        REQUIRE(col[0] == 3);
        REQUIRE(col[1] == 7);
        REQUIRE(col[2] == 11);
        REQUIRE(col[3] == 15);
    }

    SECTION("test col 3")
    {
        std::vector<int> col = gameState.col(3);
        REQUIRE(col[0] == 4);
        REQUIRE(col[1] == 8);
        REQUIRE(col[2] == 12);
        REQUIRE(col[3] == 16);
    }
}
TEST_CASE("Slide GameState Line", "[GameState]" ) 
{
    SECTION("{0,0,0,0} -- Empty Line")
    {
        std::vector<int> line = {0,0,0,0};
        auto slided = GameState::slideLine(line);
        REQUIRE(slided[0] == 0);
        REQUIRE(slided[1] == 0);
        REQUIRE(slided[2] == 0);
        REQUIRE(slided[3] == 0);
    }

    SECTION("{0,0,2,4} -- Line With Empty Front")
    {
        std::vector<int> line = {0,0,2,4};
        auto slided = GameState::slideLine(line);
        REQUIRE(slided[0] == 2);
        REQUIRE(slided[1] == 4);
        REQUIRE(slided[2] == 0);
        REQUIRE(slided[3] == 0);
    }

    SECTION("{2,4,0,0} -- Line With Empty Back")
    {
        std::vector<int> line = {2,4,0,0};
        auto slided = GameState::slideLine(line);
        REQUIRE(slided[0] == 2);
        REQUIRE(slided[1] == 4);
        REQUIRE(slided[2] == 0);
        REQUIRE(slided[3] == 0);
    }

    SECTION("{0,2,0,4} -- Line With Back In Between #1")
    {
        std::vector<int> line = {0,2,0,4};
        auto slided = GameState::slideLine(line);
        REQUIRE(slided[0] == 2);
        REQUIRE(slided[1] == 4);
        REQUIRE(slided[2] == 0);
        REQUIRE(slided[3] == 0);
    }

    SECTION("{2,0,4,0} -- Line With Back In Between #2")
    {
        std::vector<int> line = {2,0,4,0};
        auto slided = GameState::slideLine(line);
        REQUIRE(slided[0] == 2);
        REQUIRE(slided[1] == 4);
        REQUIRE(slided[2] == 0);
        REQUIRE(slided[3] == 0);
    }

    SECTION("{0,2,4,0} -- Line With Back In Between #3")
    {
        std::vector<int> line = {0,2,4,0};
        auto slided = GameState::slideLine(line);
        REQUIRE(slided[0] == 2);
        REQUIRE(slided[1] == 4);
        REQUIRE(slided[2] == 0);
        REQUIRE(slided[3] == 0);
    }

    SECTION("{2,4,8,16} -- Full Line")
    {
        std::vector<int> line = {2,4,8,16};
        auto slided = GameState::slideLine(line);
        REQUIRE(slided[0] == 2);
        REQUIRE(slided[1] == 4);
        REQUIRE(slided[2] == 8);
        REQUIRE(slided[3] == 16);
    }

    SECTION("{2,2,8,16} -- Full Line, Merge a pair In Front")
    {
        std::vector<int> line = {2,2,8,16};
        auto slided = GameState::slideLine(line);
        REQUIRE(slided[0] == 4);
        REQUIRE(slided[1] == 8);
        REQUIRE(slided[2] == 16);
        REQUIRE(slided[3] == 0);
    }

    SECTION("{8,16,2,2} -- Full Line, Merge a pair In Back")
    {
        std::vector<int> line = {8,16,2,2};
        auto slided = GameState::slideLine(line);
        REQUIRE(slided[0] == 8);
        REQUIRE(slided[1] == 16);
        REQUIRE(slided[2] == 4);
        REQUIRE(slided[3] == 0);
    }

    SECTION("{2,2,2,2} -- Full Line, Merge line of identical numbers")
    {
        std::vector<int> line = {2,2,2,2};
        auto slided = GameState::slideLine(line);
        REQUIRE(slided[0] == 4);
        REQUIRE(slided[1] == 4);
        REQUIRE(slided[2] == 0);
        REQUIRE(slided[3] == 0);
    }

    SECTION("{2,2,4,4} -- Full Line, Merge two not identical pairs #1")
    {
        std::vector<int> line = {2,2,4,4};
        auto slided = GameState::slideLine(line);
        REQUIRE(slided[0] == 4);
        REQUIRE(slided[1] == 8);
        REQUIRE(slided[2] == 0);
        REQUIRE(slided[3] == 0);
    }

    SECTION("{2,2,8,8} -- Full Line, Merge two not identical pairs #2")
    {
        std::vector<int> line = {2,2,8,8};
        auto slided = GameState::slideLine(line);
        REQUIRE(slided[0] == 4);
        REQUIRE(slided[1] == 16);
        REQUIRE(slided[2] == 0);
        REQUIRE(slided[3] == 0);
    }

    SECTION("{2,2,2,8} -- Full Line, Merge triple In Front")
    {
        std::vector<int> line = {2,2,2,8};
        auto slided = GameState::slideLine(line);
        REQUIRE(slided[0] == 4);
        REQUIRE(slided[1] == 2);
        REQUIRE(slided[2] == 8);
        REQUIRE(slided[3] == 0);
    }

    SECTION("{8,2,2,2} -- Full Line, Merge triple In Back")
    {
        std::vector<int> line = {8,2,2,2};
        auto slided = GameState::slideLine(line);
        REQUIRE(slided[0] == 8);
        REQUIRE(slided[1] == 4);
        REQUIRE(slided[2] == 2);
        REQUIRE(slided[3] == 0);
    }

    SECTION("{2,2,0,0} -- With Empties, Merge a pair In Front")
    {
        std::vector<int> line = {2,2,0,0};
        auto slided = GameState::slideLine(line);
        REQUIRE(slided[0] == 4);
        REQUIRE(slided[1] == 0);
        REQUIRE(slided[2] == 0);
        REQUIRE(slided[3] == 0);
    }

    SECTION("{0,0,2,2} -- With Empties, Merge a pair In Back")
    {
        std::vector<int> line = {0,0,2,2};
        auto slided = GameState::slideLine(line);
        REQUIRE(slided[0] == 4);
        REQUIRE(slided[1] == 0);
        REQUIRE(slided[2] == 0);
        REQUIRE(slided[3] == 0);
    }

    SECTION("{0,2,2,0} -- With Empties, Merge a pair In Middle")
    {
        std::vector<int> line = {0,2,2,0};
        auto slided = GameState::slideLine(line);
        REQUIRE(slided[0] == 4);
        REQUIRE(slided[1] == 0);
        REQUIRE(slided[2] == 0);
        REQUIRE(slided[3] == 0);
    }

    SECTION("{2,2,2,0} -- With Empties, Merge triple In Front")
    {
        std::vector<int> line = {2,2,2,0};
        auto slided = GameState::slideLine(line);
        REQUIRE(slided[0] == 4);
        REQUIRE(slided[1] == 2);
        REQUIRE(slided[2] == 0);
        REQUIRE(slided[3] == 0);
    }

    SECTION("{0,2,2,2} -- With Empties, Merge triple In Back")
    {
        std::vector<int> line = {0,2,2,2};
        auto slided = GameState::slideLine(line);
        REQUIRE(slided[0] == 4);
        REQUIRE(slided[1] == 2);
        REQUIRE(slided[2] == 0);
        REQUIRE(slided[3] == 0);
    }

    SECTION("{2,2,0,0} -- 2+2=4")
    {
        std::vector<int> line = {2,2,0,0};
        auto slided = GameState::slideLine(line);
        REQUIRE(slided[0] == 4);
        REQUIRE(slided[1] == 0);
        REQUIRE(slided[2] == 0);
        REQUIRE(slided[3] == 0);
    }

    SECTION("{4,4,0,0} -- 4+4=8")
    {
        std::vector<int> line = {4,4,0,0};
        auto slided = GameState::slideLine(line);
        REQUIRE(slided[0] == 8);
        REQUIRE(slided[1] == 0);
        REQUIRE(slided[2] == 0);
        REQUIRE(slided[3] == 0);
    }

    SECTION("{8,8,0,0} -- 8+8=16")
    {
        std::vector<int> line = {8,8,0,0};
        auto slided = GameState::slideLine(line);
        REQUIRE(slided[0] == 16);
        REQUIRE(slided[1] == 0);
        REQUIRE(slided[2] == 0);
        REQUIRE(slided[3] == 0);
    }

    SECTION("{16,16,0,0} -- 16+16=32")
    {
        std::vector<int> line = {16,16,0,0};
        auto slided = GameState::slideLine(line);
        REQUIRE(slided[0] == 32);
        REQUIRE(slided[1] == 0);
        REQUIRE(slided[2] == 0);
        REQUIRE(slided[3] == 0);
    }

    SECTION("{32,32,0,0} -- 32+32=64")
    {
        std::vector<int> line = {32,32,0,0};
        auto slided = GameState::slideLine(line);
        REQUIRE(slided[0] == 64);
        REQUIRE(slided[1] == 0);
        REQUIRE(slided[2] == 0);
        REQUIRE(slided[3] == 0);
    }

    SECTION("{64,64,0,0} -- 64+64=128")
    {
        std::vector<int> line = {64,64,0,0};
        auto slided = GameState::slideLine(line);
        REQUIRE(slided[0] == 128);
        REQUIRE(slided[1] == 0);
        REQUIRE(slided[2] == 0);
        REQUIRE(slided[3] == 0);
    }

    SECTION("{128,128,0,0} -- 128+128=256")
    {
        std::vector<int> line = {128,128,0,0};
        auto slided = GameState::slideLine(line);
        REQUIRE(slided[0] == 256);
        REQUIRE(slided[1] == 0);
        REQUIRE(slided[2] == 0);
        REQUIRE(slided[3] == 0);
    }

    SECTION("{256,256,0,0} -- 256+256=512")
    {
        std::vector<int> line = {256,256,0,0};
        auto slided = GameState::slideLine(line);
        REQUIRE(slided[0] == 512);
        REQUIRE(slided[1] == 0);
        REQUIRE(slided[2] == 0);
        REQUIRE(slided[3] == 0);
    }


}
