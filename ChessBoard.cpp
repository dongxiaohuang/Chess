#include "ChessBoard.h"
#include "Pawn.h"
#include "King.h"
#include "Rook.h"
#include "Bishop.h"
#include "Queen.h"
#include "Knight.h"
ColorText::Modifier def(ColorText::FG_DEFAULT);
ColorText::Modifier red(ColorText::FG_RED);
void ChessBoard::resetBoard()
{
  last_player_color_ = BLACK; // because white color player goes first
  // first delete the previous dynamicly chess pieces
  for (int i = 0; i <= 7; i++)
  {
    for(int j = 0; j <= 7; j++)
    {
      if(board_[i][j] != NULL)
        {
          delete board_[i][j];
          board_[i][j] = NULL;
        }
    }
  }
  // put new chess pieces
  for(int file = 0; file <= 7; file++)
    board_[1][file] = new Pawn("Pawn", WHITE, this);//rnak = 1
  for(int file = 0; file <= 7; file++)
    board_[6][file] = new Pawn("Pawn", BLACK, this);//rank = 7

  // add WHITE Rook
  board_[0][0] = new Rook("Rook",WHITE, this);
  board_[0][7] = new Rook("Rook",WHITE, this);
  // add BLACK Rook
  board_[7][0] = new Rook("Rook",BLACK, this);
  board_[7][7] = new Rook("Rook",BLACK, this);
  // add WHITE Knight
  board_[0][1] = new Knight("Knight",WHITE, this);
  board_[0][6] = new Knight("Knight",WHITE, this);
  // add BLACK Knight
  board_[7][1] = new Knight("Knight",BLACK, this);
  board_[7][6] = new Knight("Knight",BLACK, this);
  // add WHITE Bishop
  board_[0][2] = new Bishop("Bishop",WHITE, this);
  board_[0][5] = new Bishop("Bishop",WHITE, this);
  // add BLACK Bishop
  board_[7][2] = new Bishop("Bishop",BLACK, this);
  board_[7][5] = new Bishop("Bishop",BLACK, this);
  // add WHITE Queen
  board_[0][3] = new Queen("Queen",WHITE, this);
  // add BLACK Queen
  board_[7][3] = new Queen("Queen",BLACK, this);
  // add WHITE King
  board_[0][4] = new King("King",WHITE, this);
  white_king_rank_ = 0;
  white_king_file_ = 4;
  mock_white_king_r = 0;
  mock_white_king_f = 4;
  // add BLack King
  board_[7][4] = new King("King",BLACK, this);
  black_king_rank_ = 7;
  black_king_file_ = 4;
  mock_black_king_r = 7;
  mock_black_king_f = 4;

  cout << "A new chess game is started!" << endl;
}
ChessBoard::ChessBoard()
{
  //initialize the board_, all the array elements assigned to NULL;
  for (int i = 0; i <= 7; i++)
  {
    for(int j = 0; j <= 7; j++)
    {
          board_[i][j] = NULL;
    }
  }
  resetBoard();
}
// print ChessBoard used for debug
void ChessBoard::printBoard()
{
  cout << '\t' ;

  for(int file=0; file<=7; ++file)
    cout << static_cast<char>('A'+file) << '\t';
  cout << endl;
  for (int rank = 7; rank >= 0; --rank)
  {
    cout << rank+1<<'\t';
    for(int file = 0; file <= 7; file++)
      if(board_[rank][file] != NULL)
      {
        if(board_[rank][file] -> getColor() == BLACK)
          cout << red << board_[rank][file] -> getName() <<'\t'<<def;
        else
          cout << board_[rank][file] -> getName() <<'\t';
      }else
      {
        cout<<"\t";
      }
      cout << endl;
  }
  cout << '\t' ;
  for(int file=0; file<=7; file++)
    cout << static_cast<char>('A'+file) << '\t';
  cout << endl;
}

ChessBoard::~ChessBoard()
{
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      if(board_[i][j] != NULL)
        {
          delete board_[i][j];
          board_[i][j] = NULL;
        }
    }
  }
}
// function to make a mock move to check if this move will make self side piece in check
bool ChessBoard::isValidMockMove(Color current_player_color, int from_rank, int from_file, int to_rank, int to_file)
{
  //copy a new board
  Chess* board[8][8] ;// copy a new board
  for(int rank = 0; rank <8; ++rank)
    {
      for(int file = 0; file <8; ++file)
      {
        board[rank][file] = board_[rank][file];
      }
    }
  //copy finish
  string from_piece = board[from_rank][from_file] ->getName();

  //if king moves
  if(from_piece == "King" && board[from_rank][from_file]->getColor() == WHITE)
  {
    mock_white_king_r = to_rank;
    mock_white_king_f = to_file;
  }
  if(from_piece == "King" && board[from_rank][from_file]->getColor() == BLACK)
  {
    mock_black_king_r = to_rank;
    mock_black_king_f = to_file;
  }
  //make movement
  board[to_rank][to_file] = board[from_rank][from_file];
  board[from_rank][from_file] = NULL;
  isChecked = isInCheck(board, true);
  if(current_player_color == WHITE && is_White_Checked)
    return false;
  if(current_player_color == BLACK && is_Black_Checked)
    return false;
  return true;
}

