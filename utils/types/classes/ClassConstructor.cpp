#include "ClassConstructor.hpp"

#include <algorithm>

#include "Class.hpp"

ClassConstructor::ClassConstructor(const std::string &identifier, const std::vector<Parameter> &parameters,
	const std::string &superIdentifier, const std::vector<Tree*> &superVariables, Block *body) : 
	Constructor(identifier, parameters, body), superIdentifier(superIdentifier), superVariables(superVariables) {}

bool ClassConstructor::isCorrect(const Class &parent, Environment &env) const {
	if (!correctDecl(parent, env))
		return false;
	return std::get<Block*>(body)->isCorrect(env);
}
	
bool ClassConstructor::correctDecl(const Type &parent, const Environment &env) const {
	if (Constructor::correctDecl(parent, env))
		return false;
	/* Check si superIdentifier || superVariables ? bug track */
	/* Check correct super constructor call ? */
	/*
	for (std::string superVariable : *superVariables)  Pas de check des types.
		if (std::find_if(parameters.begin(), parameters.end(), [&](Variable const &parameter) { return parameter.identifier == superVariable; }) != parameters.end())
			return false;*/
	return true;
}
