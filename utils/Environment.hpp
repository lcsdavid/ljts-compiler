#ifndef COMPILER_ENVIRONMENT_HPP
#define COMPILER_ENVIRONMENT_HPP

#include <string>
#include <vector>
#include <map>

#include "Variable.hpp"

struct Type;

struct Environment {
	std::map<std::string, Type*> env;
	std::vector<Variable> fields;
	
	Environment() = default;
	Environment(std::map<std::string, Type*> &env, std::vector<Variable> const & fields);
	~Environment() = default;

	//est-ce que l'on connait le type qui est passé en parametre
	bool know(std::string type);
	
	//est-ce que la string passée en parametre correspond à un parametre connu
	Variable* contains(std::string param);
	
	//vérifie si le type numéro 1 est sous type du type numero 2
	bool isSubClass(std::string type1, std::string type2);
	
};

#endif