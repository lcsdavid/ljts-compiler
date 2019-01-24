#ifndef COMPILER_OBJECT_HPP
#define COMPILER_OBJECT_HPP

#include "../Type.hpp"

struct Object : Type {
	Object(std::string const &identifier, std::vector<Variable> const &fields, Constructor &constructor,
		std::vector<Method> const &methods);
	Object(Object const &other);
	Object(Object &&other);
	~Object() override;
	
	bool isInheritable() const override {
		return false;
	}
		
	bool correctDecl(std::map<std::string, Type*> &env) const override;
};

#endif