#include "evaluator.h"
#include <math.h>


void Evaluator::setAllPossibilities()
{
    for (auto myIndex: std::views::iota(0, theDimension * theDimension))
    {
        for (auto myVal: std::views::iota(1, theDimension + 1))
        {
            thePossibleVals[myIndex].emplace(myVal)
        }
    }
}

void Evaluator::addRowIndices(std::set<unsigned int>& aIndexList, const unsigned int aRow)
{
    auto myRow = std::floor(aRow / theDimension);

}

void Evaluator::addColIndices(std::set<unsigned int>& aIndexList, const unsigned int aCol)
{
    auto myColRemainder = aCol % theDimension;

}

static unsigned int getBoxIndex(unsigned int aRow, unsigned int aCol)
{
    auto mySqrtDimension = std::sqrt(theDimension);
    auto myBoxRow = std::floor(aRow / mySqrtDimension);
    auto myBoxCol = std::floor(aCol / mySqrtDimension);
    return myBoxRow * mySqrtDimension + myBoxCol;
}

void Evaluator::addBoxIndices(std::set<unsigned int>& aIndexList, const unsigned int aRow, const unsigned int aCol)
{
    auto myBoxIndex = getBoxIndex(aRow, aCol);
    


}

std::set<unsigned int> Evaluator::getIndexList(const unsigned int aRow, const unsigned int aCol)
{
    std::set<unsigned int> myIndexList();


}


void Evaluator::initialize(const std::vector<std::vector<int>>& aBoard)
{
    setAllPossibilities();

    for (const auto [myRow, myRow]: std::views::enumerate(aBoard))
    {
        auto myRowValMap = myRow | std::views::enumerate | std::ranges::to<std::map>();
        
        for (const auto [myCol, myVal]: myRowValMap)
        {
            auto myIndex = getIndex(myRow, myCol);
            if (myVal != 0)
            {
                thePossibleVals.erase(myIndex);
                for (auto myAffectedIndex: getIndexList(myRow, myCol))
                {
                    thePossbleVals[myAffectedIndex].erase(myVal)
                }
            }
        }

    }

    for (Val myIndex = 0, myIndex < (theDimension * theDimension), ++myIndex)
    {

    }
}
