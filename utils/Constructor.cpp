#include "Constructor.hpp"

Constructor::Constructor(std::string const &identifier, std::vector<Parameter> const &parameters) 
	: identifier(identifier), parameters(parameters) {}

Constructor::isCorrect() { /* Dans le cas d'un objet classique. */
	return true;
}
	
ClassConstructor(std::string const &identifier, std::vector<Parameter> const &parameters,
	std::string *superIdentifier, std::vector<std::string> *superParameters) : identifier(identifier),
	parameters(parameters), superIdentifier(superIdentifier), superParameters(superParameters) {}
	
bool ClassConstructor::isCorrect() { /* Dans le cas d'un constructeur de classe. */
    if (superIdentifier == nullptr)
		return Constructor::isCorrect();
	/* Check si superIdentifier || superParameters ? bug track */
	/* Check correct super constructor call ? */
	
	for (std::string superParam : *superParameters) /* Pas de check des types. */
		if (std::find(parameters.begin(), parameters.end(), [=](auto param) { return superParam == param.identifier; }) != parameters.end())
			return false;
	return paramaters == superConstructor->parameters;
}
