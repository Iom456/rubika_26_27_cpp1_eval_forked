#pragma once

#include <map>
#include <memory>
#include "Ranking.h"
#include <vector>
#include "IStrategy.h"

class Tournament
{
public:
	void PopulateStrategy();

	void Simulate();

	std::vector<Ranking> GenerateFinalRankingByPoint() const;
	std::vector<Ranking> GenerateFinalRankingByWinDrawLoss() const;
	
private:
	std::vector<std::unique_ptr<IStrategy>> possibleStrategies;
	std::map<std::unique_ptr<IStrategy>,std::unique_ptr<IStrategy>> matchs;
	
	std::map<std::string, Ranking*> results;
};


