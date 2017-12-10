//
// Created by Dongxiao Huang on 05/12/2017.
//

#ifndef CHESS_CHESS_H
#define CHESS_CHESS_H

#include "ChessBoard.h"
#include "helper.h"
#include <iostream>
#include <string>
using namespace std;
class ChessBoard;
class Chess {
protected:
    string name_;
    Color color_;
    ChessBoard* chess_board_;
public:
    Chess(string name, Color color, ChessBoard* cb);
    virtual bool isValidMove(Chess* board_[8][8],int from_rank, int from_file, int to_rank, int to_file) = 0;
    Color getColor();
    string getName();
    virtual ~Chess(){};
    bool isKillable(Chess* board_[8][8],int to_rank, int to_file);
    bool checkFourDirection(int from_rank, int from_file, int to_rank, int to_file, int rank_step_abs, int file_step_abs);
};

#endif //CHESS_CHESS_H
