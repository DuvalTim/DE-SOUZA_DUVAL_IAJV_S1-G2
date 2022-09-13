#pragma once

#include <vector>
#include "Precondition.h"
#include "Effet.h"


class Action
{
private:
	std::string Name;
	std::vector<Effet> Effets;
	std::vector<Precondition> Preconditions;
	int Cout;
public:
	Action(const std::string& _name, const int& _cout = 1);
	void AddPrecondition(const Precondition _precondition);
	void AddEffect(const Effet _effet);
	void OnActionValid();
	friend std::ostream& operator<<(std::ostream& os, const Action& action);
	std::vector<Precondition> GetPreconditions() const {
		return Preconditions;
	}
	std::string GetName() const {
		return Name;
	}
};

