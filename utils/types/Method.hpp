#ifndef COMPILER_METHOD_HPP
#define COMPILER_METHOD_HPP

#include <string>
#include <variant>
#include <vector>

#include "../Variable.hpp"

#include "../Environment.hpp"

struct Block;
struct Tree;

struct Type;

struct Method {
	bool override;						/* Override? */
	std::string identifier;				/* Identifiant. */
	std::vector<Variable> parameters;	/* Paramètre(s) de la Method [optionnel]. */
	std::string returnTypeIdentifier;	/* Type de retour. */
	std::variant<Block*, Tree*> body;	/* Corps de la Method. */
	
	Method(bool override, const std::string &identifier, const std::vector<Variable> &parameters, 
		const std::string &returnTypeIdentifier, Tree *body);
	Method(bool override, const std::string &identifier, const std::vector<Variable> &parameters, 
		const std::string &returnTypeIdentifier, Block *body);
	Method(const Method &other) = default;
	Method(Method &&other) = default;
	virtual ~Method() = default;
	
	
	Method &operator=(const Method &other) = default;
	Method &operator=(Method &&other) = default;
	
	virtual bool correctDecl(const Type &parent, const Environment &env) const;
	virtual bool correctDef(const Type &parent, const Environment &env) const;
};

/**
 * Surchage de l'opérateur de flux de sortie.
 */
std::ostream &operator<<(std::ostream &os, const Method &m);

Method &operator+=(Method &lhs, const Variable &rhs);

/**
 * Surcharge de '+' entre Method et Variable.
 * Ajout d'un Variable sur une Method.
 */
Method operator+(const Method &lhs, const Variable &rhs);

/** 
 * Surcharge de '==' pour les Method.
 */
bool operator ==(const Method &lhs, const Method &rhs);

#endif