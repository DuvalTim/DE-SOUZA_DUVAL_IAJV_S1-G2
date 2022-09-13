#include "GameState.h"

void GameState::CreateActions()
{
	
	Action travailler = Action("Travailler");

    Precondition prec = Precondition(Precondition::PreconditionList::AvoirDormis, 1, &SleepValue);
    Precondition prec2 = Precondition(Precondition::PreconditionList::AvoirFaim, 1, &HungryValue);
    Effet eff = Effet(Effet::EffetListe::GagnerDeLArgent, &MoneyValue, 1);
    Effet eff2 = Effet(Effet::EffetListe::PerteForme, &SleepValue, -1);
    Effet eff3 = Effet(Effet::EffetListe::PerteGlucose, &HungryValue, -1);

	travailler.AddPrecondition(prec);
	travailler.AddPrecondition(prec2);
	travailler.AddEffect(eff);
	travailler.AddEffect(eff2);
	travailler.AddEffect(eff3);
	Actions.push_back(travailler);
	
	//========================================

    Action manger = Action("Manger");

    prec = Precondition(Precondition::PreconditionList::AvoirDeLaNourriture, 1, &RepasValue);
    eff = Effet(Effet::EffetListe::GagnerDuGlucose, &HungryValue, 1);
	eff2 = Effet(Effet::EffetListe::PerteRepas, &RepasValue, -1);
    manger.AddPrecondition(prec);
    manger.AddEffect(eff);
    manger.AddEffect(eff2);
    Actions.push_back(manger);

    //========================================

    Action dormir = Action("Dormir");

    prec = Precondition(Precondition::PreconditionList::AvoirFaim, 1, &HungryValue);
    eff = Effet(Effet::EffetListe::GagnerDeLaForme, &SleepValue, 1);
    dormir.AddPrecondition(prec);
    dormir.AddEffect(eff);
    Actions.push_back(dormir);

    //========================================

    Action courses = Action("Courses");

    prec = Precondition(Precondition::PreconditionList::AvoirDeLArgent, 1, &MoneyValue);
    eff = Effet(Effet::EffetListe::GagnerUnRepas, &RepasValue, 1);
	eff2 = Effet(Effet::EffetListe::PerteArgent, &MoneyValue, -1);
    courses.AddPrecondition(prec);
    courses.AddEffect(eff);
    courses.AddEffect(eff2);
    Actions.push_back(courses);

    //========================================

    Action loisir = Action("Loisir");

    prec = Precondition(Precondition::PreconditionList::AvoirDeLArgent, 1, &MoneyValue);
    eff = Effet(Effet::EffetListe::GagnerDuPlaisir, &FunValue, 1);
	eff2 = Effet(Effet::EffetListe::PerteArgent, &MoneyValue, -1);
    loisir.AddPrecondition(prec);
    loisir.AddEffect(eff);
    loisir.AddEffect(eff2);
    Actions.push_back(loisir);

    //========================================
	

	/*
	Action reviser = Action("Reviser");

	Precondition prec = Precondition(Precondition::PreconditionList::AvoirDormis, 1, &HungryValue);
	Effet eff = Effet(Effet::EffetListe::GagnerUnRepas, &MoneyValue, 1);


	
	prec.IsValid<uint16_t>([test]() mutable
		{
			return *test > 2;
		}
	);
	uint16_t* Hungry = &HungryValue;
	uint16_t* Money = &MoneyValue;
	eff.AddActionEvent(
		[&Hungry, &Money]()
		{
			std::cout << Hungry << std::endl;
			Hungry--;
			Money++;
			std::cout << "Hungry :" << Hungry << std::endl;
			std::cout << "Money :" << Money << std::endl;
		}
	);

	reviser.AddPrecondition(prec);
	reviser.AddEffect(eff);
	Actions.push_back(reviser);
	*/

}

GameState::GameState(const uint16_t& _hungryValue, const uint16_t& _sleepValue, const uint16_t& _moneyValue, const uint16_t& _repasValue, const uint16_t& _funValue)
{
	this->HungryValue = _hungryValue;
	this->SleepValue = _sleepValue;
	this->MoneyValue = _moneyValue;
	this->RepasValue = _repasValue;
	this->FunValue = _funValue;
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
