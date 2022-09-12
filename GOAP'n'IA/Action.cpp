#include "Action.h"


Action::Action(const std::string& _name, const int& _cout = 1)
{
	this->Name = _name;
}

void Action::AddPrecondition(const Preconditions& _precondition)
{
	this->Precondition = _precondition;
}

void Action::AddEffect(const Effets& _effet)
{
	this->Effect = _effet;
}


void Action::ShowAction() const {
	std::cout << "Action : " << Name << ", Precondition : " << Precondition << ", Effect : " << Effect << std::endl;
}