#include "GameState.h"

GameState::GameState(const uint16_t& _hungryValue, const uint16_t& _sleepValue, const uint16_t& _moneyValue)
{
	this->HungryValue = _hungryValue;
	this->SleepValue = _sleepValue;
	this->MoneyValue = _moneyValue;
}


void GameState::Run()
{
	assert(HungryValue >= 0);
	assert(SleepValue >= 0);
	assert(MoneyValue >= 0);
	for (Action curr : Actions)
	{
		std::vector<Precondition> precs = curr.GetPreconditions();
		size_t i = 0;
		for (i; i < precs.size(); i++)
		{
			if (!precs[i].IsTrue())
			{
				break;
			}
		}
		if (i == precs.size())
		{
			std::cout << "Value valid" << std::endl;
		}
		else 
		{
			std::cout << "Value invalid" << std::endl;
		}
	}
}
