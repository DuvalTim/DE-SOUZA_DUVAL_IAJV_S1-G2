#pragma once

#include <iostream>
#include <functional>

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
		GagnerDuPlaisir,
		PerteForme,
		PerteGlucose,
		PerteArgent,
		PerteRepas
	};

	Effet(const EffetListe& _effet , uint16_t* _valueToDecrement, const uint16_t& _decrementStep)
	{
		CurrentEffet = _effet;
		ValueToDecrement = _valueToDecrement;
		DecrementStep = _decrementStep;
		OnActionCompleted = [](){};
	}

	void OnActionSuccess()
	{
		*ValueToDecrement += DecrementStep;
		std::cout << *ValueToDecrement << std::endl;
	}

	//void OnActionSuccess()
	//{
	//	OnActionCompleted();
	//}

	//void AddActionEvent(std::function<void()> _onActionCompleted)
	//{
	//	OnActionCompleted = _onActionCompleted;
	//}

	//int OnActionSuccess(int x, int y, int (*function)(int, int)) { return function(x, y); }

	friend std::ostream& operator<<(std::ostream& os, const Effet& effet);

private:
	EffetListe CurrentEffet;
	uint16_t* ValueToDecrement;
	uint16_t DecrementStep;

	std::function<void()> OnActionCompleted;
};