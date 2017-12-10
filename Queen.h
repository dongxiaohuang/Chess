//
// Created by Dongxiao Huang on 04/12/2017.
//

#ifndef CHESS_QUEEN_H
#define CHESS_QUEEN_H

#include "Chess.h"
class Queen :public Chess {
public:
  Queen(string name, Color color, ChessBoard* cb);
  bool isValidMove(Chess* board_[8][8],int from_rank, int from_file, int to_rank, int to_file) override ;
  ~Queen() override{};
};


#endif //CHESS_QUEEN_H
