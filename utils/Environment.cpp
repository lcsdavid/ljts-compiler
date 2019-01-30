#include "Environment.hpp"

Environment::Environnemnt(std::map<std::string, Type*> &env, std::vector<Parameter*> const & fields) : env(env),
	fields(fields) {}
	
	
bool Environment::know(std::string type){
	if(this->env.find(type) != env.end())
		return true;//on a trouvé le type que l'on cherchait
	
	return false;
	
}

Parameter* Environment::contains(std::string param){
	for(size_t i = 0; i < this->fields.size(); i++){
		if(fields.at(i)->identifier == param)
			return fields.at(i);
	}
	return nullptr;
}