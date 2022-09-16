#pragma once
#include <iostream>

class Precondition
{
public:

	/// <summary>
	/// Liste des preconditions
	/// </summary>
	enum class PreconditionList {
		AvoirDormis,
		AvoirFaim,
		AvoirDeLaNourriture,
		AvoirDeLArgent
	};

	/// <summary>
	/// Return true quand la valeur de l attribut associe est superieur a la valeur minimale de la precondition
	/// </summary>
	/// <returns></returns>
	bool IsTrue() const
	{
		return *AttributeLinked >= MinValue;
	}

	/// <summary>
	/// Creation d un precondition
	/// </summary>
	/// <param name="_preconditionList">Precondition parmi la liste</param>
	/// <param name="_minValue">Valeur minimale a laquelle l attribut linked est associee</param>
	/// <param name="_attributeLinked">L attribut associe a la precondition</param>
	Precondition(const PreconditionList& _preconditionList, const uint16_t& _minValue, uint16_t* _attributeLinked)
	{
		CurrentPrecondition = _preconditionList;
		MinValue = _minValue;
		AttributeLinked = _attributeLinked;
	}

	/// <summary>
	/// Operateur ostream pour lire les donnes de la precondition
	/// </summary>
	/// <param name="os">le stream de sortie</param>
	/// <param name="action">la precondition a lire</param>
	/// <returns>le stream avec les donnes de la precondition ajoutes</returns>
	friend std::ostream& operator<<(std::ostream& os, const Precondition& precondition);

private:

	/// <summary>
	/// Precondition actuelle parmi la liste
	/// </summary>
	PreconditionList CurrentPrecondition;

	/// <summary>
	/// Valeur minimale a laquelle l attribut linked est associee
	/// </summary>
	uint16_t MinValue;

	/// <summary>
	/// L attribut associe a la precondition
	/// </summary>
	uint16_t* AttributeLinked;
};

