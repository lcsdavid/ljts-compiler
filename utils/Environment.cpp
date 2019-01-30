#include "Environment.hpp"

#include "types/Type.hpp"

Environment::Environment(std::map<std::string, Type*> &env, std::vector<Parameter> const & fields) : env(env),	fields(fields) {}
	
	
bool Environment::know(std::string type){
	if(this->env.find(type) != env.end())
		return true;//on a trouvé le type que l'on cherchait
	
	return false;
	
}

Parameter* Environment::contains(std::string param){
	for(size_t i = 0; i < this->fields.size(); i++){
		if(fields.at(i).identifier == param)
			return &fields.at(i);
	}
	return nullptr;
}

bool Environment::isSubClass(std::string type1, std::string type2){
	if(this->env.find(type1) == env.end())
		return false;//on a trouvé le type que l'on cherchait
	
	if((this->env.find(type1)->second)->getSuperClass() == "")
		return false;//pas de super classe
	
	
	//il y a une super classe
	if((this->env.find(type1)->second)->getSuperClass() ==  type2)
		return true;
		
	return isSubClass((this->env.find(type1)->second)->getSuperClass(), type2);
}