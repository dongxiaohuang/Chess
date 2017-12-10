OBJ = Chess.o Bishop.o Rook.o  helper.o King.o Knight.o Pawn.o Queen.o ChessBoard.o ChessMain.o
EXE = chess
CXX = g++
CXXFLAG = -Wall -g -MMD -std=c++11
$(EXE) : $(OBJ)
	$(CXX) $(OBJ) -o $@

%.o: %.cpp
	$(CXX) $(CXXFLAG) -c $<

-include $(OBJ:.o=.d)

clean:
	rm -f $(OBJ) $(EXE) $(OBJ:.o=.d)

.PHONEY: clean
