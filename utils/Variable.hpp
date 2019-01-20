#ifndef LJTS_COMPILER_VARIABLE_HPP
#define LJTS_COMPILER_VARIABLE_HPP

#include <string>

struct Variable {
	std::string identifier;
	std::string typeIdentifier;
	
	Variable(std::string const &identifier, std::string const &typeIdentifier);
};

bool operator==(Variable const &lhs, Variable const &rhs);

#endif