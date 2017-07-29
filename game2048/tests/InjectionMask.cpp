#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch/catch.hpp"
#include "catch/EqualsMat.hpp"

#include "game2048/InjectionMask.h"
#include "game2048/GameState.h"

using namespace solve2048::game2048;

TEST_CASE("GameState::emptyInjectionMask", "[GameState][emptyInjectionMask][InjectionMask]" ) 
{

    GameState gameState;
    InjectionMask mask = emptyInjectionMask(gameState);
    InjectionMask referenceMask = (InjectionMask(mask.rows,mask.cols) <<
                                0, 0, 0, 0,
                                0, 0, 0, 0,
                                0, 0, 0, 0,
                                0, 0, 0, 0
                                );
    REQUIRE_THAT(mask, EqualsMat(referenceMask));
}

TEST_CASE("directionalInjectionMask #1 Empty", "[GameState][Injection][directionalInjectionMask][InjectionMask]" ) 
{
    GameState gameState;
    gameState.state = (cv::Mat_<int>(gameState.state.rows,gameState.state.cols) <<
                                0, 0, 0, 0,
                                0, 0, 0, 0,
                                0, 0, 0, 0,
                                0, 0, 0, 0
                                );

    SECTION("Left")
    {
        InjectionMask referenceMask = (InjectionMask(gameState.state.rows,gameState.state.cols) <<
                                    1, 1, 1, 1,
                                    1, 1, 1, 1,
                                    1, 1, 1, 1,
                                    1, 1, 1, 1
                                    );

        InjectionMask mask = directionalInjectionMask(gameState,Left);

        REQUIRE_THAT(mask, EqualsMat(referenceMask));
    }

    SECTION("Right")
    {
        InjectionMask referenceMask = (InjectionMask(gameState.state.rows,gameState.state.cols) <<
                                    1, 1, 1, 1,
                                    1, 1, 1, 1,
                                    1, 1, 1, 1,
                                    1, 1, 1, 1
                                    );

        InjectionMask mask = directionalInjectionMask(gameState,Right);

        REQUIRE_THAT(mask, EqualsMat(referenceMask));
    }

    SECTION("Up")
    {
        InjectionMask referenceMask = (InjectionMask(gameState.state.rows,gameState.state.cols) <<
                                    1, 1, 1, 1,
                                    1, 1, 1, 1,
                                    1, 1, 1, 1,
                                    1, 1, 1, 1
                                    );

        InjectionMask mask = directionalInjectionMask(gameState,Up);

        REQUIRE_THAT(mask, EqualsMat(referenceMask));
    }

    SECTION("Down")
    {
        InjectionMask referenceMask = (InjectionMask(gameState.state.rows,gameState.state.cols) <<
                                    1, 1, 1, 1,
                                    1, 1, 1, 1,
                                    1, 1, 1, 1,
                                    1, 1, 1, 1
                                    );

        InjectionMask mask = directionalInjectionMask(gameState,Down);

        REQUIRE_THAT(mask, EqualsMat(referenceMask));
    }

}

