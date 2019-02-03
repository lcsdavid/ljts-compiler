#include "Object.hpp"

Object::Object(const std::string &identifier, const std::vector<Variable> &fields, ObjectConstructor &constructor, 
	const std::vector<Method> &methods) : Type(identifier, fields, constructor, methods) {}							 

std::ostream &Object::print(std::ostream &os) const {
	os << "object " << identifier << std::endl;
	for (auto it = fields.cbegin(); it != fields.cend(); it++)
		os << "  " << *it << std::endl;
	os << "  " << constructor;
	for (auto it = methods.cbegin(); it != methods.cend(); it++)
		os << "  " << *it << std::endl;
	return os;
}

std::ostream &operator<<(std::ostream &os, const Object &o) {
	return o.print(os);
}