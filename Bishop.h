#ifndef CHESS_BISHOP_H
#define CHESS_BISHOP_H
#include "Chess.h"

class Bishop :public Chess{
public:
  Bishop(string name, Color color, ChessBoard* cb);
  bool isValidMove(Chess* board_[8][8],int from_rank, int from_file, int to_rank, int to_file) override;
  ~Bishop() override{};
};


#endif //CHESS_BISHOP_H
