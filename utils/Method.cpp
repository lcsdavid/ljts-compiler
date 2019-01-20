#include "Method.hpp"

Method::Method(std::string const &identifier, std::string const &returnTypeIdentifier, 
	std::vector<Parameter> const &parameters) : identifier(identifier), returnTypeIdentifier(returnTypeIdentifier),
	parameters(parameters) {}
	
Method operator+=(Method &lhs, Parameter const &rhs) {
	lhs.parameters.push_back(rhs);
	return lhs;
}
	
Method operator+(Method const &lhs, Parameter const &rhs) {
    lhs.parameters.push_back(rhs);
    return lhs;
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
