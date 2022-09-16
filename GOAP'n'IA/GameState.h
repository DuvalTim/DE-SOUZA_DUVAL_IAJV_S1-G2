#pragma once
#include "Action.h"
#include <assert.h>

class GameState
{

private:
	uint16_t HungryValue;
	uint16_t SleepValue;
	uint16_t MoneyValue;
	uint16_t RepasValue;
	uint16_t FunValue;
	Action *GoalAction = nullptr;
	void CreateActions();

public:
	GameState(const uint16_t& _hungryValue, const uint16_t& _sleepValue, const uint16_t& _moneyValue, const uint16_t& _repasValue, const uint16_t& _funValue);
	void Run();
	void operator~() {
		if (GoalAction != nullptr)
		{
			delete GoalAction;
		}
	}
};

