#ifndef COMPILER_OBJECTCONSTRUCTOR_HPP
#define COMPILER_OBJECTCONSTRUCTOR_HPP

#include "../Constructor.hpp"

struct ObjectConstructor : Constructor {
	ObjectConstructor(std::string const &identifier, Block *body);
	~ObjectConstructor() override = default;
	
};

#endif