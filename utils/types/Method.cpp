#include "Method.hpp"

#include "../trees/Block.hpp"
#include "../trees/Tree.hpp"

#include "Type.hpp"

Method::Method(bool override, const std::string &identifier, const std::vector<Parameter> &parameters, 
	const std::string &returnTypeIdentifier, Tree *body) : override(override), identifier(identifier), 
	parameters(parameters), returnTypeIdentifier(returnTypeIdentifier), body(body) {}

Method::Method(bool override, const std::string &identifier, const std::vector<Parameter> &parameters, 
	const std::string &returnTypeIdentifier, Block *body) : override(override), identifier(identifier), 
	parameters(parameters), returnTypeIdentifier(returnTypeIdentifier), body(body) {}

bool Method::correctDecl(const Type &parent, const Environment &env) const {
	return true;
}

bool Method::correctDef(const Type &parent, const Environment &env) const {
	
}

std::ostream &Method::print(std::ostream &os) const {
	if (override)
		os << "override ";
	os << identifier << '(';
	for (auto it = parameters.cbegin(); it != parameters.cend(); it++) {
		os << *it;
		if (it != parameters.cend() - 1)
			os << ", ";
	}
	os << ')';
	if (!returnTypeIdentifier.empty())
		os << " : " << returnTypeIdentifier;
	return os;
}

std::ostream &operator<<(std::ostream &os, const Method &m) {
	return m.print(os);
}

/*
Method &operator+=(Method &lhs, const Variable &rhs) {
	lhs.parameters.push_back(rhs);
	return lhs;
}
	
Method operator+(const Method &lhs, const Variable &rhs) {
    Method result = lhs;
	result.parameters.push_back(rhs);
    return result;
}

bool operator==(const Method &lhs, const Method &rhs) {
    if (lhs.parameters.size() != rhs.parameters.size())
        return false;
    if (lhs.identifier != rhs.identifier)
        return false;
    for (std::size_t i = 0; i < rhs.parameters.size(); i++)
        if (lhs.parameters[i] != rhs.parameters[i])
            return false;
    return true;
}
*/