#pragma once
#include "Action.h"
#include <assert.h>

class GameState
{

private:
	uint16_t HungryValue;
	uint16_t SleepValue;
	uint16_t MoneyValue;
	std::vector<Action> Actions;

	void CreateActions();

public:
	GameState(const uint16_t& _hungryValue, const uint16_t& _sleepValue, const uint16_t& _moneyValue);
	void Run();
};

