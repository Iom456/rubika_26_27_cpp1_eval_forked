#pragma once
#include "IStrategy.h"

class ProberStartStrategy : public IStrategy
{
public:
    ProberStartStrategy() : IStrategy("ProberStart") {}

    Choice Decide(const std::vector<Choice>& previousDecisions,
                  const std::vector<Choice>& opponentPreviousDecisions) override
    {
        const size_t round = previousDecisions.size();

        if (round == 0)
        {
            return Choice::Betray;
        }
        if (round < 3)
        {
            return Choice::Cooperate;
        }

        const bool punished = opponentPreviousDecisions[1] == Choice::Betray
                           || opponentPreviousDecisions[2] == Choice::Betray;

        if (!punished)
        {
            return Choice::Betray;
        }
        return opponentPreviousDecisions.back();
    }
};