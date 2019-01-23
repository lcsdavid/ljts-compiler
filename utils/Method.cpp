#include "Method.hpp"

#include "Block.hpp"
#include "Parameter.hpp"

Method::Method(std::string const &identifier, std::string const &returnTypeIdentifier,
	std::vector<Parameter*> const &parameters, Tree *body) : identifier(identifier), 
	returnTypeIdentifier(returnTypeIdentifier), parameters(parameters), body(body) {}

Method::Method(std::string const &identifier, std::string const &returnTypeIdentifier, 
	std::vector<Parameter*> const &parameters, Block *body) : identifier(identifier),
	returnTypeIdentifier(returnTypeIdentifier), parameters(parameters), body(body) {}

Method &Method::operator=(Method const &other) {
	identifier = other.identifier;
	returnTypeIdentifier = other.returnTypeIdentifier;
	parameters = other.parameters;
	return *this;
}
	
bool Method::correctDecl() const {
	return true;
}

Method &operator+=(Method &lhs, Parameter const &rhs) {
	lhs.parameters.push_back(new Parameter(rhs));
	return lhs;
}
	
Method operator+(Method const &lhs, Parameter const &rhs) {
    Method result = lhs;
	result.parameters.push_back(new Parameter(rhs));
    return result;
}

bool operator==(Method const &lhs, Method const &rhs) {
    if (lhs.parameters.size() != rhs.parameters.size())
        return false;
    if (lhs.identifier != rhs.identifier)
        return false;
    for (std::size_t i = 0; i < rhs.parameters.size(); i++)
        if (lhs.parameters[i] != rhs.parameters[i])
            return false;
    return true;
}
