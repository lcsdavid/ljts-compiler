#include "Method.hpp"

Method::Method(std::string const &identifier, std::string const &returnTypeIdentifier, 
	std::vector<Parameter> const &parameters) : identifier(identifier), returnTypeIdentifier(returnTypeIdentifier),
	parameters(parameters) {}