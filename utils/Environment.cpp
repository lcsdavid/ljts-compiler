#include "Environment.hpp"

#include "types/Type.hpp"

Environment::Environment(std::map<std::string, Type*> &env, const std::vector<Parameter> &fields) : env(env), fields(fields) {}
	
bool Environment::know(std::string type){
	if(env.find(type) != env.end())
		return true; /* On a trouvé le type que l'on cherchait. */
	return false;
}

Parameter* Environment::contains(std::string param){
	for(size_t i = 0; i < fields.size(); i++){
		if(fields.at(i).identifier == param)
			return &fields.at(i);
	}
	return nullptr;
}

bool Environment::isSubClass(std::string type1, std::string type2){
	if(env.find(type1) == env.end())
		return false; /* On a trouvé le type que l'on cherchait*/
	
	if(env.find(type1)->second->super() == "")
		return false;//pas de super classe
	
	
	/* Il y a une super classe. */
	if(env.find(type1)->second->super() ==  type2)
		return true;
		
	return isSubClass((this->env.find(type1)->second)->super(), type2);
}