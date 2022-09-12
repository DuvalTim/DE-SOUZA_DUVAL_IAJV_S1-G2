#pragma once

#include <iostream>

/// <summary>
/// Liste des preconditions
/// </summary>
enum Preconditions {
	AvoirDuBois,
	AvoirSoif,
	AvoirUneHache
};

/// <summary>
/// Liste des effets
/// </summary>
enum Effets {
	GagnerDuBois,
	GagnerDeLEau,
	GagnerUneHache
};

class Action
{
private:
	std::string Name;
	Effets Effect;
	Preconditions Precondition;
	int Cout;
public:
	Action(const std::string& _name, const int& _cout = 1);
	void AddPrecondition(const Preconditions& _precondition);
	void AddEffect(const Effets& _effet);
	void ShowAction() const;
};

