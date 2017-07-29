#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch/catch.hpp"
#include "catch/EqualsMat.hpp"

#include "game2048/Injection.h"
#include "game2048/GameState.h"

using namespace solve2048::game2048;

TEST_CASE("Injection construction", "[Injection]" ) 
{
    SECTION("default constructor")
    {
        Injection injection;
        REQUIRE(injection.x == 0);
        REQUIRE(injection.y == 0);
        REQUIRE(injection.value == 0);
    }
    SECTION("value initialization constructor")
    {
        Injection injection(1,2,3);
        REQUIRE(injection.x == 1);
        REQUIRE(injection.y == 2);
        REQUIRE(injection.value == 3);
    }
    SECTION("copy constructor")
    {
        Injection injection(1,2,3);
        Injection injectionCopy(injection);
        REQUIRE(injectionCopy.x == injection.x);
        REQUIRE(injectionCopy.y == injection.y);
        REQUIRE(injectionCopy.value == injection.value);
    }
    SECTION("copy by assignment in decleration")
    {
        Injection injection(1,2,3);
        Injection injectionCopy = injection;
        REQUIRE(injectionCopy.x == injection.x);
        REQUIRE(injectionCopy.y == injection.y);
        REQUIRE(injectionCopy.value == injection.value);
    }
    SECTION("copy by assignment")
    {
        Injection injection(1,2,3);
        Injection injectionCopy;
        injectionCopy = injection;
        REQUIRE(injectionCopy.x == injection.x);
        REQUIRE(injectionCopy.y == injection.y);
        REQUIRE(injectionCopy.value == injection.value);
    }
}
TEST_CASE("Starting with an empty GameState", "[GameState][Injection]" ) 
{
    GameState gameState;

    SECTION("Inject at empty position (0,0)")
    {
        Injection injection(0,0,2);

        REQUIRE(gameState.cell(injection.x,injection.y) == 0);
        std::shared_ptr<GameState> injected = inject(gameState, injection);
        REQUIRE(injected.get() != NULL);
        REQUIRE(injected->cell(injection.x,injection.y) == injection.value);
    }
    SECTION("Inject at empty position (0,2)")
    {
        Injection injection(0,2,4);

        REQUIRE(gameState.cell(injection.x,injection.y) == 0);
        std::shared_ptr<GameState> injected = inject(gameState, injection);
        REQUIRE(injected.get() != NULL);
        REQUIRE(injected->cell(injection.x,injection.y) == injection.value);
    }
    SECTION("Inject at empty position (2,0)")
    {
        Injection injection(2,0,8);

        REQUIRE(gameState.cell(injection.x,injection.y) == 0);
        std::shared_ptr<GameState> injected = inject(gameState, injection);
        REQUIRE(injected.get() != NULL);
        REQUIRE(injected->cell(injection.x,injection.y) == injection.value);
    }

    SECTION("Inject at empty position (2,2)")
    {
        Injection injection(2,2,8);

        REQUIRE(gameState.cell(injection.x,injection.y) == 0);
        std::shared_ptr<GameState> injected = inject(gameState, injection);
        REQUIRE(injected.get() != NULL);
        REQUIRE(injected->cell(injection.x,injection.y) == injection.value);
    }

    SECTION("Inject at not empty position (0,0)")
    {
        Injection injection(0,0,4);
        gameState.cell(injection.x,injection.y) = 2;

        REQUIRE(gameState.cell(injection.x,injection.y) != 0);
        std::shared_ptr<GameState> injected = inject(gameState, injection);
        REQUIRE(injected.get() == NULL);
    }

    SECTION("Inject at not empty position (0,2)")
    {
        Injection injection(0,2,4);
        gameState.cell(injection.x,injection.y) = 2;

        REQUIRE(gameState.cell(injection.x,injection.y) != 0);
        std::shared_ptr<GameState> injected = inject(gameState, injection);
        REQUIRE(injected.get() == NULL);
    }

    SECTION("Inject at not empty position (2,0)")
    {
        Injection injection(2,0,4);
        gameState.cell(injection.x,injection.y) = 2;

        REQUIRE(gameState.cell(injection.x,injection.y) != 0);
        std::shared_ptr<GameState> injected = inject(gameState, injection);
        REQUIRE(injected.get() == NULL);
    }

    SECTION("Inject at not empty position (2,2)")
    {
        Injection injection(2,2,4);
        gameState.cell(injection.x,injection.y) = 2;

        REQUIRE(gameState.cell(injection.x,injection.y) != 0);
        std::shared_ptr<GameState> injected = inject(gameState, injection);
        REQUIRE(injected.get() == NULL);
    }

    SECTION("Inject empty at not empty position (0,0) does not work")
    {
        Injection injection(0,0,0);
        gameState.cell(injection.x,injection.y) = 2;

        REQUIRE(gameState.cell(injection.x,injection.y) != 0);
        std::shared_ptr<GameState> injected = inject(gameState, injection);
        REQUIRE(injected.get() == NULL);
    }

    SECTION("Inject empty at not empty position (2,0) does not work")
    {
        Injection injection(2,0,0);
        gameState.cell(injection.x,injection.y) = 2;

        REQUIRE(gameState.cell(injection.x,injection.y) != 0);
        std::shared_ptr<GameState> injected = inject(gameState, injection);
        REQUIRE(injected.get() == NULL);
    }

    SECTION("Inject empty at empty position (0,0) does not change a thing")
    {
        Injection injection(0,0,0);

        REQUIRE(gameState.cell(injection.x,injection.y) == 0);
        std::shared_ptr<GameState> injected = inject(gameState, injection);
        REQUIRE(injected.get() != NULL);
        REQUIRE(injected->cell(injection.x,injection.y) == gameState.cell(injection.x,injection.y));
    }

    SECTION("Inject empty at empty position (2,0) does not change a thing")
    {
        Injection injection(2,0,0);

        REQUIRE(gameState.cell(injection.x,injection.y) == 0);
        std::shared_ptr<GameState> injected = inject(gameState, injection);
        REQUIRE(injected.get() != NULL);
        REQUIRE(injected->cell(injection.x,injection.y) == gameState.cell(injection.x,injection.y));
    }
}
TEST_CASE("listInjectionsFromMask", "[GameState][Injection][InjectionMask][listInjectionsFromMask]" ) 
{
    CellValueType injectionValue = 2;
    GameState gameState;
    SECTION("Empty mask")
    {
        InjectionMask mask = (InjectionMask(gameState.state.rows,gameState.state.cols) <<
                                    0, 0, 0, 0,
                                    0, 0, 0, 0,
                                    0, 0, 0, 0,
                                    0, 0, 0, 0
                                    );

        std::vector<Injection> list = listInjectionsFromMask( mask, injectionValue);
        REQUIRE(list.size() == 0);
    }
    SECTION("Full mask")
    {
        InjectionMask mask = (InjectionMask(gameState.state.rows,gameState.state.cols) <<
                                    1, 1, 1, 1,
                                    1, 1, 1, 1,
                                    1, 1, 1, 1,
                                    1, 1, 1, 1
                                    );
        cv::Mat_<int> occurences = cv::Mat_<int>::zeros(gameState.state.rows,gameState.state.cols);
        std::vector<Injection> list = listInjectionsFromMask( mask, injectionValue);
        for (Injection injection : list)
        {
            occurences.at<int>(injection.y,injection.x) += 1;
            REQUIRE(injection.value == injectionValue);
        }
        REQUIRE_THAT(occurences, EqualsMat(mask));
    }
    SECTION("mask #1")
    {
        InjectionMask mask = (InjectionMask(gameState.state.rows,gameState.state.cols) <<
                                    1, 1, 1, 1,
                                    0, 0, 0, 1,
                                    1, 1, 1, 1,
                                    1, 1, 1, 1
                                    );
        cv::Mat_<int> occurences = cv::Mat_<int>::zeros(gameState.state.rows,gameState.state.cols);
        std::vector<Injection> list = listInjectionsFromMask( mask, injectionValue);
        for (Injection injection : list)
        {
            occurences.at<int>(injection.y,injection.x) += 1;
            REQUIRE(injection.value == injectionValue);
        }
        REQUIRE_THAT(occurences, EqualsMat(mask));
    }
    SECTION("mask #2")
    {
        InjectionMask mask = (InjectionMask(gameState.state.rows,gameState.state.cols) <<
                                    1, 1, 1, 0,
                                    0, 0, 0, 1,
                                    1, 0, 0, 0,
                                    0, 1, 1, 1
                                    );
        cv::Mat_<int> occurences = cv::Mat_<int>::zeros(gameState.state.rows,gameState.state.cols);
        std::vector<Injection> list = listInjectionsFromMask( mask, injectionValue);
        for (Injection injection : list)
        {
            occurences.at<int>(injection.y,injection.x) += 1;
            REQUIRE(injection.value == injectionValue);
        }
        REQUIRE_THAT(occurences, EqualsMat(mask));
    }

}
