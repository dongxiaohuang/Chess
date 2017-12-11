#ifndef CHESS_KING_H
#define CHESS_KING_H
#include "Chess.h"

class King : public Chess{
public:
  King(string name, Color color, ChessBoard* cb);
  bool isValidMove(Chess* board_[8][8],int from_rank, int from_file, int to_rank, int to_file) override ;
  ~King() override {};
};


#endif //CHESS_KING_H
