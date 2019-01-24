#include "Class.hpp"

Class::Class(std::string const &identifier, std::vector<Parameter> const &parameters, std::string superIdentifier, 
	std::vector<Variable> const &fields, ClassConstructor &constructor, std::vector<Method> const &methods) :
	Type(identifier, fields, constructor, methods), parameters(parameters), superIdentifier(superIdentifier) {}
	
Class::Class(Class const &other) : Type(other), parameters(other.parameters), 
	superIdentifier(other.superIdentifier) {}

Class::Class(Class &&other) : Type(other), parameters(other.parameters), 
	superIdentifier(other.superIdentifier) {}
	
Class::~Class() {}

bool Class::correctDecl(std::map<std::string, Type*> &env) const {
	if (!Type::correctDecl(env))
		return false;
	/* Vérifie si la super classe est connue... */
	if (!superIdentifier.empty()) {
		auto super = env.find(identifier);
		if (super == env.end())
			return false;
		if (!(*super).second->isInheritable())
			return false;
	}
	return false;
}
	