// function to check if the move is valid according to the chess rule
bool ChessBoard::canMove(string from, string to)
{
  int from_rank;
  int from_file;
  int to_rank;
  int to_file;
  bool can_move;
  if(from == to) // check if it moves
  {
    cerr <<"you need to make a move when you try to move from \""<< from<<"\" to \""<<to << "\""<<endl;
    return false;
  }
  from_rank = getRankIndex(from);
  from_file = getFileIndex(from);
  to_rank = getRankIndex(to);
  to_file = getFileIndex(to);
  // check if the starting position is valid or not
  if(board_[from_rank][from_file] == NULL)
  {
    cerr <<"there is no piece at position " <<from << "!"<<endl;
    return false;
  }
  if(from_rank == -1 || from_file == -1 || to_rank ==-1 || to_file == -1)
  {
    cout << "wrong coordinate" <<endl;
    return false;
  }
  //check if is available
  current_player_color = board_[from_rank][from_file] -> getColor();
  if((current_player_color != last_player_color_) )
  {

    can_move = board_[from_rank][from_file] -> isValidMove(board_,from_rank, from_file, to_rank, to_file);
    if(can_move)
    {
      // to check if this move will let the current player in check
      if(!isValidMockMove(current_player_color, from_rank, from_file, to_rank, to_file))
        {
          cout << "You cannot make this move from "<<from <<" to "<<to<<" because it will let you in check" << endl;
          return false;
        }
      return true;
    }
    else
    {
      cout << current_player_color<<"'s "<<board_[from_rank][from_file]->getName() <<" cannot move to "<< to <<endl;
      return false;
    }
  }else
  {
    cerr<< "It is not "<<last_player_color_<<"'s turn to move!"<< endl;
    return false;
  }
}
// check if this move is valid for mock move
bool ChessBoard::canMove(Chess* board_[8][8], Color current_player_color, int from_rank, int from_file, int to_rank, int to_file)
{
  bool can_move;
  if(from_file == to_file && from_rank == to_rank) // check if it moves
  {
    return false;
  }
  // check if the starting position is valid or not
  if(board_[from_rank][from_file] == NULL)
  {
    return false;
  }
  //check if is available
  can_move = board_[from_rank][from_file] -> isValidMove(board_,from_rank, from_file, to_rank, to_file);
  if(can_move)
  {
      // to check if this move will let the current player in check
    if(!isValidMockMove(current_player_color, from_rank, from_file, to_rank, to_file))
      {
        return false;
      }
        return true;
  }
      return false;
}
// function to submitMove from a position to another position
void ChessBoard::submitMove(string from, string to)
{
  int from_rank;
  int from_file;
  int to_rank;
  int to_file;
  from_rank = getRankIndex(from);
  from_file = getFileIndex(from);
  to_rank = getRankIndex(to);
  to_file = getFileIndex(to);
  if(canMove(from,to))
    {
      makeMove(from, to, from_rank, from_file, to_rank, to_file);
      isChecked = isInCheck(board_,false); // make move and check if this move make the otehr player in check
      if(isChecked)
      {
        if(is_White_Checked)
          {
            if(checkMate(WHITE))
              {
                cout << "White is in checkMate"<< endl;
            }
            else  cout <<"White is in check" << endl; // the enemy
          }
        if(is_Black_Checked)
          {
            if(checkMate(BLACK))
              {
                cout << "Black is in checkmate"<<endl;
              }
            else cout <<"Black is in check" << endl; // the enemy
          }
      }else
      {
        //check if it is stalemate
        if(staleMate())
          cout << "the game ends with a stalemate" << endl;
      }
    }
}
// function to makemove
void ChessBoard::makeMove(string from, string to, int from_rank, int from_file, int to_rank, int to_file)
{
  int take_output = 0; // if the piece take other piece then it will not output the move because it has already output
  string to_piece;
  string from_piece = board_[from_rank][from_file]->getName();
  if(board_[to_rank][to_file] != NULL) // taking others piece
  {
    take_output = 1;
    string to_piece = board_[to_rank][to_file] -> getName();
    cout << current_player_color<< "'s "<<from_piece<<" moves from "<< from <<" to "<<to<< " taking "<<last_player_color_<<"'s "<< to_piece << endl;
    delete board_[to_rank][to_file];
  }
  //if king moves

  if(from_piece == "King" && board_[from_rank][from_file]->getColor() == WHITE)
  {
    white_king_rank_ = to_rank;
    white_king_file_ = to_file;
  }
  if(from_piece == "King" && board_[from_rank][from_file]->getColor() == BLACK)
  {
    black_king_rank_ = to_rank;
    black_king_file_ = to_file;
  }
  // check end
  //update last_player_color
  last_player_color_ = current_player_color;
  if(take_output == 0)
   cout <<  last_player_color_<<"'s "<<from_piece<< " moves from " <<from<<" to "<<to<<endl;
  //make movement
  board_[to_rank][to_file] = board_[from_rank][from_file];
  board_[from_rank][from_file] = NULL;
}

