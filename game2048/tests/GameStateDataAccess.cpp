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
TEST_CASE("Set GameState Lines", "[GameState]" ) 
{
    GameState gameState;
    GameState gameStateReference;

    int k=1;
    for (int y=0; y<4; y++)
    {
        for (int x=0; x<4; x++)
        {
            gameStateReference.cell(x,y)=k;
            k++;
        }
    }

    SECTION("test setRow")
    {
        std::vector<int> row0 = {1  , 2  , 3  , 4};
        std::vector<int> row1 = {5  , 6  , 7  , 8};
        std::vector<int> row2 = {9  , 10 , 11 , 12};
        std::vector<int> row3 = {13 , 14 , 15 , 16};
        gameState.setRow(0,row0);
        gameState.setRow(1,row1);
        gameState.setRow(2,row2);
        gameState.setRow(3,row3);
        REQUIRE_THAT(gameState.state, EqualsMat(gameStateReference.state));
    }

    SECTION("test setCol")
    {
        std::vector<int> col0 = {1 , 5 , 9  , 13};
        std::vector<int> col1 = {2 , 6 , 10 , 14};
        std::vector<int> col2 = {3 , 7 , 11 , 15};
        std::vector<int> col3 = {4 , 8 , 12 , 16};
        gameState.setCol(0,col0);
        gameState.setCol(1,col1);
        gameState.setCol(2,col2);
        gameState.setCol(3,col3);
        REQUIRE_THAT(gameState.state, EqualsMat(gameStateReference.state));
    }
}
