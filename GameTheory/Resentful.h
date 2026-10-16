#pragma once
#include "IStrategy.h"

class Resentful : public IStrategy
{
    Resentful() : IStrategy("AlwaysCooperateStrategy"), opponentBetray(false){}
    ~Resentful() = default;
    
    Choice Decide(const std::vector<Choice>& previousDecisions, const std::vector<Choice>& opponentPreviousDecisions) override
    {
        if (opponentPreviousDecisions.back() == Choice::Betray)
        {
            opponentBetray = true;
        }
        if (!opponentBetray)
        {
            return Choice::Cooperate;
        }
        return Choice::Betray;
    }
    
    std::string Name;
private :
    bool opponentBetray;
};
