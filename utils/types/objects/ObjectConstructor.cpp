#include "ObjectConstructor.hpp"

ObjectConstructor::ObjectConstructor(std::string const &identifier, Block *body) : Constructor(identifier, 
	std::vector<Parameter>(), body) {}
	
ObjectConstructor::ObjectConstructor(ObjectConstructor const &other) : Constructor(other) {}

ObjectConstructor::ObjectConstructor(ObjectConstructor &&other) : Constructor(other) {}

ObjectConstructor::~ObjectConstructor() {}

ObjectConstructor &ObjectConstructor::operator=(ObjectConstructor const &other) {
	return *this = Constructor::operator=(other);
}

ObjectConstructor &ObjectConstructor::operator=(ObjectConstructor &&other) {
	return *this = Constructor::operator=(other);
}