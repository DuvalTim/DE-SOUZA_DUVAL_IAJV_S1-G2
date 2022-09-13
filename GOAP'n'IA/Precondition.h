#pragma once
#include <iostream>
#include <functional>

class Precondition
{
public:

	/// <summary>
	/// Liste des preconditions
	/// </summary>
	enum PreconditionList {
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

