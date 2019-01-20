#include "Type.hpp"

Type::Type(std::string const &identifier, std::vector<Variable> const &fields, Constructor &constructor,
	std::vector<Method> const &methods) : identifier(identifier), fields(fields), constructor(constructor),
	methods(methods) {}
		   
bool Type::correctDecl(/*std::map<std::string, Type>* environnement*/) const {
    /* Cas où le nom de la classe est déjà pris... */
	/* if (environnement->find(identifier) != environnement.end())
        return false; */
	
	/* Vérifie la validité du constructeur... */
	if (!constructor.correctDecl())
		return false;
	
	/* Vérifie la validité des méthodes... */
	for (Method const &method : methods)
		if (!method.correctDecl())
			return false;

    return true;
}

Class::Class(std::string const &identifier, std::vector<Parameter> const &parameters, std::string *superClassIdentifier, 
	std::vector<Variable> const &fields, ClassConstructor &constructor, std::vector<Method> const &methods) 
	: Type(identifier, fields, constructor, methods), parameters(parameters), superClassIdentifier(superClassIdentifier) {}

bool Class::correctDecl() const {
	if (!Type::correctDecl())
		return false;
	
	/* Vérifie si la super classe est connue... */
	/* if (superClassIdentifier != nullptr)
		if (environnement->find(identifier) != environnement.end())
			return false; */
	
	return true;
}
	
Object::Object(std::string const &identifier, std::vector<Variable> const &fields, Constructor &constructor, 
	std::vector<Method> const &methods) : Type(identifier, fields, constructor, methods) {}							 

bool Object::correctDecl() const {
	return Type::correctDecl();
}