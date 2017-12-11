#include "Knight.h"

Knight::Knight(string name, Color color, ChessBoard* cb):Chess(name,color,cb){}
bool Knight::isValidMove(Chess* board_[8][8],int from_rank, int from_file, int to_rank, int to_file)
{
  bool check_H_L;// check if it moves horizontally
  bool check_V_L; // check if it moves vertically
  //check destination
  if(chess_board_->isOccupied(board_,to_rank, to_file))
  {
    if(! isKillable(board_,to_rank, to_file))
    return false;
  }
  check_H_L = checkFourDirection(from_rank,from_file,to_rank,to_file,2,1);
  check_V_L = checkFourDirection(from_rank,from_file,to_rank,to_file,1,2);
  return (check_H_L||check_V_L);
}
