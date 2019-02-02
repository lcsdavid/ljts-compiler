#include "ObjectConstructor.hpp"

ObjectConstructor::ObjectConstructor(std::string const &identifier, Block *body) : Constructor(identifier, 
	std::vector<Variable>(), body) {}