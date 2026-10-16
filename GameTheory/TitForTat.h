#pragma once
#include "IStrategy.h"

class TitForTat: public IStrategy
{
public:
    
    TitForTat() : IStrategy("AlwaysCooperateStrategy"){}
    ~TitForTat() = default;
    
    Choice Decide(const std::vector<Choice>& previousDecisions, const std::vector<Choice>& opponentPreviousDecisions) override
    {
        if (opponentPreviousDecisions.empty())
        {
            return Choice::Cooperate;
        }
        else
        {
            return opponentPreviousDecisions.back();
        }
    }
    
    std::string Name;
};
