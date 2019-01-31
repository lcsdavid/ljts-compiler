#ifndef COMPILER_OBJECTCONSTRUCTOR_HPP
#define COMPILER_OBJECTCONSTRUCTOR_HPP

#include "../Constructor.hpp"

struct ObjectConstructor : Constructor {
	ObjectConstructor(std::string const &identifier, Block *body);
	ObjectConstructor(ObjectConstructor const &other) = default;
	ObjectConstructor(ObjectConstructor &&other) = default;
	~ObjectConstructor() override = default;
	
	ObjectConstructor &operator=(ObjectConstructor const &other) = default;
	ObjectConstructor &operator=(ObjectConstructor &&other) = default;
	
	bool correctDecl(const Environment &env) const override {
		return true;
	}
};

#endif