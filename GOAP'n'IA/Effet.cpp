#include "Effet.h"


std::ostream& operator<<(std::ostream& os, const Effet& effet)
{
	return os << effet.CurrentEffet;
}