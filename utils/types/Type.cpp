#include "Type.hpp"

Type::Type(const std::string &identifier, const std::vector<Parameter> &fields, Constructor &constructor,
	const std::vector<Method> &methods) : identifier(identifier), fields(fields), constructor(constructor),
	methods(methods) {}
	
Type::~Type() {
	delete &constructor;
}
	
bool Type::correctDecl(const Environment &env) const {
    /* Cas où le nom de la classe est déjà pris. */
	if (env.env.find(identifier) != env.env.end())
        return false;
	/* Vérifie la validité du constructeur. */
	/*if(this->fields != constructor.parameters)//si les paramètres de la classe et du constructeur ne sont pas les mêmes
		return false;*/
	if (!constructor.correctDecl(env))
		return false;
	/* Vérifie la validité des méthodes. */
	for (Method const &method : methods)
		if (!method.correctDecl(env))
			return false;
    return true;
}

std::string Type::getSuperClass() {
	return "";
}