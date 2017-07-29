
#include <opencv2/opencv.hpp>
#include <vector>

#include "game2048/GameState.h"

using namespace solve2048::game2048;

namespace solve2048{
namespace game2048{



    GameState::GameState()
        : state(cv::Mat_<CellValueType>::zeros(4,4))
    {

    }

    GameState::~GameState()
    {}

    CellValueType& GameState::cell(int x, int y)
    {
        return state.at<CellValueType>(y,x);
    }

    const CellValueType& GameState::cell(int x, int y) const
    {
        return state.at<CellValueType>(y,x);
    }

    void GameState::rotateClockwise()
    {
        // https://stackoverflow.com/a/23990392/798588
        // transpose+flip(1)=CW
        cv::transpose(state, state);
        cv::flip(state, state, 1);

    }

    void GameState::rotateCounterClockwise()
    {
        // https://stackoverflow.com/a/23990392/798588
        // transpose+flip(0)=CCW 
        cv::transpose(state, state);
        cv::flip(state, state, 0);
    }

    std::vector<CellValueType> GameState::row(int y) const
    {
        return (std::vector<CellValueType>)state.row(y);
    }

    std::vector<CellValueType> GameState::col(int x) const
    {
        return (std::vector<CellValueType>)state.col(x);
    }

    void GameState::setRow(int y, std::vector<CellValueType> rowVector)
    {
        for(int x=0; x<rowVector.size(); x++)
        {
            cell(x,y) = rowVector[x];
        }
    }

    void GameState::setCol(int x, std::vector<CellValueType> colVector)
    {
        for(int y=0; y<colVector.size(); y++)
        {
            cell(x,y) = colVector[y];
        }
    }


}
}
