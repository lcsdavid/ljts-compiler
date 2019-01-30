#include "Parameter.hpp"

Parameter::Parameter(const std::string &identifier, const std::string &typeIdentifier, bool var) : identifier(identifier),
	typeIdentifier(typeIdentifier), var(var) {}

bool operator==(Parameter const &lhs, Parameter const &rhs) {
    return lhs.identifier == rhs.identifier && lhs.typeIdentifier == rhs.typeIdentifier && lhs.var == rhs.var;
}

bool operator!=(Parameter const &lhs, Parameter const &rhs) {
    return !(lhs == rhs);
}