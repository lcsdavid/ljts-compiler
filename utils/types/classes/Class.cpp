#include "Class.hpp"

Class::Class(const std::string &identifier, const std::vector<Parameter> &parameters, const std::string &superIdentifier, 
	const std::vector<Parameter> &fields, ClassConstructor &constructor, const std::vector<Method> &methods) :
	Type(identifier, fields, constructor, methods), parameters(parameters), superIdentifier(superIdentifier) {}

bool Class::correctDecl(Environment env) const {
	if (!Type::correctDecl(env))
		return false;
	/* Vérifie si la super classe est connue... */
	if (!superIdentifier.empty()) {
		auto super = env.env.find(identifier);
		if (super == env.env.end())
			return false;
		if (!(*super).second->isInheritable())
			return false;
	}
	return true;
}
	
std::string Class::getSuperClass(){
	return superIdentifier;	
}