//
// Created by Dongxiao Huang on 04/12/2017.
//

#ifndef CHESS_CHESSBOARD_H
#define CHESS_CHESSBOARD_H


#include "Chess.h"
#include <string>
#include "helper.h"
class Chess;
using namespace std;
class ChessBoard {

     Chess* board_[8][8];
     int white_king_rank_;
     int white_king_file_;
     int black_king_rank_;
     int black_king_file_;
     int mock_white_king_r;
     int mock_white_king_f;
     int mock_black_king_r;
     int mock_black_king_f;
     Color last_player_color_ = BLACK;// because white color player goes first
     Color current_player_color;
     bool isChecked = false;
     bool is_White_Checked = false;
     bool is_Black_Checked = false;
     int white_enemy_r; // who make the black in check
     int white_enemy_f; // who make the black in check
     int black_enemy_r; //who make the white in check
     int black_enemy_f;//who make the white in check

public:
    void submitMove(string , string);
    void resetBoard();
    void printBoard();
    void printBoard(Chess* board[8][8]); // to be delte
    ChessBoard();
    virtual ~ChessBoard();
    bool isOccupied(Chess* board_[8][8],int rank, int file);
    Color getCoorColor(Chess* board_[8][8],int rank, int file);
    bool isInCheck(Chess* board[8][8], bool mock);
    bool checkMate(Color be_checked_color);
    bool isValidMockMove(Color current_player_color, int from_rank, int from_file, int to_rank, int to_file);
    void makeMove(string from, string to, int from_rank, int from_file, int to_rank, int to_file);
    bool canMove(string from, string to);
    bool canMove(Chess* board[8][8],Color current_player_color, int from_rank, int from_file, int to_rank, int to_file);
    // void makeMove(Color current_player_color, int from_rank, int from_file, int to_rank, int to_file);
  };
#endif //CHESS_CHESSBOARD_H
