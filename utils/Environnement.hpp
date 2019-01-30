#ifndef LJTS_COMPILER_ENVIRONNEMENT_H
#define LJTS_COMPILER_ENVIRONNEMENT_H

#include <string>
#include <vector>
#include <map>

#include "/variables/Parameter.hpp"


struct Environnemnt{
	std::map<std::string, Type*> env;
	std::vector<Parameter*> fields;
	
	Environnemnt();
	Environnemnt(std::map<std::string, Type*> &env, std::vector<Parameter*> const & fields);
	~Parameter() = default;
	
}



#endif //LJTS_COMPILER_VERIFICATIONS_H