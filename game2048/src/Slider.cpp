
#include "game2048/Slider.h"
#include "game2048/GameState.h"

using namespace solve2048::game2048;

namespace solve2048
{
namespace game2048
{
namespace slider
{

std::vector<CellValueType> slideLine(const std::vector<CellValueType>& line)
{
    std::vector<CellValueType> result = {0,0,0,0};

    int input = 0;
    int output = 0;
    while(output<result.size() && input<line.size())
    {
        // find not empty input
        if (line[input] != 0)
        {
            // find mergeable pair
            if (input < line.size()-1 && line[input] == line[input+1])
            {
                // a mergeable pair is found
                result[output] = 2 * line[input];
                input+=2;
                output+=1;
            }
            else
            {
                // current item is not mergeable
                result[output] = line[input];
                input+=1;
                output+=1;
            }
        }
        else
        {
            // skip empty input
            while (input < line.size() && line[input] == 0) ++input;
            if (input == line.size())
            {
                // rest of line is empty
                return result;
            }
        }
    }

    return result;
}

GameState slideLeft(const GameState& origin)
{
    GameState slided(origin);
    for (int y=0; y<slided.state.rows; y++)
    {
        slided.setRow(y,slideLine(slided.row(y)));
    }
    return slided;
}
GameState slideRight(const GameState& origin)
{
    GameState rotated(origin);
    rotated.rotateClockwise();
    rotated.rotateClockwise();

    GameState slided = slideLeft(rotated);
    
    slided.rotateCounterClockwise();
    slided.rotateCounterClockwise();
    return slided;
}
GameState slideUp(const GameState& origin)
{
    GameState rotated(origin);
    rotated.rotateCounterClockwise();

    GameState slided = slideLeft(rotated);
    
    slided.rotateClockwise();
    return slided;
}
GameState slideDown(const GameState& origin)
{
    GameState rotated(origin);
    rotated.rotateClockwise();

    GameState slided = slideLeft(rotated);
    
    slided.rotateCounterClockwise();
    return slided;
}

}
}
}
