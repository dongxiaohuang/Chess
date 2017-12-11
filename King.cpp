#include "King.h"

King::King(string name, Color color, ChessBoard* cb):Chess(name,color,cb){}
bool King::isValidMove(Chess* board_[8][8],int from_rank, int from_file, int to_rank, int to_file)
{
  if(chess_board_->isOccupied(board_, to_rank, to_file))
  {
    if(! isKillable(board_,to_rank, to_file))
    return false;
  }
  int rank_diff = to_rank - from_rank;
  int file_diff = to_file - from_file;
  if((rank_diff == 0) && (file_diff == -1 || file_diff == 1)) // move one square left or right
    return true;
  if((file_diff == 0) && (rank_diff == -1 || rank_diff == 1)) // move one square up or down
    return true;
  return false;
}
