#include "Tournament.h"
#include <algorithm>
#include <iostream>
#include "AlwaysCooperateStrategy.h"
#include "AlwaysBetray.h"
#include "TitForTat.h"
#include "Resentful.h"
#include "RadomStrategy.h"
#include "PavlovStrategy.h"
#include "ProberStartStrategy.h"

void Tournament::PopulateStrategy()
{
    possibleStrategies.push_back(std::make_unique<AlwaysCooperateStrategy>());
    possibleStrategies.push_back(std::make_unique<AlwaysBetray>());
    possibleStrategies.push_back(std::make_unique<Resentful>());
    possibleStrategies.push_back(std::make_unique<TitForTat>());
    possibleStrategies.push_back(std::make_unique<ProberStartStrategy>());
    possibleStrategies.push_back(std::make_unique<PavlovStrategy>());
    possibleStrategies.push_back(std::make_unique<RandomStrategy>());
    
    for (int i = 0; i < possibleStrategies.size(); ++i)
    {
        Ranking strategy_stats;
        strategy_stats.StrategyName = possibleStrategies[i]->Name;
        strategy_stats.Lose = 0;
        strategy_stats.Win = 0;
        strategy_stats.Draw = 0;
        
        results[strategy_stats.StrategyName] = strategy_stats;
    }
}

void Tournament::Simulate()
{
    constexpr int roundsPerMatch = 50;

    for (size_t i = 0; i < possibleStrategies.size(); ++i)
    {
        for (size_t j = i + 1; j < possibleStrategies.size(); ++j)
        {
            IStrategy& player1_strategy = *possibleStrategies[i];
            IStrategy& player2_strategy = *possibleStrategies[j];

            std::vector<Choice> player1_decisions;
            std::vector<Choice> player2_decisions;

            int player1_score = 0;
            int player2_score = 0;

            for (int round = 0; round < roundsPerMatch; ++round)
            {
                Choice player1_choice = player1_strategy.Decide(player1_decisions, player2_decisions);
                Choice player2_choice = player2_strategy.Decide(player2_decisions, player1_decisions);

                player1_decisions.push_back(player1_choice);
                player2_decisions.push_back(player2_choice);

                if (player1_choice == Choice::Betray && player2_choice == Choice::Betray)
                {
                    player1_score += 1;
                    player2_score += 1;
                }
                else if (player1_choice == Choice::Cooperate && player2_choice == Choice::Cooperate)
                {
                    player1_score += 3;
                    player2_score += 3;
                }
                else if (player1_choice == Choice::Betray)
                {
                    player1_score += 5;
                }
                else 
                {
                    player2_score += 5;
                }
            }

            Ranking& player1_results = results[player1_strategy.Name];
            Ranking& player2_results = results[player2_strategy.Name];

            player1_results.TotalPoint += player1_score;
            player2_results.TotalPoint += player2_score;

            if (player1_score > player2_score)
            {
                player1_results.Win += 1;
                player2_results.Lose += 1;
            }
            else if (player2_score > player1_score)
            {
                player2_results.Win += 1;
                player1_results.Lose += 1;
            }
            else
            {
                player1_results.Draw += 1;
                player2_results.Draw += 1;
            }
        }
    }
}

std::vector<Ranking> Tournament::GenerateFinalRankingByPoint() const
{
    std::vector<Ranking> ranking;
    for (const auto& result : results)
    {
        ranking.push_back(result.second);
    }

    std::sort(ranking.begin(), ranking.end(), [](const Ranking& a, const Ranking& b)
    {
        if (a.TotalPoint != b.TotalPoint) return a.TotalPoint > b.TotalPoint;
        if (a.Win != b.Win)               return a.Win > b.Win;
        if (a.Draw != b.Draw)             return a.Draw > b.Draw;
        return a.Lose > b.Lose;
    });

    return ranking;
}

std::vector<Ranking> Tournament::GenerateFinalRankingByWinDrawLoss() const
{
    std::vector<Ranking> ranking;
    for (const auto& result : results)
    {
        ranking.push_back(result.second);
    }

    std::sort(ranking.begin(), ranking.end(), [](const Ranking& a, const Ranking& b)
    {
        if (a.Win != b.Win)   return a.Win > b.Win;
        if (a.Draw != b.Draw) return a.Draw > b.Draw;
        return a.Lose > b.Lose;
    });

    return ranking;
}
