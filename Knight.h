#ifndef CHESS_KNIGHT_H
#define CHESS_KNIGHT_H

#include "Chess.h"
class Knight :public Chess {
public:
  Knight(string name, Color color, ChessBoard* cb);
  bool isValidMove(Chess* board_[8][8],int from_rank, int from_file, int to_rank, int to_file) override ;
  ~Knight() override{};
};

#endif //CHESS_KNIGHT_H
