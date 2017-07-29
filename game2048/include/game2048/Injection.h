#pragma once

#include <opencv2/opencv.hpp>
#include <vector>
#include <memory>

#include "game2048/Cell.h"
#include "game2048/Direction.h"
#include "game2048/GameState.h"
#include "game2048/InjectionMask.h"

namespace solve2048
{
namespace game2048
{

    struct Injection
    {
        Injection();
        Injection(int x, int y, CellValueType value);
        int x;
        int y;
        CellValueType value;
    };

    typedef cv::Mat_<int> InjectionMask;


    std::vector<Injection> listInjectionsFromMask(const InjectionMask& mask, CellValueType value);
    std::shared_ptr<GameState> inject(const GameState& gameState, Injection injection);

    // std::shared_ptr<Injection>
    // GameState injectInLeftDirection() const;
    // GameState injectInRightDirection() const;
    // GameState injectInUpDirection() const;
    // GameState injectInDownDirection() const;

}
}
