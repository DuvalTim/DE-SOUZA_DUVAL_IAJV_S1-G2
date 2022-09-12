#include "Precondition.h"



std::ostream& operator<<(std::ostream& os, const Precondition& precondition)
{
	return os << precondition.CurrentPrecondition;
}