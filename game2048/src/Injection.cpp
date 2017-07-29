
#include "game2048/GameState.h"
#include "game2048/Injection.h"

namespace solve2048
{
namespace game2048
{

    Injection::Injection()
        : x(0)
        , y(0)
        , value(0)
    {}
    Injection::Injection(int x, int y, CellValueType value)
        : x(x)
        , y(y)
        , value(value)
    {}


    std::shared_ptr<GameState> inject(const GameState& gameState, Injection injection)
    {
        std::shared_ptr<GameState> result;
        if (gameState.cell(injection.x, injection.y) == 0)
        {
            result.reset(new GameState(gameState));
            result->cell(injection.x, injection.y) = injection.value;
        }
        return result;
    }

    std::vector<Injection> listInjectionsFromMask(const InjectionMask& mask, CellValueType value)
    {
        std::vector<Injection> results;
        for (int x=0; x<mask.cols; x++)
        {
            for (int y=0; y<mask.rows; y++)
            {
                if (mask.at<int>(y,x) == 1)
                {
                    results.push_back(Injection(x,y,value));
                }
            }
        }
        return results;
    }


}
}
