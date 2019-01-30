#include "Constructor.hpp"

Constructor::Constructor(const std::string &identifier, const std::vector<Parameter> &parameters, Block *body) : 
	Method(false, identifier, parameters, identifier, body) {}