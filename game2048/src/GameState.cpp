
#include <opencv2/opencv.hpp>
#include <vector>

#include "game2048/GameState.h"

using namespace solve2048::game2048;

solve2048::game2048::GameState::GameState()
    : state(cv::Mat_<int>::zeros(4,4))
{

}

solve2048::game2048::GameState::~GameState()
{}

int& solve2048::game2048::GameState::cell(int x, int y)
{
    return state.at<int>(y,x);
}

void solve2048::game2048::GameState::rotateClockwise()
{
    // https://stackoverflow.com/a/23990392/798588
    // transpose+flip(1)=CW
    cv::transpose(state, state);
    cv::flip(state, state, 1);

}

void solve2048::game2048::GameState::rotateCounterClockwise()
{
    // https://stackoverflow.com/a/23990392/798588
    // transpose+flip(0)=CCW 
    cv::transpose(state, state);
    cv::flip(state, state, 0);
}

std::vector<int> solve2048::game2048::GameState::row(int y) const
{
    return (std::vector<int>)state.row(y);
}

std::vector<int> solve2048::game2048::GameState::col(int x) const
{
    return (std::vector<int>)state.col(x);
}

void solve2048::game2048::GameState::setRow(int y, std::vector<int> rowVector)
{
    for(int x=0; x<rowVector.size(); x++)
    {
        cell(x,y) = rowVector[x];
    }
}

void solve2048::game2048::GameState::setCol(int x, std::vector<int> colVector)
{
    for(int y=0; y<colVector.size(); y++)
    {
        cell(x,y) = colVector[y];
    }
}


std::vector<int> solve2048::game2048::GameState::slideLine(std::vector<int> line)
{
    std::vector<int> result = {0,0,0,0};

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

solve2048::game2048::GameState solve2048::game2048::GameState::slideLeft() const
{
    GameState slided;
    for (int y=0; y<state.rows; y++)
    {
        slided.setRow(y,slideLine(slided.row(y)));
    }
    return slided;
}

solve2048::game2048::GameState solve2048::game2048::GameState::slideRight() const
{
    GameState rotated(*this);
    rotated.rotateClockwise();
    rotated.rotateClockwise();

    GameState slided = rotated.slideLeft();
    
    slided.rotateCounterClockwise();
    slided.rotateCounterClockwise();
    return slided;
}

solve2048::game2048::GameState solve2048::game2048::GameState::slideUp() const
{
    GameState rotated(*this);
    rotated.rotateCounterClockwise();

    GameState slided = rotated.slideLeft();
    
    slided.rotateClockwise();
    return slided;
}

solve2048::game2048::GameState solve2048::game2048::GameState::slideDown() const
{
    GameState rotated(*this);
    rotated.rotateClockwise();

    GameState slided = rotated.slideLeft();
    
    slided.rotateCounterClockwise();
    return slided;
}
