#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch/catch.hpp"
#include "catch/EqualsMat.hpp"

#include "game2048/GameState.h"

using namespace solve2048::game2048;


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

