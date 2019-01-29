#include "Object.hpp"

Object::Object(std::string const &identifier, std::vector<Parameter> const &fields, ObjectConstructor &constructor, 
	std::vector<Method> const &methods) : Type(identifier, fields, constructor, methods) {}							 

Object::Object(Object const &other) : Type(other) {}	
	
Object::Object(Object &&other) : Type(other) {}

Object::~Object() {}

bool Object::correctDecl(std::map<std::string, Type*> &env) const {
	return Type::correctDecl(env);
}