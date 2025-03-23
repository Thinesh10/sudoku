#include "evaluator.h"

void Evaluator::setAllPossibilities()
{
    for (auto myIndex: std::views::iota(0, theDimension * theDimension))
    {
        for (auto myVal: std::views::iota(1, theDimension + 1))
        {
            thePossibleVals[myIndex].emplace(myVal);
        }
    }
}

void Evaluator::addRowIndices(std::set<unsigned int>& aIndexList, const unsigned int aRow)
{
    auto myRow = std::floor(aRow / theDimension);
    auto myStartIndex = std::floor(aRow / theDimension);
    auto myEndIndex = myStartIndex + theDimension;
    
    for (auto i = myStartIndex; i < myEndIndex; ++i)
    {
        aIndexList.emplace(i);
    }
}

void Evaluator::addColIndices(std::set<unsigned int>& aIndexList, const unsigned int aCol)
{
    auto myColRemainder = aCol % theDimension;
    
    for (auto i = 0; i < theDimension; ++i)
    {
        aIndexList.emplace(i * theDimension + myColRemainder);
    }
}

unsigned int Evaluator::getBoxIndex(unsigned int aRow, unsigned int aCol)
{
    auto myBoxRow = std::floor(aRow / theSqrtDimension);
    auto myBoxCol = std::floor(aCol / theSqrtDimension);
    return myBoxRow * theSqrtDimension + myBoxCol;
}

void Evaluator::addBoxIndices(std::set<unsigned int>& aIndexList, const unsigned int aRow, const unsigned int aCol)
{
    auto myBoxStartRow = std::floor(aRow / theSqrtDimension) * theSqrtDimension;
    auto myBoxStartCol = std::floor(aCol / theSqrtDimension) * theSqrtDimension;

    for (auto myRow = myBoxStartRow; myRow < myBoxStartRow + theSqrtDimension; ++myRow)
    {
        for (auto myCol = myBoxStartCol; myCol < myBoxStartCol + theSqrtDimension; ++myCol)
        {
            aIndexList.emplace(getIndex(myRow, myCol));
        }
    }
}

std::set<unsigned int> Evaluator::getIndexList(const unsigned int aRow, const unsigned int aCol)
{
    std::set<unsigned int> myIndexList;
    addRowIndices(myIndexList, aRow);
    addColIndices(myIndexList, aCol);
    addBoxIndices(myIndexList, aRow, aCol);
    return myIndexList;
}

void Evaluator::initialize(const std::vector<std::vector<int>>& aBoard)
{
    setAllPossibilities();

    for (const auto [myRowIndex, myRow]: std::views::enumerate(aBoard))
    {
        auto myRowValMap = myRow | std::views::enumerate | std::ranges::to<std::map<int, int>();
        
        for (const auto [myColIndex, myVal]: myRowValMap)
        {
            if (myVal != 0)
            {
                for (auto myAffectedIndex: getIndexList(myRowIndex, myColIndex))
                {
                    thePossibleVals[myAffectedIndex].erase(myVal)
                }
            }
        }
    }

    for (auto index = 0; index < theDimension * theDimension; ++index)
    {
        for (auto it = thePossibleVals[index].begin(); it != thePossibleVals[index].end(); ++it)
        {
            std::cout << *it << "->" << std::endl;
        }
    }
}
