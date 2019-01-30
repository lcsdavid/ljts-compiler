#ifndef METHOD_HPP
#define METHOD_HPP

#include <string>
#include <variant>
#include <vector>

#include "../variables/Parameter.hpp"

struct Block;
struct Tree;

struct Method {
	bool override;						/* Override? */
	std::string identifier;				/* Identifiant. */
	std::vector<Parameter> parameters;	/* Paramètre(s) de la Method [optionnel]. */
	std::string returnTypeIdentifier;	/* Type de retour. */
	std::variant<Block*, Tree*> body;	/* Corps de la Method. */
	
	Method(bool override, const std::string &identifier, const std::vector<Parameter> &parameters, 
		const std::string &returnTypeIdentifier, Tree *body);
	Method(bool override, const std::string &identifier, const std::vector<Parameter> &parameters, 
		const std::string &returnTypeIdentifier, Block *body);
	Method(const Method &other) = default;
	Method(Method &&other) = default;
	virtual ~Method() = default;
	
	Method &operator=(const Method &other) = default;
	Method &operator=(Method &&other) = default;
	
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