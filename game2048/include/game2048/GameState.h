#pragma once

#include <opencv2/opencv.hpp>
#include <vector>
#include <memory>

#include "game2048/Cell.h"

namespace solve2048
{
namespace game2048
{

class GameState
{
public:
    GameState();
    ~GameState();
    const CellValueType& cell(int x, int y) const;
    CellValueType& cell(int x, int y);
    void rotateClockwise();
    void rotateCounterClockwise();
    cv::Mat_<CellValueType> state;

    std::vector<CellValueType> row(int y) const;
    std::vector<CellValueType> col(int x) const;

    void setRow(int y, std::vector<CellValueType> rowVector);
    void setCol(int x, std::vector<CellValueType> colVector);

};

}
}
