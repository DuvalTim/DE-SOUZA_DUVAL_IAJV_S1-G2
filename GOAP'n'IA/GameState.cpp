#include "GameState.h"

void GameState::CreateActions()
{
	GoalAction = new Action("Travailler", 2);

	Precondition prec = Precondition(Precondition::PreconditionList::AvoirDormis, 1, &SleepValue);
	Precondition prec2 = Precondition(Precondition::PreconditionList::AvoirFaim, 1, &HungryValue);
	Effet eff = Effet(Effet::EffetListe::GagnerDeLArgent, &MoneyValue, 1);
	Effet eff2 = Effet(Effet::EffetListe::PerteForme, &SleepValue, -1);
	Effet eff3 = Effet(Effet::EffetListe::PerteGlucose, &HungryValue, -1);

	GoalAction->AddPrecondition(prec);
	GoalAction->AddPrecondition(prec2);
	GoalAction->AddEffect(eff);
	GoalAction->AddEffect(eff2);
	GoalAction->AddEffect(eff3);

	//========================================

	Action manger = Action("Manger", 1);

	prec = Precondition(Precondition::PreconditionList::AvoirDeLaNourriture, 1, &RepasValue);
	eff = Effet(Effet::EffetListe::GagnerDuGlucose, &HungryValue, 1);
	eff2 = Effet(Effet::EffetListe::PerteRepas, &RepasValue, -1);
	manger.AddPrecondition(prec);
	manger.AddEffect(eff);
	manger.AddEffect(eff2);

	//========================================

	Action dormir = Action("Dormir", 3);

	prec = Precondition(Precondition::PreconditionList::AvoirFaim, 1, &HungryValue);
	eff = Effet(Effet::EffetListe::GagnerDeLaForme, &SleepValue, 1);
	dormir.AddPrecondition(prec);
	dormir.AddEffect(eff);

	//========================================

	Action courses = Action("Courses", 1);

	prec = Precondition(Precondition::PreconditionList::AvoirDeLArgent, 1, &MoneyValue);
	eff = Effet(Effet::EffetListe::GagnerUnRepas, &RepasValue, 1);
	eff2 = Effet(Effet::EffetListe::PerteArgent, &MoneyValue, -1);
	courses.AddPrecondition(prec);
	courses.AddEffect(eff);
	courses.AddEffect(eff2);

	//========================================

	Action loisir = Action("Loisir", 9);

	prec = Precondition(Precondition::PreconditionList::AvoirDeLArgent, 1, &MoneyValue);
	eff = Effet(Effet::EffetListe::GagnerDuPlaisir, &FunValue, 1);
	eff2 = Effet(Effet::EffetListe::PerteArgent, &MoneyValue, -1);
	loisir.AddPrecondition(prec);
	loisir.AddEffect(eff);
	loisir.AddEffect(eff2);

	//========================================

	manger.AddPreviousAction(courses);
	GoalAction->AddPreviousAction(manger);
	GoalAction->AddPreviousAction(dormir);
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

	// declaration
	std::vector<int>* Couts = new std::vector<int>();
	std::vector<std::vector<Action>>* Actions = new std::vector<std::vector<Action>>();

	// calcul des couts
	GoalAction->CalculateCost(Couts, Actions, *Couts, *Actions, 0);

	// recuperation des valeurs
	std::vector<int> coutsObtenus = *Couts;
	std::vector<std::vector<Action>> actionCombinaisons = *Actions;

	if (actionCombinaisons.size() > 0)
	{
		std::cout << "Liste des combinaisons possibles :" << std::endl;
		size_t moinsCouteuseIndex = 0;

		// recherche action moins couteuse plus affichage
		for (size_t i = 0; i < actionCombinaisons.size() ; i++)
		{
			std::cout << "Cout : " << coutsObtenus[i] << ", actions : ";
			for (Action oneAction : actionCombinaisons[i])
			{
				std::cout << oneAction.GetName() << " ";
			}
			std::cout << std::endl;

			if (i != 0)
			{
				if (coutsObtenus[i] < coutsObtenus[moinsCouteuseIndex]) // si nouveau cout inferieur a l ancien
				{
					moinsCouteuseIndex = i;
				}
				else if (coutsObtenus[i] == coutsObtenus[moinsCouteuseIndex]) // si cout egal mais moins d action a effectuer
				{
					if (actionCombinaisons[i].size() < actionCombinaisons[moinsCouteuseIndex].size())
					{
						moinsCouteuseIndex = i;
					}
				}
			}
		}
		
		// lancement serie d action moins couteuse
		std::vector<Action> actionsAEffectuer = actionCombinaisons[moinsCouteuseIndex];
		int i = actionsAEffectuer.size() ;
		for (;;)
		{
			i--;
			if (i < 0)
			{
				break;
			}
			std::vector<Precondition> precs = actionsAEffectuer[i].GetPreconditions();
			size_t j;
			for (j = 0; j < precs.size(); j++)
			{
				if (!precs[j].IsTrue())
				{
					break;
				}
			}
			if (j == precs.size())
			{
				std::cout << "Action realisable :" << actionsAEffectuer[i].GetName() << std::endl;
				actionsAEffectuer[i].OnActionValid();
			}
			else
			{
				std::cout << "Action invalid for :" << actionsAEffectuer[i].GetName() << std::endl;
			}
		}
	}
	else
	{
		std::cout << "Aucune combinaisons trouvees." << std::endl;
	}
	//for (Action curr : Actions)
	//{
	//	std::vector<Precondition> precs = curr.GetPreconditions();
	//	size_t i = 0;
	//	for (i; i < precs.size(); i++)
	//	{
	//		if (!precs[i].IsTrue())
	//		{
	//			break;
	//		}
	//	}
	//	if (i == precs.size())
	//	{
	//		std::cout << "Action realisable :" << curr.GetName() << std::endl;
	//		//curr.OnActionValid();
	//		realisablesActions.push_back(curr);
	//		//break;
	//	}
	//	else 
	//	{
	//		std::cout << "Action invalid for :" << curr.GetName() << std::endl;
	//	}
	//}
}
