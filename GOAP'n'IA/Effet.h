#pragma once

#include <iostream>

class Effet
{
public:

	/// <summary>
	/// Liste des effets
	/// </summary>
	enum class EffetListe {
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
	Effet(const EffetListe& _effet, uint16_t* _valueToDecrement, const uint16_t& _decrementStep);

	/// <summary>
	/// Evenement lors d une action effectuee
	/// </summary>
	void OnActionSuccess();

	/// <summary>
	/// Operateur ostream pour lire les donnes de l effet
	/// </summary>
	/// <param name="os">le stream de sortie</param>
	/// <param name="action">l effet a lire</param>
	/// <returns>le stream avec les donnes de l effet ajoutes</returns>
	friend std::ostream& operator<<(std::ostream& os, const Effet& effet);

private:

	/// <summary>
	/// Effet courant
	/// </summary>
	EffetListe CurrentEffet;

	/// <summary>
	/// Valeur a decrementer
	/// </summary>
	uint16_t* ValueToDecrement;

	/// <summary>
	/// Quantite a decrementer
	/// </summary>
	uint16_t DecrementStep;
};