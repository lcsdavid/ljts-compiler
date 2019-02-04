#include "ClassConstructor.hpp"

#include <algorithm>

#include "../../trees/Tree.hpp"
#include "../../trees/Block.hpp"
#include "Class.hpp"

ClassConstructor::ClassConstructor(const std::string &identifier, const std::vector<Parameter> &parameters, Tree *super,
	Block *body) : Constructor(identifier, parameters, body), super(super) {}

bool ClassConstructor::isCorrect(const Type &parent, Environment &env) const {
	if (!correctDecl(parent, env))
		return false;
	return std::get<Block*>(body)->isCorrect(env);
}
	
bool ClassConstructor::correctDecl(const Type &parent, const Environment &env) const {
	if (Constructor::correctDecl(parent, env))
		return false;
	if (super) {
		if (!parent.hasSuper() or parent.super() != std::get<std::string>(super->children.at(0))) {
			std::cout << "\033[91merror:\033[0m type '" << std::get<std::string>(super->children.at(0))
				<< "' is not a direct base of '" << parent.identifier << "'" << std::endl;
		}
	}
	return true;
}
