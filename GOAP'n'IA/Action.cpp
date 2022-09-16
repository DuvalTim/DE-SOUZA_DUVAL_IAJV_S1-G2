#include "Action.h"


Action::Action(const std::string& _name, const int& _cout)
{
	this->Name = _name;
	this->Cout = _cout;
	this->Preconditions = std::vector<Precondition>();
	this->Effets = std::vector<Effet>();
	this->PreviousActions = std::vector<Action*>();
}

void Action::AddPrecondition(const Precondition _precondition)
{
	this->Preconditions.push_back(_precondition);
}

void Action::AddEffect(const Effet _effet)
{
	this->Effets.push_back(_effet);
}

void Action::AddPreviousAction(const Action& _action)
{
	this->PreviousActions.push_back(new Action(_action));
}

void Action::OnActionValid()
{
	for (Effet effet : Effets)
	{
		effet.OnActionSuccess();
	}
}

std::ostream& operator<<(std::ostream& os, const Action& action)
{
	os << "Action :" << action.Name;
	os << ", Precondition(s) :";
	for (Precondition prec : action.Preconditions)
	{
		os << " " << prec;
	}
	os << ", Effet(s) :";
	for (Effet eff : action.Effets)
	{
		os << " " << eff;
	}
	return os;
}

void Action::CalculateCost(
	std::vector<int>* _Couts, 
	std::vector<std::vector<Action>>* _Actions, 
	std::vector<int> localCouts, 
	std::vector<std::vector<Action>> localActions, 
	const size_t& _CombinaisonIndex) const
{
	int cout = 0;
	for (size_t i = 0; i < Preconditions.size(); i++)
	{
		if (!Preconditions[i].IsTrue())
		{
			cout = this->Cout;
			break;
		}
	}
	int lastIndex = _Couts->size();
	std::vector<Action> newList;

	if (_CombinaisonIndex >= lastIndex) // nouvelle serie
	{
		int lastCout = 0;
		if (lastIndex > 0)
		{
			// cas 1 : action nouvelle serie avec ancienne liste a copier
			newList = localActions[_CombinaisonIndex - 1];
			lastCout = localCouts[_CombinaisonIndex - 1];
		}
		// else cas 2 : action nouvelle serie sans ancienne liste a copier
		newList.push_back(*this);
		lastCout += cout;
		_Actions->push_back(newList);
		_Couts->push_back(lastCout);
	}
	else
	{
		int lastCout = 0;
		if (lastIndex > 0) {
			lastIndex--;
			localCouts[lastIndex] = cout + localCouts[lastIndex];
			*_Couts = localCouts;
			localActions[lastIndex].push_back(*this);
			*_Actions = localActions;
		}
		else
		{
			// cas 4 : action ancienne serie avec ancienne liste vide
			_Couts->push_back(cout);
			std::vector<Action> newList;
			newList.push_back(*this);
			_Actions->push_back(newList);
		}
	}
	for (size_t i = 0; i < PreviousActions.size(); i++)
	{
		PreviousActions[i]->CalculateCost(_Couts, _Actions, *_Couts, *_Actions, i);
	}
}