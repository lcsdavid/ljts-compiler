#include "Constructor.hpp"

Constructor::Constructor(const std::string &identifier, const std::vector<Parameter> &parameters, Block *body) : 
	Method(identifier, identifier, parameters, body) {}