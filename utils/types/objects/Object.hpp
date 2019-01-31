#ifndef COMPILER_OBJECT_HPP
#define COMPILER_OBJECT_HPP

#include "../Type.hpp"
#include "ObjectConstructor.hpp"

struct Object : Type {
	Object(const std::string &identifier, const std::vector<Parameter> &fields, ObjectConstructor &constructor,
		const std::vector<Method> &methods);
	Object(const Object &other) = default;
	Object(Object &&other) = default;
	~Object() override = default;
	
	bool isInheritable() const override {
		return false;
	}
	
	bool isDuplicable() const override {
		return false;
	}
		
	bool correctDecl(Environment env) const override;
};

#endif