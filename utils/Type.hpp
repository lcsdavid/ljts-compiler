#ifndef COMPILER_TYPE_HPP
#define COMPILER_TYPE_HPP

#include <vector>

#include "Constructor.hpp"
#include "Parameter.hpp"

struct Field;
struct Method;

struct Type {
	std::string identifier;       /* Identifiant de la classe. */
	std::vector<Field*> fields;   /* Liste de champs de la classe. */
	Constructor constructor;      /* Constructeur de la classe. */
	std::vector<Method*> methods; /* Liste de méthodes de la classe. */
    
    Type(std::string const &identifier, std::vector<Field*> const &fields, Constructor const &constructor,
        std::vector<Method*> const &methods);
};

struct Class : Type  {
	std::vector<Parameter*> parameters; /* Liste de paramètres de la classe. */
	std::string *superClassIdentifier;  /* Identifiant de la super-classe de la classe [optionnel]. */

	Class(std::string const &identifier, std::vector<Parameter*> const &parameters, std::string const *superClassIdentifier,
        std::vector<Field*> const &fields, Constructor &constructor, std::vector<Method*> const &methods);
};

struct Object : Type  {
	Object(std::string const &identifier, std::vector<Field*> const &fields, Constructor const &constructor, 
	    std::vector<Method*> const &methods);
};

struct Field {
	std::string identifier;     /* Identifiant. */
    std::string typeIdentifier; /* Identifiant du type du champ. */
	
	Field(std::string const &identifier, std::string const &typeIdentifier);
};

struct Method {
    std::string identifier;             /* Identifiant de la méthode. */
    std::vector<Parameter*> parameters; /* Liste de paramètre. */
    //std::tree* m_bloc_instruction;    /* Arbre d'instructions. */
	
	Method(std::string const &identifier, std::vector<Parameter*> const parameters);
};

/**
 * Surcharge de '+' entre Method et Parameter.
 * Ajout d'un Parameter sur une Method.
 */
Method operator+(const Method &lhs, const Parameter &rhs);

/** 
 * Surcharge de '==' pour les Method.
 */
bool operator ==(const Method &lhs, const Method &rhs);

#endif