#include "Variable.hpp"

Variable::Variable(std::string const &identifier, std::string const &typeIdentifier) : identifier(identifier),
	typeIdentifier(typeIdentifier);
	
Parameter::Parameter(std::string const &identifier, std::string const &typeIdentifier, bool var = false);