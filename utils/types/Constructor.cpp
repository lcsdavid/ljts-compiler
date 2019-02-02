#include "Constructor.hpp"

#include "Type.hpp"

Constructor::Constructor(const std::string &identifier, const std::vector<Variable> &parameters, Block *body) : 
	Method(false, identifier, parameters, identifier, body) {}
	
std::ostream &operator<<(std::ostream &os, const Constructor &c) {
	os << c.identifier << '(';
	for (auto it = c.parameters.begin(); it != c.parameters.end(); it++) {
		os << *it;
		if (it != c.parameters.end() - 1)
			os << ", ";
	}
	return os << ')' << std::endl;
}
	
bool Constructor::correctDecl(const Type &parent, const Environment &env) const {
	return Method::correctDecl(parent, env);
}