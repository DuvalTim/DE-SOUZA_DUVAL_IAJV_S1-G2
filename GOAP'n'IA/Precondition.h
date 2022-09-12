#pragma once
#include <iostream>


class Precondition
{
public:

	/// <summary>
	/// Liste des preconditions
	/// </summary>
	enum PreconditionList {
		AvoirDormis,
		AvoirFaim,
		AvoirDeLaNourriture
	};

	bool IsTrue() const
	{
		return *AttributeLinked >= MinValue;
	}

	Precondition(const PreconditionList& _preconditionList, const uint16_t& _minValue, uint16_t& _attributeLinked)
	{
		CurrentPrecondition = _preconditionList;
		MinValue = _minValue;
		*AttributeLinked = _attributeLinked;
	}

	friend std::ostream& operator<<(std::ostream& os, const Precondition& precondition);

private:
	PreconditionList CurrentPrecondition;
	uint16_t MinValue;
	uint16_t* AttributeLinked;
};

