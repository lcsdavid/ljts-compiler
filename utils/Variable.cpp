#include "Variable.hpp"

#include "trees/Tree.hpp"

Variable::Variable(const std::string &identifier, const std::string &typeIdentifier, Tree *initialization) : identifier(identifier),
	typeIdentifier(typeIdentifier), initialization(initialization) {}

std::ostream &operator<<(std::ostream &os, const Variable &v) {
	return os << "var " << v.identifier << " : " << v.typeIdentifier;
	if (v.initialization)
		os << " := " << *v.initialization;
}
	
/*
bool operator==(Variable const &lhs, Variable const &rhs) {
    return lhs.identifier == rhs.identifier && lhs.typeIdentifier == rhs.typeIdentifier && lhs.var == rhs.var;
}

bool operator!=(Variable const &lhs, Variable const &rhs) {
    return !(lhs == rhs);
}
*/