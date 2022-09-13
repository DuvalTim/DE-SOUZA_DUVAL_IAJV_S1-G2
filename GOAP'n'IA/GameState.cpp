#include "GameState.h"

void GameState::CreateActions()
{
	Action reviser = Action("Reviser");
	reviser.AddEffect(Effet::GagnerDeLaForme);
	reviser.AddEffect(Effet::GagnerDuGlucose);
	Precondition prec = Precondition(Precondition::PreconditionList::AvoirFaim, 1, &HungryValue);

	/*
	prec.IsValid<uint16_t>([test]() mutable
		{
			return *test > 2;
		}
	);
	*/

	reviser.AddPrecondition(prec);
	std::cout << reviser << std::endl;
	Actions.push_back(reviser);
}

GameState::GameState(const uint16_t& _hungryValue, const uint16_t& _sleepValue, const uint16_t& _moneyValue)
{
	this->HungryValue = _hungryValue;
	this->SleepValue = _sleepValue;
	this->MoneyValue = _moneyValue;
	CreateActions();
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
			std::cout << "Action valid :" << curr.GetName() << std::endl;
		}
		else 
		{
			std::cout << "Value invalid" << std::endl;
		}
	}
}
