#pragma once
#include "IStrategy.h"

class AlwaysBetray : public IStrategy
{
public:

    AlwaysBetray() : IStrategy("AlwaysCooperateStrategy"){}
    ~AlwaysBetray() = default;
    
    Choice Decide(const std::vector<Choice>& previousDecisions, const std::vector<Choice>& opponentPreviousDecisions) override {return Choice::Betray;}
    
    std::string Name;
};
