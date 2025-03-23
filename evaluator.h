#include <array>
#include <unordered_set>
#include <unordered_map>
#include <map>
#include <list>
#include <cmath>
#include <vector>
#include <set>
#include <iostream>
#include <ranges>
#include <math.h>

#pragma once

typedef enum
{
	ROW,
	COL,
	BOX,
} Types;

class Evaluator
{
	private:
		static constexpr auto theDimension = 9;
    	static constexpr auto theSqrtDimension = std::sqrt(theDimension);
		typedef std::unordered_map<unsigned int, std::set<unsigned int>> IndexValsMap;
		IndexValsMap thePossibleVals;
		std::unordered_map<unsigned int, IndexValsMap> theSnapShots;

	public:		
		Evaluator() = default;

		void initialize(const std::vector<std::vector<int>>&);
		unsigned int getIndex(const unsigned int aRowIndex, const unsigned int aColIndex) 
		{return aRowIndex * theDimension + aColIndex;};
		std::set<unsigned int> getIndexList(const unsigned int aRow, const unsigned int aCol);
		void addRowIndices(std::set<unsigned int>&, const unsigned int);
		void addColIndices(std::set<unsigned int>&, const unsigned int);
		void addBoxIndices(std::set<unsigned int>&, const unsigned int, const unsigned int);
		unsigned int getBoxIndex(unsigned int aRow, unsigned int aCol);
		void setAllPossibilities();
		void execute();
};