TEST_CASE("directionalInjectionMask #2", "[GameState][Injection][directionalInjectionMask][InjectionMask]" ) 
{
    GameState gameState;
    gameState.state = (cv::Mat_<int>(gameState.state.rows,gameState.state.cols) <<
                                    0, 0, 0, 0,
                                    0, 1, 2, 0,
                                    0, 3, 4, 0,
                                    0, 0, 0, 0
                                );
    GameState nextGameState;
    GameState nextGameStateReference;

    SECTION("Left")
    {
        InjectionMask referenceMask = (InjectionMask(gameState.state.rows,gameState.state.cols) <<
                                    1, 1, 1, 1,
                                    0, 0, 0, 1,
                                    0, 0, 0, 1,
                                    1, 1, 1, 1
                                    );

        InjectionMask mask = directionalInjectionMask(gameState,Left);

        REQUIRE_THAT(mask, EqualsMat(referenceMask));
    }

    SECTION("Right")
    {
        InjectionMask referenceMask = (InjectionMask(gameState.state.rows,gameState.state.cols) <<
                                    1, 1, 1, 1,
                                    1, 0, 0, 0,
                                    1, 0, 0, 0,
                                    1, 1, 1, 1
                                    );

        InjectionMask mask = directionalInjectionMask(gameState,Right);

        REQUIRE_THAT(mask, EqualsMat(referenceMask));
    }

    SECTION("Up")
    {
        InjectionMask referenceMask = (InjectionMask(gameState.state.rows,gameState.state.cols) <<
                                    1, 0, 0, 1,
                                    1, 0, 0, 1,
                                    1, 0, 0, 1,
                                    1, 1, 1, 1
                                    );

        InjectionMask mask = directionalInjectionMask(gameState,Up);

        REQUIRE_THAT(mask, EqualsMat(referenceMask));
    }

    SECTION("Down")
    {
        InjectionMask referenceMask = (InjectionMask(gameState.state.rows,gameState.state.cols) <<
                                    1, 1, 1, 1,
                                    1, 0, 0, 1,
                                    1, 0, 0, 1,
                                    1, 0, 0, 1
                                    );

        InjectionMask mask = directionalInjectionMask(gameState,Down);

        REQUIRE_THAT(mask, EqualsMat(referenceMask));
    }

}

TEST_CASE("directionalInjectionMask #3", "[GameState][Injection][directionalInjectionMask][InjectionMask]" ) 
{
    GameState gameState;
    gameState.state = (cv::Mat_<int>(gameState.state.rows,gameState.state.cols) <<
                                    0, 0, 0, 8,
                                    0, 2, 2, 0,
                                    0, 2, 2, 0,
                                    0, 0, 0, 0
                                );
    GameState nextGameState;
    GameState nextGameStateReference;

    SECTION("Left")
    {
        InjectionMask referenceMask = (InjectionMask(gameState.state.rows,gameState.state.cols) <<
                                    0, 0, 0, 0,
                                    0, 0, 0, 1,
                                    0, 0, 0, 1,
                                    1, 1, 1, 1
                                    );

        InjectionMask mask = directionalInjectionMask(gameState,Left);

        REQUIRE_THAT(mask, EqualsMat(referenceMask));
    }

    SECTION("Right")
    {
        InjectionMask referenceMask = (InjectionMask(gameState.state.rows,gameState.state.cols) <<
                                    1, 1, 1, 0,
                                    1, 0, 0, 0,
                                    1, 0, 0, 0,
                                    1, 1, 1, 1
                                    );

        InjectionMask mask = directionalInjectionMask(gameState,Right);

        REQUIRE_THAT(mask, EqualsMat(referenceMask));
    }

    SECTION("Up")
    {
        InjectionMask referenceMask = (InjectionMask(gameState.state.rows,gameState.state.cols) <<
                                    1, 0, 0, 0,
                                    1, 0, 0, 1,
                                    1, 0, 0, 1,
                                    1, 1, 1, 1
                                    );

        InjectionMask mask = directionalInjectionMask(gameState,Up);

        REQUIRE_THAT(mask, EqualsMat(referenceMask));
    }

    SECTION("Down")
    {
        InjectionMask referenceMask = (InjectionMask(gameState.state.rows,gameState.state.cols) <<
                                    1, 1, 1, 0,
                                    1, 0, 0, 0,
                                    1, 0, 0, 0,
                                    1, 0, 0, 0
                                    );

        InjectionMask mask = directionalInjectionMask(gameState,Down);

        REQUIRE_THAT(mask, EqualsMat(referenceMask));
    }

}

