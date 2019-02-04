#ifndef COMPILER_CLASSCONSTRUCTOR_HPP
#define COMPILER_CLASSCONSTRUCTOR_HPP

#include "../Constructor.hpp"

struct ClassConstructor : Constructor {
	Tree *super;
	
	ClassConstructor(const std::string &identifier, const std::vector<Parameter> &parameters,
		Tree *super, Block *body);
	~ClassConstructor() override = default;
	
	ClassConstructor &operator=(const ClassConstructor &other) = default;
	ClassConstructor &operator=(ClassConstructor &&other) = default;
	
	bool isCorrect(const Type &parent, Environment &env) const override;
	bool correctDecl(const Type &parent, const Environment &env) const override;
};

#endif