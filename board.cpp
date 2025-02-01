#include "board.h"
#include <sstream>
#include <algorithm>

Board::Board()
{
    if (!readBoard(std::cin))
    {
		exit(1);
    }

	theEvaluator.initialize(theBoard);
}

bool Board::placeNumber(const int aRow, const int aCol, const int aVal)
{
	if (theBoard[aRow][aCol] != 0)
	{
		std::cout << "Error: Number already placed" << std::endl;
		return false;
	}

	theBoard[aRow][aCol] = aVal;
	return true;
}

bool Board::removeNumber(const int aRow, const int aCol)
{
	if (theBoard[aRow][aCol] == 0)
	{
		std::cout << "Error: No number placed" << std::endl;
		return false;
	}

	theBoard[aRow][aCol] = 0;
	return true;
}

bool Board::readBoard(std::istream& aIstream)
{
	std::stringstream mySS;
	std::string myCurrString;
	std::size_t myCounter = 0;
	while (std::getline(aIstream, myCurrString))
	{
		std::vector<int> myCurrRow;
		if (myCurrString.size() != theDimension) 
		{
			std::cout << "Incorrect number of columns [ " << myCurrString.size() << " ] in row [ " << myCounter << " ]" << std::endl;
			return false;	
		}

		std::for_each(myCurrString.begin(), myCurrString.end(), 
		[&myCurrRow] (auto aChar)
		{
			if (aChar == ' ') {
				myCurrRow.emplace_back(0);
			}
			else
			{
				myCurrRow.emplace_back(aChar - '0');				
			}		
		});
	
		theBoard.emplace_back(myCurrRow);
		++myCounter;
	}
	
	if (myCounter != theDimension) 
	{
		std::cout << "Incorrect number of rows [" << myCounter << " ]" << std::endl;
		return false;
	}

	return true;
}

void Board::displayBoard()
{
	const std::string myTopBottomBorder = "-------------------------------";
	const std::string myMidBorder = "|---------|---------|---------|";

	std::cout << myTopBottomBorder << std::endl;
	int myRowCount = 0;

	std::for_each(theBoard.begin(), theBoard.end(), 
	[&myRowCount, &myMidBorder](auto aRow) 
	{
		int myColCount = 0;
		
		if (myRowCount % 3 == 0 && myRowCount != 0)
		{
			std::cout << myMidBorder << std::endl;
		}

		std::for_each(aRow.begin(), aRow.end(), 
		[&myColCount](auto aVal)
		{
			if (myColCount % 3 == 0)
			{
				std::cout << "|";
			}

			++myColCount;
			aVal == 0 ? std::cout << "   " : std::cout << ' ' << aVal << ' ';
		}); 
	
		std::cout << "|" << std::endl;
		++myRowCount;
	});	
	
	std::cout << myTopBottomBorder << std::endl;
}

bool Board::checkSolved()
{
	for (int myRow = 0; myRow < theDimension; ++myRow)
	{
		for (int myCol = 0; myCol < theDimension; ++myCol)
		{
			if (theBoard[myRow][myCol] == 0)
			{
				return false;
			}
		}
	}
	return true;
}


void Board::solve()
{
	
	while(!checkSolved())
	{
		std::cout << "loop" << std::endl;
		break;

	}

	std::cout << "Solved!" << std::endl;


	// theEvaluator.execute();	
}

