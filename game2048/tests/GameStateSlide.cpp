#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch/catch.hpp"
#include "catch/EqualsMat.hpp"

#include "game2048/GameState.h"

using namespace solve2048::game2048;

TEST_CASE("GameState Slide #1 Empty", "[GameState][slideLeft][slideRight][slideUp][slideDown]" ) 
{
    GameState gameState;
    gameState.state = (cv::Mat_<int>(gameState.state.rows,gameState.state.cols) <<
                                0, 0, 0, 0,
                                0, 0, 0, 0,
                                0, 0, 0, 0,
                                0, 0, 0, 0
                                );
    GameState nextGameState;
    GameState nextGameStateReference;

    SECTION("slideLeft")
    {
        nextGameStateReference.state = (cv::Mat_<int>(nextGameStateReference.state.rows,nextGameStateReference.state.cols) <<
                                    0, 0, 0, 0,
                                    0, 0, 0, 0,
                                    0, 0, 0, 0,
                                    0, 0, 0, 0
                                    );

        nextGameState = gameState.slideLeft();

        REQUIRE_THAT(nextGameState.state, EqualsMat(nextGameStateReference.state));
    }

    SECTION("slideRight")
    {
        nextGameStateReference.state = (cv::Mat_<int>(nextGameStateReference.state.rows,nextGameStateReference.state.cols) <<
                                    0, 0, 0, 0,
                                    0, 0, 0, 0,
                                    0, 0, 0, 0,
                                    0, 0, 0, 0
                                    );

        nextGameState = gameState.slideRight();

        REQUIRE_THAT(nextGameState.state, EqualsMat(nextGameStateReference.state));
    }

    SECTION("slideUp")
    {
        nextGameStateReference.state = (cv::Mat_<int>(nextGameStateReference.state.rows,nextGameStateReference.state.cols) <<
                                    0, 0, 0, 0,
                                    0, 0, 0, 0,
                                    0, 0, 0, 0,
                                    0, 0, 0, 0
                                    );

        nextGameState = gameState.slideUp();

        REQUIRE_THAT(nextGameState.state, EqualsMat(nextGameStateReference.state));
    }

    SECTION("slideDown")
    {
        nextGameStateReference.state = (cv::Mat_<int>(nextGameStateReference.state.rows,nextGameStateReference.state.cols) <<
                                    0, 0, 0, 0,
                                    0, 0, 0, 0,
                                    0, 0, 0, 0,
                                    0, 0, 0, 0
                                    );

        nextGameState = gameState.slideDown();

        REQUIRE_THAT(nextGameState.state, EqualsMat(nextGameStateReference.state));
    }

}

TEST_CASE("GameState Slide #2", "[GameState][slideLeft][slideRight][slideUp][slideDown]" ) 
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

    SECTION("slideLeft")
    {
        nextGameStateReference.state = (cv::Mat_<int>(nextGameStateReference.state.rows,nextGameStateReference.state.cols) <<
                                    0, 0, 0, 0,
                                    1, 2, 0, 0,
                                    3, 4, 0, 0,
                                    0, 0, 0, 0
                                    );

        nextGameState = gameState.slideLeft();

        REQUIRE_THAT(nextGameState.state, EqualsMat(nextGameStateReference.state));
    }

    SECTION("slideRight")
    {
        nextGameStateReference.state = (cv::Mat_<int>(nextGameStateReference.state.rows,nextGameStateReference.state.cols) <<
                                    0, 0, 0, 0,
                                    0, 0, 1, 2,
                                    0, 0, 3, 4,
                                    0, 0, 0, 0
                                    );

        nextGameState = gameState.slideRight();

        REQUIRE_THAT(nextGameState.state, EqualsMat(nextGameStateReference.state));
    }

    SECTION("slideUp")
    {
        nextGameStateReference.state = (cv::Mat_<int>(nextGameStateReference.state.rows,nextGameStateReference.state.cols) <<
                                    0, 1, 2, 0,
                                    0, 3, 4, 0,
                                    0, 0, 0, 0,
                                    0, 0, 0, 0
                                    );

        nextGameState = gameState.slideUp();

        REQUIRE_THAT(nextGameState.state, EqualsMat(nextGameStateReference.state));
    }

    SECTION("slideDown")
    {
        nextGameStateReference.state = (cv::Mat_<int>(nextGameStateReference.state.rows,nextGameStateReference.state.cols) <<
                                    0, 0, 0, 0,
                                    0, 0, 0, 0,
                                    0, 1, 2, 0,
                                    0, 3, 4, 0
                                    );

        nextGameState = gameState.slideDown();

        REQUIRE_THAT(nextGameState.state, EqualsMat(nextGameStateReference.state));
    }

}

