#pragma once

#include <opencv2/opencv.hpp>
#include <vector>

namespace solve2048
{
namespace game2048
{

class GameState
{
public:
    GameState();
    ~GameState();
    int& cell(int x, int y);
    void rotateClockwise();
    void rotateCounterClockwise();
    cv::Mat_<int> state;

    std::vector<int> row(int x);
    std::vector<int> col(int y);

    static std::vector<int> slideLine(std::vector<int> line);
};

}
}
