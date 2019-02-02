#include "Type.hpp"

Type::Type(const std::string &identifier, const std::vector<Parameter> &fields, Constructor &constructor,
	const std::vector<Method> &methods) : identifier(identifier), fields(fields), constructor(constructor),
	methods(methods) {}
	
Type::~Type() {
	delete &constructor;
}

std::ostream &operator<<(std::ostream &os, const Type &type) {
	os << (type.isStatic() ? "object " : "class ") << type.identifier 
		<< (!type.isStatic() and hasSuper() ? "extends " + super() : "") << std::endl;
	for (auto it = fields.begin(); it != fields.end(); it++)
		os << "  " << *it << std::endl;
	os << "  " << constructor;
	for (auto it = methods.begin(); it != methods.end(); it++)
		os << "  " << *it << std::endl;
	return os << std::endl;
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

NotInheritableException::NotInheritableException(const std::string& what_arg) : std::logic_error(what_arg) {}

NotInheritableException::NotInheritableException(const char* what_arg) : std::logic_error(what_arg) {}