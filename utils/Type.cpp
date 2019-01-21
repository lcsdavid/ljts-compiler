#include "Type.hpp"

Type::Type(std::string const &identifier, std::vector<Variable> const &fields, Constructor &constructor,
	std::vector<Method> const &methods, bool heritable) : identifier(identifier), fields(fields), constructor(constructor),
	methods(methods), isHeritable(heritable) {}
		   
bool Type::correctDecl(std::map<std::string, Type>* environnement) const {
    /* Cas où le nom de la classe est déjà pris... */
	if (environnement->find(identifier) != environnement->end())
        return false;
	
	/* Vérifie qu'on a bien passé le bon nombre d'arguments au constructeur */
	
	
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
	: Type(identifier, fields, constructor, methods, true), parameters(parameters), superClassIdentifier(superClassIdentifier) {}

bool Class::correctDecl(std::map<std::string, Type>* environnement) const {
	if (!Type::correctDecl(environnement))
		return false;
	
	
	/* Vérifie si la super classe est connue... */
	if (superClassIdentifier != nullptr){
		if (environnement->find(identifier) == environnement->end())
			return false;
		else{
			if (!(*environnement->find(identifier)).second.isHeritable)
				return false;
		}
	}
	return true;
}
	
Object::Object(std::string const &identifier, std::vector<Variable> const &fields, Constructor &constructor, 
	std::vector<Method> const &methods) : Type(identifier, fields, constructor, methods, false) {}							 

bool Object::correctDecl(std::map<std::string, Type>* environnement) const {
	return Type::correctDecl(environnement);
}