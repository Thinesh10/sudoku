#include <array>
#include <unordered_set>
#include <unordered_map>
#include <list>
#include <cmath>
#include <vector>
#include <stack>

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
		static constexpr int theDimension = 9;
		typedef std::unordered_map<unsigned int, std::set<unsigned int>> IndexValsMap;

		IndexValsMap thePossibleVals;
		std::stack<std::pair<unsigned int, unsigned int>, IndexValsMap> theSnapShots;

	public:		
		Evaluator() = default;

		void initialize(const std::vector<std::vector<int>>&);
		Val getIndex(const Val aRowIndex, const Val aColIndex) 
		{return aRowIndex * theDimension + aColIndex;} const;
		std::set<unsigned int> Evaluator::getIndexList(const unsigned int, const unsigned int);
		void addRowIndices(std::set<unsigned int>&, const unsigned int);
		void addColIndices(std::set<unsigned int>&, const unsigned int);
		void addBoxIndices(std::set<unsigned int>&, const unsigned int, const unsigned int);


		void setAllPossibilities();
		void execute();
};
