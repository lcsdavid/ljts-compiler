#include "Object.hpp"

Object::Object(std::string const &identifier, std::vector<Parameter> const &fields, ObjectConstructor &constructor, 
	std::vector<Method> const &methods) : Type(identifier, fields, constructor, methods) {}							 

bool Object::correctDecl(Environment env) const {
	return Type::correctDecl(env);
}