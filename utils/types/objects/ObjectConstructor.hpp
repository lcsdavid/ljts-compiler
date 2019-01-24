#ifndef COMPILER_OBJECTCONSTRUCTOR_HPP
#define COMPILER_OBJECTCONSTRUCTOR_HPP

#include "../Constructor.hpp"

struct ObjectConstructor : Constructor {
	ObjectConstructor(std::string const &identifier, Block *body);
	ObjectConstructor(ObjectConstructor const &other);
	ObjectConstructor(ObjectConstructor &&other);
	~ObjectConstructor() override;
	
	bool correctDecl() const override {
		return true;
	}
};

#endif