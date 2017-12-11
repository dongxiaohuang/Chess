#ifndef CHESS_PAWN_H
#define CHESS_PAWN_H


#include "Chess.h"
#include <string>
using namespace std;

class Pawn : public Chess {
public:
    Pawn(string name,Color color, ChessBoard* cb);
    bool isValidMove(Chess* board_[8][8],int from_rank, int from_file, int to_rank, int to_file) override;
    ~Pawn() override{};
};


#endif //CHESS_PAWN_H
