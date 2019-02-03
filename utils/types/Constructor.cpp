#include "Constructor.hpp"

#include "Type.hpp"

Constructor::Constructor(const std::string &identifier, const std::vector<Parameter> &parameters, Block *body) : 
	Method(false, identifier, parameters, identifier, body) {}

bool Constructor::correctDecl(const Type &parent, const Environment &env) const {
	return Method::correctDecl(parent, env);
}

std::ostream &Constructor::print(std::ostream &os) const {
	os << identifier << '(';
	for (auto it = parameters.cbegin(); it != parameters.cend(); it++) {
		os << *it;
		if (it != parameters.cend() - 1)
			os << ", ";
	}
	return os << ')' << std::endl;
}

std::ostream &operator<<(std::ostream &os, const Constructor &c) {
	return c.print(os);
}

