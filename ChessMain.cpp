#include <iostream>

using namespace std;

#include "ChessBoard.h"
#include "helper.h"
int main() {

    cout << "===========================" << endl;
    cout << "Testing the Chess Engine" << endl;
    cout << "===========================" << endl;
    cout << endl;

    ChessBoard cb;
  cb.submitMove("E2", "E3");
  cb.submitMove("A7", "A5");
  cout << endl;

  cb.submitMove("D1", "H5");
  cb.submitMove("A8", "A6");
  cout << endl;

  cb.submitMove("H5", "A5");
  cb.submitMove("H7", "H5");
  cout << endl;

  cb.submitMove("H2", "H4");
  cb.submitMove("A6", "H6");
  cout << endl;

  cb.submitMove("A5", "C7");
  cb.submitMove("F7", "F6");
  cout << endl;

  cb.submitMove("C7", "D7");
  cb.submitMove("E8", "F7");
  cout << endl;

  cb.submitMove("D7", "B7");
  cb.submitMove("D8", "D3");
  cout << endl;

  cb.submitMove("B7", "B8");
  cb.submitMove("D3", "H7");
  cout << endl;

  cb.submitMove("B8", "C8");
  cb.submitMove("F7", "G6");
  cout << endl;

  cb.submitMove("C8", "E6");
  cb.printBoard();

    return 0;
}
