#include "Queen.h"
#include "Rook.h"
#include "Bishop.h"
Queen::Queen(string name, Color color, ChessBoard* cb):Chess(name,color,cb){}
bool Queen::isValidMove(Chess* board_[8][8],int from_rank, int from_file, int to_rank, int to_file)
{
  // is this efficient
  bool isValid;
  if(to_rank == from_rank || to_file == from_file)
  {
    Rook rk(getName(),getColor(),chess_board_);
    isValid = rk.isValidMove(board_,from_rank, from_file, to_rank, to_file);
  }else
  {
    Bishop bs(getName(),getColor(),chess_board_);
    isValid = bs.isValidMove(board_,from_rank, from_file, to_rank, to_file);
  }
  return isValid;
}