TEST_CASE("directionalInjectionMask #4", "[GameState][Injection][directionalInjectionMask][InjectionMask]" ) 
{
    GameState gameState;
    gameState.state = (cv::Mat_<int>(gameState.state.rows,gameState.state.cols) <<
                                    2,  0, 0, 0,
                                    4,  2, 2, 0,
                                    8,  4, 4, 2,
                                    16, 8, 8, 8
                                );
    GameState nextGameState;
    GameState nextGameStateReference;

    SECTION("Left")
    {
        InjectionMask referenceMask = (InjectionMask(gameState.state.rows,gameState.state.cols) <<
                                    0, 1, 1, 1,
                                    0, 0, 0, 1,
                                    0, 0, 0, 0,
                                    0, 0, 0, 0
                                    );

        InjectionMask mask = directionalInjectionMask(gameState,Left);

        REQUIRE_THAT(mask, EqualsMat(referenceMask));
    }

    SECTION("Right")
    {
        InjectionMask referenceMask = (InjectionMask(gameState.state.rows,gameState.state.cols) <<
                                    0, 0, 0, 0,
                                    0, 0, 0, 0,
                                    0, 0, 0, 0,
                                    0, 0, 0, 0
                                    );

        InjectionMask mask = directionalInjectionMask(gameState,Right);

        REQUIRE_THAT(mask, EqualsMat(referenceMask));
    }

    SECTION("Up")
    {
        InjectionMask referenceMask = (InjectionMask(gameState.state.rows,gameState.state.cols) <<
                                    0, 0, 0, 0,
                                    0, 0, 0, 0,
                                    0, 0, 0, 0,
                                    0, 0, 0, 0
                                    );

        InjectionMask mask = directionalInjectionMask(gameState,Up);

        REQUIRE_THAT(mask, EqualsMat(referenceMask));
    }

    SECTION("Down")
    {
        InjectionMask referenceMask = (InjectionMask(gameState.state.rows,gameState.state.cols) <<
                                    0, 1, 1, 1,
                                    0, 0, 0, 1,
                                    0, 0, 0, 0,
                                    0, 0, 0, 0
                                    );

        InjectionMask mask = directionalInjectionMask(gameState,Down);

        REQUIRE_THAT(mask, EqualsMat(referenceMask));
    }

}

TEST_CASE("directionalInjectionMask #5", "[GameState][Injection][directionalInjectionMask][InjectionMask]" ) 
{
    GameState gameState;
    gameState.state = (cv::Mat_<int>(gameState.state.rows,gameState.state.cols) <<
                                    1,  2, 3, 4,
                                    5,  6, 7, 8,
                                    9,  10, 11, 12,
                                    13,  14, 15, 16
                                );
    GameState nextGameState;
    GameState nextGameStateReference;

    SECTION("Left")
    {
        InjectionMask referenceMask = (InjectionMask(gameState.state.rows,gameState.state.cols) <<
                                    0, 0, 0, 0,
                                    0, 0, 0, 0,
                                    0, 0, 0, 0,
                                    0, 0, 0, 0
                                    );

        InjectionMask mask = directionalInjectionMask(gameState,Left);

        REQUIRE_THAT(mask, EqualsMat(referenceMask));
    }

    SECTION("Right")
    {
        InjectionMask referenceMask = (InjectionMask(gameState.state.rows,gameState.state.cols) <<
                                    0, 0, 0, 0,
                                    0, 0, 0, 0,
                                    0, 0, 0, 0,
                                    0, 0, 0, 0
                                    );

        InjectionMask mask = directionalInjectionMask(gameState,Right);

        REQUIRE_THAT(mask, EqualsMat(referenceMask));
    }

    SECTION("Up")
    {
        InjectionMask referenceMask = (InjectionMask(gameState.state.rows,gameState.state.cols) <<
                                    0, 0, 0, 0,
                                    0, 0, 0, 0,
                                    0, 0, 0, 0,
                                    0, 0, 0, 0
                                    );

        InjectionMask mask = directionalInjectionMask(gameState,Up);

        REQUIRE_THAT(mask, EqualsMat(referenceMask));
    }

    SECTION("Down")
    {
        InjectionMask referenceMask = (InjectionMask(gameState.state.rows,gameState.state.cols) <<
                                    0, 0, 0, 0,
                                    0, 0, 0, 0,
                                    0, 0, 0, 0,
                                    0, 0, 0, 0
                                    );

        InjectionMask mask = directionalInjectionMask(gameState,Down);

        REQUIRE_THAT(mask, EqualsMat(referenceMask));
    }

}
