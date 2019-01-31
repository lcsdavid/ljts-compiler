#include "Object.hpp"

Object::Object(const std::string &identifier, const std::vector<Parameter> &fields, ObjectConstructor &constructor, 
	const std::vector<Method> &methods) : Type(identifier, fields, constructor, methods) {}							 

bool Object::correctDecl(const Environment &env) const {
	return Type::correctDecl(env);
}