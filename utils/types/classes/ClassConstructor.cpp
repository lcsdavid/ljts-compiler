#include "ClassConstructor.hpp"

#include <algorithm>

ClassConstructor::ClassConstructor(bool override,const std::string &identifier, const std::vector<Parameter> &parameters,
	const std::string &superIdentifier, const std::vector<Tree*> &superParameters, Block *body) : 
	Constructor(identifier, parameters, body), superIdentifier(superIdentifier), superParameters(superParameters) {}

bool ClassConstructor::correctDecl() const {
	return Constructor::correctDecl();
	/* Check si superIdentifier || superParameters ? bug track */
	/* Check correct super constructor call ? */
	/*
	for (std::string superParameter : *superParameters)  Pas de check des types.
		if (std::find_if(parameters.begin(), parameters.end(), [&](Parameter const &parameter) { return parameter.identifier == superParameter; }) != parameters.end())
			return false;*/
	return true;
}
