#include "Variable.hpp"

Variable::Variable(std::string const &identifier, std::string const &typeIdentifier) : identifier(identifier),
	typeIdentifier(typeIdentifier) {}
	
bool operator==(Variable const &lhs, Variable const &rhs) {
	return lhs.identifier == rhs.identifier && lhs.typeIdentifier == rhs.typeIdentifier;
}