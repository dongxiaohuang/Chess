#include "Rook.h"
// Rook::Rook(string name, Color color, ChessBoard* cb):Chess(name,color,cb){}
// bool Rook::isValidMove(int from_rank, int from_file, int to_rank, int to_file)
// {
//   cout << "Knight check"<<endl;
//   return true;
// }
Rook::Rook(string name, Color color, ChessBoard* cb):Chess(name,color,cb)
{}
bool Rook::isValidMove(Chess* board_[8][8],int from_rank, int from_file, int to_rank, int to_file)
{
  if(chess_board_->isOccupied(board_,to_rank, to_file))
  {
    if(! isKillable(board_,to_rank, to_file))
    return false;
  }
  if(from_rank == to_rank) // move in the same rank
    {
      if(from_file > to_file) // move to the left
        {
          for(int file = to_file+1; file< from_file; file++) // check if leap over pieces; not include the previous position
          {
            if(chess_board_->isOccupied(board_,from_rank,file))
              return false;
          }
          return true;
        }else // move to right
        {
          for(int file = from_file+1; file< to_file; file++) // check if leap over pieces; not include the previous position
          {
            if(chess_board_->isOccupied(board_,from_rank,file))
              return false;
          }
          return true;
        }
    }
    if(from_file == to_file) // move in the same file
    {
      if(from_rank > to_rank) // move downward
        {
          for(int rank = to_rank+1; rank< from_rank; ++rank) // check if leap over pieces; not include the previous position
          {
            if(chess_board_->isOccupied(board_,rank,from_file))
              return false;
          }
          return true;
        }else // move upward
        {
          for(int rank = from_rank+1; rank< to_rank; ++rank) // check if leap over pieces; not include the previous position
          {
            if(chess_board_->isOccupied(board_,rank,from_file))
              return false;
          }
          return true;
        }
    }
  return false;
}
