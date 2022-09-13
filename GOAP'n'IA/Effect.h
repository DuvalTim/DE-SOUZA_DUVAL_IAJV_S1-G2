#pragma once

#include <iostream>

class Effet
{
private:
	uint16_t* ValueToDecrement;
	uint16_t DecrementStep;
public:

	/// <summary>
	/// Liste des effets
	/// </summary>
	enum EffetListe {
		GagnerDeLaForme,
		GagnerDuGlucose,
		GagnerUnRepas
	};

	Effet()
	{

	}

	int OnActionSuccess(int x, int y, int (*function)(int, int)) { return function(x, y); }
};