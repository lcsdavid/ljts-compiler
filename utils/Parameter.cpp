#include "Parameter.hpp"

Parameter::Parameter(bool var, const std::string &identifier, const std::string &typeIdentifier) : var(var),
	identifier(identifier), typeIdentifier(typeIdentifier) {}

std::ostream &operator<<(std::ostream &os, const Parameter &p) {
	if (p.var)
		os << "var ";
	return os << p.identifier << " : " << p.typeIdentifier;
}