#ifndef COMPILER_CONSTRUCTOR_HPP
#define COMPILER_CONSTRUCTOR_HPP

#include "Method.hpp"

struct Constructor : Method {
    Constructor(std::string const &identifier, std::vector<Parameter> const &parameters, Block *body);
	Constructor(Constructor const &other);
	Constructor(Constructor &&other);
	~Constructor() override;
	
	Constructor &operator=(Constructor const &other);
	Constructor &operator=(Constructor &&other);
	
    //virtual bool correctDecl() const = 0;
};

#endif