#ifndef ROOK_H
#define ROOK_H
#include "Chess.h"

class Rook :public Chess{
public:
  Rook(string name, Color color, ChessBoard* cb);
  bool isValidMove(Chess* board_[8][8],int from_rank, int from_file, int to_rank, int to_file) override;
  ~Rook() override{};
};


#endif //CHESS_ROOK_H
