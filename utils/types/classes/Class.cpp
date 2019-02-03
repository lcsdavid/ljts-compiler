#include "Class.hpp"

Class::Class(const std::string &identifier, const std::vector<Parameter> &parameters, const std::string &superIdentifier, 
	const std::vector<Variable> &fields, ClassConstructor &constructor, const std::vector<Method> &methods) :
	Type(identifier, fields, constructor, methods), parameters(parameters), superIdentifier(superIdentifier) {}

bool Class::correctDecl(const Environment &env) const {
	if (!Type::correctDecl(env))
		return false;
	/* Si la class a une super class. */
	if (hasSuper()) {
		auto super = env.env.find(superIdentifier);
		/* Vérifie si la super class est connue. */
		if (super == env.env.end()) {
			std::cout << "\033[91merreur:\033[0m utilisation invalide d'un type non déclaré '" << superIdentifier << '\'' << std::endl;
			return false;
		}
		/* Si la super class est un type static. */
		if (!(*super).second->isStatic()) { 
			std::cout << "\033[91merreur:\033[0m héritage impossible depuis un type statique '" << identifier << '\'' << std::endl;
			return false;
		}
	}

	/* Vérifie qu'il ni a pas d'héritage circulaire. */
	//if (env.isSubClass(identifier, identifier))
		//return false;
	
	return true;
}