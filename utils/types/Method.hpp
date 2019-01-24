#ifndef METHOD_HPP
#define METHOD_HPP

#include <string>
#include <variant>
#include <vector>

#include "../variables/Parameter.hpp"

struct Block;
struct Tree;

struct Method {
	std::string identifier;				/* Identifiant. */
	std::string returnTypeIdentifier;	/* Type de retour. */
	std::vector<Parameter> parameters;
	std::variant<Block*, Tree*> body;
	
	Method(std::string const &identifier, std::string const &returnTypeIdentifier,
		std::vector<Parameter> const &parameters, Tree *body);
	Method(std::string const &identifier, std::string const &returnTypeIdentifier,
		std::vector<Parameter> const &parameters, Block *body);
	Method(Method const &other);
	Method(Method &&other);
	virtual ~Method();
	
	Method &operator=(Method const &other);
	Method &operator=(Method &&other);
	
	virtual bool correctDecl() const;
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

struct MethodCall {
	std::string identifier;
	std::vector<std::string> parameters;
	
	MethodCall(std::string const &identifier, std::vector<Parameter> const &parameters);
};

#endif