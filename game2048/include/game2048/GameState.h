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

    std::vector<int> row(int y) const;
    std::vector<int> col(int x) const;

    void setRow(int y, std::vector<int> rowVector);
    void setCol(int x, std::vector<int> colVector);

    static std::vector<int> slideLine(std::vector<int> line);

    GameState slideLeft() const;
    GameState slideRight() const;
    GameState slideUp() const;
    GameState slideDown() const;
};

}
}
