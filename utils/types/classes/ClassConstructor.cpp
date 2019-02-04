#include "ClassConstructor.hpp"

#include <algorithm>

#include "../../trees/Tree.hpp"
#include "Class.hpp"

ClassConstructor::ClassConstructor(const std::string &identifier, const std::vector<Parameter> &parameters, Tree *super,
	Block *body) : Constructor(identifier, parameters, body), super(super) {}

bool ClassConstructor::isCorrectDecl(const Type &parent, Environment &env) const {
	if (!correctDecl(parent, env))
		return false;
	return std::get<Block*>(body)->isCorrect(env);
}
	
bool ClassConstructor::correctDecl(const Type &parent, const Environment &env) const {
	if (Constructor::correctDecl(parent, env))
		return false;
	if (super) {
		if (!parent.hasSuper() or parent.super() != std::get<std::string>(super.children.at(0))) {
			std::cout << "\033[91merror:\033[0m type '" << std::get<std::string>(super.children.at(0))
				<< "' is not a direct base of '" << parent.identifier << "'" << std::endl;
		}
	}
	/* Check si superIdentifier || superVariables ? bug track */
	/* Check correct super constructor call ? */
	/*
	for (std::string superVariable : *superVariables)  Pas de check des types.
		if (std::find_if(parameters.begin(), parameters.end(), [&](Variable const &parameter) { return parameter.identifier == superVariable; }) != parameters.end())
			return false;*/
	return true;
}
