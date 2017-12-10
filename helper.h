//
// Created by Dongxiao Huang on 04/12/2017.
//

#ifndef CHESS_HELPER_H
#define CHESS_HELPER_H

#include <string>
#include<iostream>
#include <ostream>
using namespace std;
enum Color {WHITE, BLACK};
int const GAME_OVER =-1;
int getRankIndex(string coordinate);
int getFileIndex(string coordinate);
ostream& operator<<(ostream& os, const Color& color); //make the output more readable
namespace ColorText
{
  enum Code
  {
         FG_RED      = 31,
         FG_DEFAULT  = 39
   };
class Modifier {
        Code code;
    public:
        Modifier(Code pCode) : code(pCode) {}
        friend std::ostream&
        operator<<(std::ostream& os, const Modifier& mod) {
            return os << "\033[" << mod.code << "m";
        }
    };
}

#endif //CHESS_HELPER_H
