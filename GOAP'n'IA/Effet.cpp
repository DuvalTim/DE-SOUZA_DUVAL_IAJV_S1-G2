#include "Effet.h"

Effet::Effet(const EffetListe& _effet, uint16_t* _valueToDecrement, const uint16_t& _decrementStep)
{
	CurrentEffet = _effet;
	ValueToDecrement = _valueToDecrement;
	DecrementStep = _decrementStep;
}

void Effet::OnActionSuccess()
{
	*ValueToDecrement += DecrementStep;
	std::cout << *ValueToDecrement << std::endl;
}

std::ostream& operator<<(std::ostream& os, const Effet& effet)
{
	return os << effet.CurrentEffet;
}