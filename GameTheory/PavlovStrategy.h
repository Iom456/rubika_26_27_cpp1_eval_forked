#pragma once
#include "IStrategy.h"

class PavlovStrategy : public IStrategy
{
public:
    PavlovStrategy() : IStrategy("Pavlov") {}

    Choice Decide(const std::vector<Choice>& previousDecisions,
                  const std::vector<Choice>& opponentPreviousDecisions) override
    {
        if (previousDecisions.empty())
        {
            return Choice::Cooperate;
        }

        const Choice myLast = previousDecisions.back();
        const Choice opponentLast = opponentPreviousDecisions.back();

        if (opponentLast == Choice::Cooperate)
        {
            return myLast;
        }
        return (myLast == Choice::Cooperate) ? Choice::Betray : Choice::Cooperate;
    }
};