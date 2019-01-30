#ifndef COMPILER_ENVIRONMENT_H
#define COMPILER_ENVIRONMENT_H

#include <string>
#include <vector>
#include <map>

#include "variables/Parameter.hpp"

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



#endif //LJTS_COMPILER_VERIFICATIONS_H