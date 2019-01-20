#ifndef COMPILER_TYPE_HPP
#define COMPILER_TYPE_HPP

#include <vector>

#include "Constructor.hpp"
#include "Variable.hpp"
#include "Method.hpp"

struct Type {
	std::string identifier;       /* Identifiant de la classe. */
	std::vector<Variable> fields; /* Liste de champs de la classe. */
	Constructor &constructor;     /* Constructeur de la classe. */
	std::vector<Method> methods;  /* Liste de méthodes de la classe. */
    
    Type(std::string const &identifier, std::vector<Variable> const &fields, Constructor const &constructor,
        std::vector<Method> const &methods);
		
	virtual bool correctDecl() const;
};

struct Class : Type  {
	std::vector<Parameter> parameters; /* Liste de paramètres de la classe. */
	std::string *superClassIdentifier;  /* Identifiant de la super-classe de la classe [optionnel]. */

	Class(std::string const &identifier, std::vector<Parameter> const &parameters, std::string const *superClassIdentifier,
        std::vector<Variable> const &fields, ClassConstructor const &constructor, std::vector<Method> const &methods);
		
	bool correctDecl() const override;
};

struct Object : Type  {
	
	Object(std::string const &identifier, std::vector<Variable> const &fields, Constructor const &constructor, 
	    std::vector<Method> const &methods);
		
	bool correctDecl() const override;
};

#endif