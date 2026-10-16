#pragma once
#include "IStrategy.h"
#include <cstdlib>

class RandomStrategy : public IStrategy
{
public:
    RandomStrategy() : IStrategy("Random") {}

    Choice Decide(const std::vector<Choice>&, const std::vector<Choice>&) override
    {
        return (std::rand() % 2 == 0) ? Choice::Betray : Choice::Cooperate;
    }
};