#include "Constructor.hpp"

Constructor::Constructor(std::string const &identifier, std::vector<Parameter> const &parameters, Block *body) : 
	Method(identifier, identifier, parameters, body) {}

Constructor::Constructor(Constructor const &other) : Method(other) {}

Constructor::Constructor(Constructor &&other) : Method(other) {}

Constructor::~Constructor() {}

Constructor &Constructor::operator=(Constructor const &other) {
	return *this = Method::operator=(other);
}

Constructor &Constructor::operator=(Constructor &&other) {
	return *this = Method::operator=(other);
}