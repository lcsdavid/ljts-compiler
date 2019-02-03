#include "ClassConstructor.hpp"

#include <algorithm>

#include "Class.hpp"

ClassConstructor::ClassConstructor(const std::string &identifier, const std::vector<Parameter> &parameters,
	const std::string &superIdentifier, const std::vector<Tree*> &superVariables, Block *body) : 
	Constructor(identifier, parameters, body), superIdentifier(superIdentifier), superVariables(superVariables) {}

bool ClassConstructor::correctDecl(const Type &parent, const Environment &env) const {
	return Constructor::correctDecl(parent, env);
	/* Check si superIdentifier || superVariables ? bug track */
	/* Check correct super constructor call ? */
	/*
	for (std::string superVariable : *superVariables)  Pas de check des types.
		if (std::find_if(parameters.begin(), parameters.end(), [&](Variable const &parameter) { return parameter.identifier == superVariable; }) != parameters.end())
			return false;*/
	return true;
}
