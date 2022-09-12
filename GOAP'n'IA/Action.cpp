#include "Action.h"


Action::Action(const std::string& _name, const int& _cout)
{
	this->Name = _name;
	this->Cout = _cout;
	this->Preconditions = std::vector<Precondition>();
	this->Effets = std::vector<Effet>();
}

void Action::AddPrecondition(const Precondition _precondition)
{
	this->Preconditions.push_back(_precondition);
}

void Action::AddEffect(const Effet _effet)
{
	this->Effets.push_back(_effet);
}


std::ostream& operator<<(std::ostream& os, const Action& action)
{
	os << "Action :" << action.Name;
	os << ", Precondition(s) :";
	for (Precondition prec : action.Preconditions)
	{
		os << " " << prec;
	}
	os << ", Effect(s) :";
	for (Effet eff : action.Effets)
	{
		os << " " << eff;
	}
	return os;
}