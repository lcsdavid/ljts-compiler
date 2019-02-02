#include "Variable.hpp"

Variable::Variable(const std::string &identifier, const std::string &typeIdentifier, bool var) : identifier(identifier),
	typeIdentifier(typeIdentifier), var(var) {}

std::ostream &operator<<(std::ostream &os, const Variable &parameter) {
	os << "var" << parameter.typeIdentifier << " " << parameter.identifier;
}
	
bool operator==(Variable const &lhs, Variable const &rhs) {
    return lhs.identifier == rhs.identifier && lhs.typeIdentifier == rhs.typeIdentifier && lhs.var == rhs.var;
}

bool operator!=(Variable const &lhs, Variable const &rhs) {
    return !(lhs == rhs);
}