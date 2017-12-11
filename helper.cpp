#include "helper.h"
int getFileIndex(string coor)
{
  char alpIndex = coor[0];
  int rank;
  if(alpIndex<= 'Z' && alpIndex>= 'A')
    {
      rank = alpIndex - 'A';
    }else
    {
      cerr<< "invalid Step coordinate, Please start with Uppercase Alphabate"<<endl;
      return -1;
    }
    return rank;
}
int getRankIndex(string coor)
{
  int file;
  char c = coor[2];
  if(c!= '\0')
   {
     cerr<<"please input correct coordinate, JUST 2 CHARACTERS, just one digital (1-8)number followed by Uppercase Alphabate" <<endl;
     return -1;
   }
  file = atoi((coor.substr(1,2)).c_str()); // if it fail to convert return 0;
  if(file>8)
    {
      cerr << "please input digital number in between 1-8" <<endl;
      return -1; 
    }
  if(file ==0 && coor[1] != '0')
    {
      cerr<<"please input correct coordinate, just ONE DIGITAL NUMBER followed by Uppercase Alphabate" <<endl;
      return -1;
    }
    return file-1;
}

ostream& operator<<(ostream& os, const Color& color)
{
    if(color == WHITE)
      os<< "White";
    else
      os << "Black";
    return os;
}
