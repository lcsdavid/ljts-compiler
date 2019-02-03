#include "Constructor.hpp"

#include "../trees/Block.hpp"
#include "Type.hpp"


Constructor::Constructor(const std::string &identifier, const std::vector<Parameter> &parameters, Block *body) : 
	Method(false, identifier, parameters, identifier, body) {}

bool Constructor::isCorrect(const Type &parent, Environment &env) const {
	if (!correctDecl(parent, env))
		return false;
	return std::get<Block*>(body)->isCorrect(env);
}
	
bool Constructor::correctDecl(const Type &parent, const Environment &env) const {
	if (Method::correctDecl(parent, env))
		return false;
	if (identifier != parent.identifier) {
		std::cout << "\033[91merror:\033[0m '" << parent.identifier << "::" << *this 
			<< "' invalid name for constructor method" << std::endl
			<< "\033[96mnote:\033[0m try '" << parent.identifier << "::" << *this 
			<< "' name for constructor method" << std::endl;
		return false;
	}
	return true;
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

