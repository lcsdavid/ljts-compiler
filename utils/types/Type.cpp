#include "Type.hpp"

Type::Type(const std::string &identifier, const std::vector<Variable> &fields, Constructor &constructor,
	const std::vector<Method> &methods) : identifier(identifier), fields(fields), constructor(constructor),
	methods(methods) {}
	
Type::~Type() {
	delete &constructor;
}

std::ostream &operator<<(std::ostream &os, const Type &type) {
	os << (type.isStatic() ? "object " : "class ") << type.identifier 
		<< (!type.isStatic() and type.hasSuper() ? "extends " + type.super() : "") << std::endl;
	/*
	for (auto it = type.fields.begin(); it != type.fields.end(); it++)
		os << "  " << *it << std::endl;
	os << "  " << type.constructor;
	for (auto it = type.methods.begin(); it != type.methods.end(); it++)
		os << "  " << *it << std::endl;
	*/
	return os << std::endl;
}
	
bool Type::correctDecl(const Environment &env) const {
    /* Cas où le nom de la classe est déjà pris. */
	if (env.env.find(identifier) != env.env.end()) {
		std::cout << "\033[91merreur:\033[0m redéfinition de '" << identifier << '\'' << std::endl;
        return false;
	}
	/* Vérifie la validité du constructeur. */
	if (!constructor.correctDecl(*this, env))
		return false;
	/* Vérifie la validité des méthodes. */
	for (const Method &method : methods)
		if (!method.correctDecl(*this, env))
			return false;
	
	/* ??? */
	/* On ajoute les variables au scope si elles existent, sinon on retourne une erreur. */
	/*for(size_t i; i<parameters.size; i++){
		if(env.env.find(parameters.at(i).identifier) == env.env.end)
			return false;
		env.fields.push_back(parameters.at(i);
	}
	
	//en sortie de la classe on supprimer les variables locales
	for(size_t i; i<parameters.size(); i++){
		env.fields.pop_back();
	}*/
	
	// env.env[this->typename] = this;
	
	return true;
}
