#pragma once
#include "IStrategy.h"

class AlwaysCooperateStrategy : public IStrategy
{
public:
    
    AlwaysCooperateStrategy() : IStrategy("AlwaysCooperateStrategy"){}
    ~AlwaysCooperateStrategy() = default;
    
    Choice Decide(const std::vector<Choice>& previousDecisions, const std::vector<Choice>& opponentPreviousDecisions) override {return Choice::Cooperate;}
    
    std::string Name;
private:
};

