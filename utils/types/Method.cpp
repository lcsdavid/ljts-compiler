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

std::ostream &operator<<(std::ostream &os, const Method &m) {
	os << m.identifier << '(';
	for (auto it = m.parameters.begin(); it != m.parameters.end(); it++) {
		os << *it;
		if (it != m.parameters.end() - 1)
			os << ", ";
	}
	return os << ')' <<(m.returnTypeIdentifier.empty() ? "" : " : ") << m.returnTypeIdentifier;
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