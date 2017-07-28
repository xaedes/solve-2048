
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

std::vector<int> solve2048::game2048::GameState::row(int x)
{
    return (std::vector<int>)state.row(x);
}

std::vector<int> solve2048::game2048::GameState::col(int y)
{
    return (std::vector<int>)state.col(y);
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
