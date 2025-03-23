CC=g++
CFLAGS=-std=c++23

sudoku: sudoku.o board.o evaluator.o
	$(CC) -o sudoku sudoku.o board.o position.o evaluator.o $(CFLAGS)
	$(RM) *.o

sudoku.o: sudoku.cpp evaluator.h position.h board.h 
	$(CC) -c sudoku.cpp $(CFLAGS)

board.o: board.cpp board.h 
	$(CC) -c board.cpp $(CFLAGS)

position.o: position.cpp position.h
	$(CC) -c position.cpp $(CFLAGS)

evaluator.o: evaluator.cpp evaluator.h
	$(CC) -c evaluator.cpp $(CFLAGS)

clean:
	$(RM) *.o
