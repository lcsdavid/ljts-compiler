#include "Constructor.hpp"

#include <algorithm>

Constructor::Constructor(std::string const &identifier, std::vector<Parameter> const &parameters) 
	: identifier(identifier), parameters(parameters) {}

Constructor::Constructor(Constructor const &other) : identifier(other.identifier), parameters(other.parameters) {}
	
bool Constructor::correctDecl() const { /* Dans le cas d'un objet classique. */
	return true;
}
	
ClassConstructor::ClassConstructor(std::string const &identifier, std::vector<Parameter> const &parameters,
	std::string *superIdentifier, std::vector<std::string> *superParameters) : Constructor(identifier, parameters),
	superIdentifier(superIdentifier), superParameters(superParameters) {}
	
bool ClassConstructor::correctDecl() const { /* Dans le cas d'un constructeur de classe. */
    if (superIdentifier == nullptr)
		return Constructor::correctDecl();
	/* Check si superIdentifier || superParameters ? bug track */
	/* Check correct super constructor call ? */
	
	for (std::string superParameter : *superParameters) /* Pas de check des types. */
		if (std::find_if(parameters.begin(), parameters.end(), [&](Parameter const &parameter) { return parameter.identifier == superParameter; }) != parameters.end())
			return false;
	return true;
}
