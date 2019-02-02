#ifndef COMPILER_ENVIRONMENT_HPP
#define COMPILER_ENVIRONMENT_HPP

#include <string>
#include <vector>
#include <map>

#include "variables/Parameter.hpp"

struct Type;

struct Environment {
	std::map<std::string, Type*> env;
	std::vector<Parameter> fields;
	
	Environment();
	Environment(std::map<std::string, Type*> &env, std::vector<Parameter> const & fields);
	~Environment() = default;

	//est-ce que l'on connait le type qui est passé en parametre
	bool know(std::string type);
	
	//est-ce que la string passée en parametre correspond à un parametre connu
	Parameter* contains(std::string param);
	
	//vérifie si le type numéro 1 est sous type du type numero 2
	bool isSubClass(std::string type1, std::string type2);
	
};

#endif