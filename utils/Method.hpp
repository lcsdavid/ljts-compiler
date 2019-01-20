#ifndef METHOD_HPP
#define METHOD_HPP

struct Method {
	std::string identifier;
	std::string returnTypeIdentifier;
	std::vector<Parameter> parameters;
	// Tree instructions;
	
	Method(std::string const &identifier, std::string const &returnTypeIdentifier,
		std::vector<Parameter> const &parameters);
};

