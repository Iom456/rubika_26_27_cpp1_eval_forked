#pragma once
#include "IStrategy.h"

class Resentful : public IStrategy
{
    Resentful() : IStrategy("AlwaysCooperateStrategy"){}
    ~Resentful() = default;
    
    Choice Decide(const std::vector<Choice>& previousDecisions, const std::vector<Choice>& opponentPreviousDecisions) override {return Choice::Cooperate;}
    
    std::string Name;    
};
