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


	/// <summary>
	/// Creation d un effet
	/// </summary>
	/// <param name="_effet">Effet parmi la liste</param>
	/// <param name="_valueToDecrement">Valeur a decrementer lors d une action effectuee</param>
	/// <param name="_decrementStep">Valeur a decrementer</param>
	Effet(const EffetListe& _effet , uint16_t* _valueToDecrement, const uint16_t& _decrementStep)
	{
		CurrentEffet = _effet;
		ValueToDecrement = _valueToDecrement;
		DecrementStep = _decrementStep;
	}

	/// <summary>
	/// Evenement lors d une action effectuee
	/// </summary>
	void OnActionSuccess()
	{
		*ValueToDecrement += DecrementStep;
		std::cout << *ValueToDecrement << std::endl;
	}

	friend std::ostream& operator<<(std::ostream& os, const Effet& effet);

private:
	EffetListe CurrentEffet;
	uint16_t* ValueToDecrement;
	uint16_t DecrementStep;
};