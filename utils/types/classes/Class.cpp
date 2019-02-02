#include "Class.hpp"

Class::Class(const std::string &identifier, const std::vector<Variable> &parameters, const std::string &superIdentifier, 
	const std::vector<Variable> &fields, ClassConstructor &constructor, const std::vector<Method> &methods) :
	Type(identifier, fields, constructor, methods), parameters(parameters), superIdentifier(superIdentifier) {}

bool Class::correctDecl(const Environment &env) const {
	if (!Type::correctDecl(env))
		return false;
	/* Vérifie si la super classe est connue... */
	if (!superIdentifier.empty()) {
		auto super = env.env.find(superIdentifier);
		if (super == env.env.end())
			return false;
		if (!(*super).second->isInheritable())
			return false;
	}
	
	//on vérifie qu'il ni a pas d'héritage circulaire
	if(env.isSubClass(this->typename, this->typename)
		return false;
	
	return true;
}