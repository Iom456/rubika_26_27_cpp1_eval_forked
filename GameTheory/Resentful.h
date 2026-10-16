#pragma once
#include "IStrategy.h"
#include <algorithm>

class Resentful : public IStrategy
{
public:
    Resentful() : IStrategy("Resentful") {}
    ~Resentful() = default;

    Choice Decide(const std::vector<Choice>& previousDecisions,
                  const std::vector<Choice>& opponentPreviousDecisions) override
    {
        const bool opponentEverBetrayed = std::find(opponentPreviousDecisions.begin(),
                      opponentPreviousDecisions.end(),
                      Choice::Betray) != opponentPreviousDecisions.end();

        return opponentEverBetrayed ? Choice::Betray : Choice::Cooperate;
    }
};