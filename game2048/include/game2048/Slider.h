#pragma once

#include "game2048/GameState.h"
#include <vector>

namespace solve2048
{
namespace game2048
{
namespace slider
{

std::vector<CellValueType> slideLine(const std::vector<CellValueType>& line);

GameState slideLeft(const GameState& origin);
GameState slideRight(const GameState& origin);
GameState slideUp(const GameState& origin);
GameState slideDown(const GameState& origin);

}
}
}
