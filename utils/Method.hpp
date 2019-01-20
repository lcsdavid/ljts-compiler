#ifndef METHOD_HPP
#define METHOD_HPP

#include <vector>

#include "Parameter.hpp"

struct Method {
	std::string identifier;
	std::string returnTypeIdentifier;
	std::vector<Parameter> parameters;
	// Tree instructions;
	
	Method(std::string const &identifier, std::string const &returnTypeIdentifier,
		std::vector<Parameter> const &parameters);
	
	Method &operator=(Method const &other);
	
	bool correctDecl() const;
};

Method &operator+=(Method &lhs, Parameter const &rhs);

/**
 * Surcharge de '+' entre Method et Parameter.
 * Ajout d'un Parameter sur une Method.
 */
Method operator+(Method const &lhs, Parameter const &rhs);

/** 
 * Surcharge de '==' pour les Method.
 */
bool operator ==(Method const &lhs, Method const &rhs);

#endif