#include "Bishop.h"

Bishop::Bishop(string name, Color color, ChessBoard* cb):Chess(name,color,cb)
{}
bool Bishop::isValidMove(Chess* board_[8][8], int from_rank, int from_file, int to_rank, int to_file)
{
  int square_diff;
  //check destination
  if(chess_board_->isOccupied(board_, to_rank, to_file))
  {
    if(! isKillable(board_,to_rank, to_file))
    return false;
  }
  // move to NE
  if(to_rank > from_rank && to_file > from_file)
  {
    if((to_rank - from_rank) == (to_file - from_file)) // move diagonally
    {
      square_diff = to_rank - from_rank;
      for (int i = 1; i < square_diff; i++) {
        if(chess_board_->isOccupied(board_,from_rank + i,from_file + i))
          return false;
      }
      return true;
    }
  }
  // move to NW
  if(to_rank > from_rank && to_file < from_file)
  {
    if((to_rank - from_rank) == (from_file - to_file)) // move diagonally
    {
      square_diff = to_rank - from_rank;
      for (int i = 1; i < square_diff; i++) {
        if(chess_board_->isOccupied(board_, from_rank + i,from_file - i))
          return false;
      }
      return true;
    }
  }
  // move to SE
  if(to_rank < from_rank && to_file > from_file)
  {
    if((from_rank - to_rank) == (to_file - from_file)) // move diagonally
    {
      square_diff = from_rank - to_rank;
      for (int i = 1; i < square_diff; i++) {
        if(chess_board_->isOccupied(board_, from_rank - i,from_file + i))
          return false;
      }
      return true;
    }
  }
  // move to SW
  if(to_rank < from_rank && to_file < from_file)
  {
    if((to_rank - from_rank) == (to_file - from_file)) // move diagonally
    {
      square_diff = from_rank - to_rank;
      for (int i = 1; i < square_diff; i++) {
        if(chess_board_->isOccupied(board_,from_rank - i,from_file - i))
          return false;
      }
      return true;
    }
  }
  return false;
}
