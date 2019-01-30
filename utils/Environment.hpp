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
}



#endif //LJTS_COMPILER_VERIFICATIONS_H