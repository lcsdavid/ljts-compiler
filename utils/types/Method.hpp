#ifndef COMPILER_METHOD_HPP
#define COMPILER_METHOD_HPP

#include <ostream>
#include <string>
#include <variant>
#include <vector>

#include "../Parameter.hpp"

#include "../Environment.hpp"

struct Block;
struct Tree;

struct Type;

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
	virtual ~Method() = default;
	
	virtual bool isCorrect(const Type &parent, Environment &env) const;
	virtual bool correctDecl(const Type &parent, const Environment &env) const;
	
	virtual std::ostream &print(std::ostream &os) const;
};

std::ostream &operator<<(std::ostream &os, const Method &m);

bool operator==(const Method &lhs, const Method &rhs) ;

#endif