bool ChessBoard::isOccupied(Chess* board_[8][8], int rank, int file)
{
  return (board_[rank][file] == NULL)? false:true;
}
Color ChessBoard::getCoorColor(Chess* board_[8][8],int rank, int file)
{
  return board_[rank][file] -> getColor();
}
// function to check if a side is in check
bool ChessBoard::isInCheck(Chess* board[8][8], bool mock)
{
  //initialize is_White_Checked is_Black_Checked =false
  is_White_Checked = false;
  is_Black_Checked = false;

  Color next_player_color;
  for (int rank = 0; rank < 8; rank++)
  {
    for (int file = 0; file < 8; file++)
    {
      Chess* &next_move_chess = board[rank][file];
      if(next_move_chess != NULL)
      {
        next_player_color = next_move_chess -> getColor();
        if(next_player_color == WHITE)
        {
          if(!is_Black_Checked) // check only when the black is unchecked
          {
            if(mock)
            {
              if(next_move_chess -> isValidMove(board,rank,file,mock_black_king_r, mock_black_king_f))
              is_Black_Checked = true;
            }
            else//real
            {
                if(next_move_chess -> isValidMove(board,rank,file,black_king_rank_,black_king_file_))
                is_Black_Checked = true;
            }
          }
        }
        else // the piece is black
        {

          if(! is_White_Checked)
          {
            if(mock)
            {
              if(next_move_chess -> isValidMove(board,rank,file,mock_white_king_r, mock_white_king_f))
              is_White_Checked = true;
            }
            else// real move
            {
                if(next_move_chess -> isValidMove(board,rank,file,white_king_rank_,white_king_file_))
                  is_White_Checked = true;
            }
          }
        }
      }
    }
  }
  if(is_Black_Checked|| is_White_Checked)
    return true;
  return false;
}
// function to check if it is checkmate
bool ChessBoard::checkMate(Color be_checked_color)
{
    // copy a new board
    Chess* newboard[8][8] ;// copy a new board
    for(int rank = 0; rank <8; ++rank)
      {
        for(int file = 0; file <8; ++file)
        {
          newboard[rank][file] = board_[rank][file];
        }
      }
    // board finish
    if(be_checked_color == WHITE)
    {
      for(int rank = 0; rank <8; ++rank)
        {
          for(int file = 0; file <8; ++file)
          {
            if(newboard[rank][file] == NULL) continue;
            if(newboard[rank][file]->getColor() == WHITE)
            {
              for (int i = 0; i < 8; i++)
              {
                for (int j = 0; j < 8; j++)
                {
                  if(canMove(newboard, WHITE, rank, file, i, j))
                    return false;
                }
              }
            }
          }
        }
        return true;
    }
    if(be_checked_color == BLACK)
    {
      for(int rank = 0; rank <8; ++rank)
        {
          for(int file = 0; file <8; ++file)
          {
            if(newboard[rank][file] == NULL) continue;
            if(newboard[rank][file]->getColor() == BLACK)
            {
              for (int i = 0; i < 8; i++)
              {
                for (int j = 0 ; j < 8; j++)
                {
                  if(canMove(newboard, BLACK, rank, file, i, j))
                    return false;
                }
              }
            }
          }
        }
        return true;
    }

  return true;
}
//function to check if it is stalemate
bool ChessBoard::staleMate()
{
  // copy a new board
  Chess* newboard[8][8] ;// copy a new board
  for(int rank = 0; rank <8; ++rank)
    {
      for(int file = 0; file <8; ++file)
      {
        newboard[rank][file] = board_[rank][file];
      }
    }
  // board finish

  for(int rank = 0; rank < 8; ++rank)
    {
      for(int file = 0; file < 8; ++file)
      {
        if(newboard[rank][file] == NULL) continue;
        if(newboard[rank][file]->getColor() != current_player_color) //check if  next player have any valid move
        {
          for (int i = 0; i < 8; i++)
          {
            for (int j = 0 ; j < 8; j++)
            {
              if(canMove(newboard, newboard[rank][file]->getColor(), rank, file, i, j))
                return false;
            }
          }
        }
      }
    }
    return true;
}
