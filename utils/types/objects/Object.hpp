#ifndef COMPILER_OBJECT_HPP
#define COMPILER_OBJECT_HPP

#include "../Type.hpp"
#include "ObjectConstructor.hpp"

struct Object : Type {
	Object(std::string const &identifier, std::vector<Parameter> const &fields, ObjectConstructor &constructor,
		std::vector<Method> const &methods);
	Object(Object const &other);
	Object(Object &&other);
	~Object() override;
	
	bool isInheritable() const override {
		return false;
	}
	
	bool isDuplicable() const override{
		return false;
	}
		
	bool correctDecl(Environment env) const override;
};

#endif