#include "Chess.h"

Chess::Chess(string chess_name, Color chess_color, ChessBoard* cb)
        : name_(chess_name),color_(chess_color),chess_board_(cb){};

Color Chess::getColor()
{
  return color_;
}

string Chess::getName()
{
  return name_;
}

bool Chess::isKillable(Chess* board_[8][8],int to_rank, int to_file)
{
   Color dest_piece_color = chess_board_ -> getCoorColor(board_,to_rank, to_file);
   return (color_ == dest_piece_color) ? false:true;
}

bool Chess::checkFourDirection(int from_rank, int from_file, int to_rank, int to_file, int rank_step_abs, int file_step_abs)
{
  int rank_step = to_rank - from_rank;
  int file_step = to_file - from_file;
  // move to NE
  if(rank_step == rank_step_abs && file_step == file_step_abs)
  {
    return true;
  }
  // move to NW
  if(rank_step == rank_step_abs && file_step == -file_step_abs)
  {
    return true;
  }
  // move to SE
  if(rank_step == -rank_step_abs && file_step == file_step_abs)
  {
    return true;
  }
  // move to SW
  if(rank_step == -rank_step_abs && file_step == -file_step_abs)
  {
    return true;
  }
  return false;
}
