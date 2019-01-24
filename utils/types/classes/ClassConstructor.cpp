#include "ClassConstructor.hpp"

#include <algorithm>

ClassConstructor::ClassConstructor(std::string const &identifier, std::vector<Parameter> const &parameters, Block *body,
	std::string *superIdentifier, std::vector<std::string> *superParameters) : Constructor(identifier, parameters, body),
	superIdentifier(superIdentifier), superParameters(superParameters) {}

ClassConstructor::ClassConstructor(ClassConstructor const &other) : Constructor(other), superIdentifier(other.superIdentifier),
	superParameters(other.superParameters) {}
	
ClassConstructor::ClassConstructor(ClassConstructor &&other) : Constructor(other), superIdentifier(other.superIdentifier),
	superParameters(other.superParameters) {}
	
ClassConstructor::~ClassConstructor() {
	delete superIdentifier;
	delete superParameters;
}
	
bool ClassConstructor::correctDecl() const {
    if (superIdentifier == nullptr)
		return Constructor::correctDecl();
	/* Check si superIdentifier || superParameters ? bug track */
	/* Check correct super constructor call ? */
	
	for (std::string superParameter : *superParameters) /* Pas de check des types. */
		if (std::find_if(parameters.begin(), parameters.end(), [&](Parameter const &parameter) { return parameter.identifier == superParameter; }) != parameters.end())
			return false;
	return true;
}
