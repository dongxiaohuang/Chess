#include "Pawn.h"

Pawn::Pawn(string name,Color color, ChessBoard* cb): Chess(name,color,cb){}
bool Pawn::isValidMove(Chess* board_[8][8],int from_rank, int from_file, int to_rank, int to_file)
{
  int rank_step = to_rank - from_rank;
  int file_step = to_file - from_file;
  // check destination and try to capture
  if(chess_board_->isOccupied(board_,to_rank, to_file))
  {
    if(isKillable(board_,to_rank, to_file))
    {
      // white or black pawn moves
      if((color_ == WHITE && rank_step == 1) ||(color_ == BLACK && rank_step == -1))
      {
        if(file_step == 1 || file_step == -1)
          return true;
      }
    }
    return false;
  }
  // if not to capture, then pawn can only step forward vertically
  if(file_step != 0)
    return false;
  // check if it is the first step
  if(color_ == WHITE && from_rank == 1)// White pawn initial position
  {
    if(rank_step == 1 || rank_step == 2)
      return true;
  }
  if(color_ == BLACK && from_rank == 6)// black pawn initial position
  {
    if(rank_step == -1 || rank_step == -2)
      return true;
  }
  //normal way to move
  if(color_ == WHITE && rank_step ==1)
    return true;
  if(color_ == BLACK && rank_step ==-1)
    return true;
   return false;
}
