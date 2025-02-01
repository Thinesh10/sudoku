#include <iostream>
#include "board.h"

int main(int argc, char *argv[])
{
	// only supports 9x9
	std::cout << "Only supports 9x9 Sudoku" << std::endl;
	Board myBoard;
	std::cout << "Initial board" << std::endl;	
	myBoard.displayBoard();
	myBoard.solve();

	return 0;
}
