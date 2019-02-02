#ifndef COMPILER_CONSTRUCTOR_HPP
#define COMPILER_CONSTRUCTOR_HPP

#include "Method.hpp"

struct Constructor : Method {
    Constructor(const std::string &identifier, const std::vector<Variable> &parameters, Block *body);
	Constructor(const Constructor &other) = default;
	Constructor(Constructor &&other) = default;
	~Constructor() override = default;
	
	Constructor &operator=(const Constructor  &other) = default;
	Constructor &operator=(Constructor &&other) = default;
	
    bool correctDecl(const Environment &env) const override;
};

std::ostream &operator<<(std::ostream &os, const Constructor &c);

#endif