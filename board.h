#include <iostream>
#include <vector>
#include "evaluator.h"

class Board
{
	private:
		static constexpr int theDimension = 9;	
		Evaluator theEvaluator;
		std::vector<std::vector<int>> theBoard;

	public:
		Board(); //only supports 9x9 

		bool placeNumber(const int, const int, const int);
		bool removeNumber(const int, const int);	
		bool readBoard(std::istream&);
	    void displayBoard();	
		bool checkSolved();
		void solve();
};