TEST_CASE("GameState Slide #3", "[GameState][slideLeft][slideRight][slideUp][slideDown]" ) 
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

    SECTION("slideLeft")
    {
        nextGameStateReference.state = (cv::Mat_<int>(nextGameStateReference.state.rows,nextGameStateReference.state.cols) <<
                                    8, 0, 0, 0,
                                    4, 0, 0, 0,
                                    4, 0, 0, 0,
                                    0, 0, 0, 0
                                    );

        nextGameState = gameState.slideLeft();

        REQUIRE_THAT(nextGameState.state, EqualsMat(nextGameStateReference.state));
    }

    SECTION("slideRight")
    {
        nextGameStateReference.state = (cv::Mat_<int>(nextGameStateReference.state.rows,nextGameStateReference.state.cols) <<
                                    0, 0, 0, 8,
                                    0, 0, 0, 4,
                                    0, 0, 0, 4,
                                    0, 0, 0, 0
                                    );

        nextGameState = gameState.slideRight();

        REQUIRE_THAT(nextGameState.state, EqualsMat(nextGameStateReference.state));
    }

    SECTION("slideUp")
    {
        nextGameStateReference.state = (cv::Mat_<int>(nextGameStateReference.state.rows,nextGameStateReference.state.cols) <<
                                    0, 4, 4, 8,
                                    0, 0, 0, 0,
                                    0, 0, 0, 0,
                                    0, 0, 0, 0
                                    );

        nextGameState = gameState.slideUp();

        REQUIRE_THAT(nextGameState.state, EqualsMat(nextGameStateReference.state));
    }

    SECTION("slideDown")
    {
        nextGameStateReference.state = (cv::Mat_<int>(nextGameStateReference.state.rows,nextGameStateReference.state.cols) <<
                                    0, 0, 0, 8,
                                    0, 0, 0, 0,
                                    0, 0, 0, 0,
                                    0, 4, 4, 8
                                    );

        nextGameState = gameState.slideDown();

        REQUIRE_THAT(nextGameState.state, EqualsMat(nextGameStateReference.state));
    }

}

TEST_CASE("GameState Slide #4", "[GameState][slideLeft][slideRight][slideUp][slideDown]" ) 
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

    SECTION("slideLeft")
    {
        nextGameStateReference.state = (cv::Mat_<int>(nextGameStateReference.state.rows,nextGameStateReference.state.cols) <<
                                    2,   0, 0, 0,
                                    4,   4, 0, 0,
                                    8,   8, 2, 0,
                                    16, 16, 8, 0
                                    );

        nextGameState = gameState.slideLeft();

        REQUIRE_THAT(nextGameState.state, EqualsMat(nextGameStateReference.state));
    }

    SECTION("slideRight")
    {
        nextGameStateReference.state = (cv::Mat_<int>(nextGameStateReference.state.rows,nextGameStateReference.state.cols) <<
                                    0,  0, 0,  2,
                                    0,  0, 4,  4,
                                    0,  8, 8,  2,
                                    0, 16, 8, 16
                                    );

        nextGameState = gameState.slideRight();

        REQUIRE_THAT(nextGameState.state, EqualsMat(nextGameStateReference.state));
    }

    SECTION("slideUp")
    {
        nextGameStateReference.state = (cv::Mat_<int>(nextGameStateReference.state.rows,nextGameStateReference.state.cols) <<
                                    2,  2, 2, 2,
                                    4,  4, 4, 8,
                                    8,  8, 8, 0,
                                    16, 0, 0, 0
                                    );

        nextGameState = gameState.slideUp();

        REQUIRE_THAT(nextGameState.state, EqualsMat(nextGameStateReference.state));
    }

    SECTION("slideDown")
    {
        nextGameStateReference.state = (cv::Mat_<int>(nextGameStateReference.state.rows,nextGameStateReference.state.cols) <<
                                    2,  0, 0, 0,
                                    4,  2, 2, 0,
                                    8,  4, 4, 2,
                                    16, 8, 8, 8
                                    );

        nextGameState = gameState.slideDown();

        REQUIRE_THAT(nextGameState.state, EqualsMat(nextGameStateReference.state));
    }

}

TEST_CASE("GameState Slide #5", "[GameState][slideLeft][slideRight][slideUp][slideDown]" ) 
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

    SECTION("slideLeft")
    {
        nextGameStateReference.state = (cv::Mat_<int>(nextGameStateReference.state.rows,nextGameStateReference.state.cols) <<
                                    1,  2, 3, 4,
                                    5,  6, 7, 8,
                                    9,  10, 11, 12,
                                    13,  14, 15, 16
                                    );

        nextGameState = gameState.slideLeft();

        REQUIRE_THAT(nextGameState.state, EqualsMat(nextGameStateReference.state));
    }

    SECTION("slideRight")
    {
        nextGameStateReference.state = (cv::Mat_<int>(nextGameStateReference.state.rows,nextGameStateReference.state.cols) <<
                                    1,  2, 3, 4,
                                    5,  6, 7, 8,
                                    9,  10, 11, 12,
                                    13,  14, 15, 16
                                    );

        nextGameState = gameState.slideRight();

        REQUIRE_THAT(nextGameState.state, EqualsMat(nextGameStateReference.state));
    }

    SECTION("slideUp")
    {
        nextGameStateReference.state = (cv::Mat_<int>(nextGameStateReference.state.rows,nextGameStateReference.state.cols) <<
                                    1,  2, 3, 4,
                                    5,  6, 7, 8,
                                    9,  10, 11, 12,
                                    13,  14, 15, 16
                                    );

        nextGameState = gameState.slideUp();

        REQUIRE_THAT(nextGameState.state, EqualsMat(nextGameStateReference.state));
    }

    SECTION("slideDown")
    {
        nextGameStateReference.state = (cv::Mat_<int>(nextGameStateReference.state.rows,nextGameStateReference.state.cols) <<
                                    1,  2, 3, 4,
                                    5,  6, 7, 8,
                                    9,  10, 11, 12,
                                    13,  14, 15, 16
                                    );

        nextGameState = gameState.slideDown();

        REQUIRE_THAT(nextGameState.state, EqualsMat(nextGameStateReference.state));
    }

}
