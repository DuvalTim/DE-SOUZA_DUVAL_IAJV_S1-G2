#pragma once

#include <iostream>

class Effet
{
public:

	/// <summary>
	/// Liste des effets
	/// </summary>
	enum EffetListe {
		GagnerDeLaForme,
		GagnerDuGlucose,
		GagnerUnRepas,
		GagnerDeLArgent,
		GagnerDuPlaisir
	};

	Effet(const EffetListe& _effet , uint16_t* _valueToDecrement, const uint16_t& _decrementStep)
	{
		CurrentEffet = _effet;
		ValueToDecrement = _valueToDecrement;
		DecrementStep = _decrementStep;
	}

	void OnActionSuccess()
	{
		*ValueToDecrement += DecrementStep;
		std::cout << *ValueToDecrement << std::endl;
	}

	int OnActionSuccess(int x, int y, int (*function)(int, int)) { return function(x, y); }

	friend std::ostream& operator<<(std::ostream& os, const Effet& effet);

private:
	EffetListe CurrentEffet;
	uint16_t* ValueToDecrement;
	uint16_t DecrementStep;
};