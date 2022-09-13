#include "GameState.h"

void GameState::CreateActions()
{
	Action reviser = Action("Reviser");

	Precondition prec = Precondition(Precondition::PreconditionList::AvoirDormis, 1, &HungryValue);
	Effet eff = Effet(Effet::EffetListe::GagnerUnRepas, &MoneyValue, 1);
	/*
	prec.IsValid<uint16_t>([test]() mutable
		{
			return *test > 2;
		}
	);
	*/

	reviser.AddPrecondition(prec);
	reviser.AddEffect(eff);
	Actions.push_back(reviser);

	reviser = Action("Reviser");

	prec = Precondition(Precondition::PreconditionList::AvoirDormis, 1, &HungryValue);
	eff = Effet(Effet::EffetListe::GagnerUnRepas, &MoneyValue, 1);
	reviser.AddPrecondition(prec);
	reviser.AddEffect(eff);
	Actions.push_back(reviser);
	
	/*
	prec.IsValid<uint16_t>([test]() mutable
		{
			return *test > 2;
		}
	);
	*/

	reviser.AddPrecondition(prec);
	reviser.AddEffect(eff);
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
			curr.OnActionValid();
			break;
		}
		else 
		{
			std::cout << "Action invalid for :" << curr.GetName() << std::endl;
		}
	}
}
