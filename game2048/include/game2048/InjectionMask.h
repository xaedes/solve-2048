#pragma once

#include <opencv2/opencv.hpp>
#include <vector>
#include <memory>

#include "game2048/Direction.h"
#include "game2048/GameState.h"

namespace solve2048
{
namespace game2048
{

    typedef cv::Mat_<int> InjectionMask;

    InjectionMask emptyInjectionMask(const GameState& gameState);
    InjectionMask directionalInjectionMask(const GameState& gameState, Direction direction);

}
}
