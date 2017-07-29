
#include "game2048/GameState.h"
#include "game2048/InjectionMask.h"

namespace solve2048
{
namespace game2048
{

    InjectionMask emptyInjectionMask(const GameState& gameState)
    {
        return InjectionMask::zeros(gameState.state.rows, gameState.state.cols);
    }

    InjectionMask directionalInjectionMask(const GameState& gameState, Direction direction)
    {
        InjectionMask mask = emptyInjectionMask(gameState);
        switch(direction)
        {
        case Left:
            // all rows
            for (int y=0; y<mask.rows; y++)
            {
                // inject from end of row
                for (int x=mask.cols-1; x>=0; x--)
                {
                    if (gameState.cell(x,y) == 0)
                    {
                        mask.at<int>(y,x) = 1;
                    }
                    else
                    {
                        break;
                    }
                }
            }
            break;

        case Right:
            // all rows
            for (int y=0; y<mask.rows; y++)
            {
                // inject from start of row
                for (int x=0; x<mask.cols; x++)
                {
                    if (gameState.cell(x,y) == 0)
                    {
                        mask.at<int>(y,x) = 1;
                    }
                    else
                    {
                        break;
                    }
                }
            }
            break;

        case Up:
            // all columns
            for (int x=0; x<mask.cols; x++)
            {
                // inject from end of column
                for (int y=mask.rows-1; y>=0; y--)
                {
                    if (gameState.cell(x,y) == 0)
                    {
                        mask.at<int>(y,x) = 1;
                    }
                    else
                    {
                        break;
                    }
                }
            }
            break;

        case Down:
            // all columns
            for (int x=0; x<mask.cols; x++)
            {
                // inject from start of column
                for (int y=0; y<mask.rows; y++)
                {
                    if (gameState.cell(x,y) == 0)
                    {
                        mask.at<int>(y,x) = 1;
                    }
                    else
                    {
                        break;
                    }
                }
            }
            break;

        }
        return mask;
    }

}
}
