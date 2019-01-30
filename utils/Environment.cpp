#include "Environment.hpp"

Environment::Environnemnt(std::map<std::string, Type*> &env, std::vector<Parameter*> const & fields) : env(env),
	fields(fields) {}