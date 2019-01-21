#ifndef COMPILER_TYPE_HPP
#define COMPILER_TYPE_HPP

#include <string>
#include <vector>
#include <map>

#include "Constructor.hpp"
#include "Variable.hpp"
#include "Method.hpp"
#include "Parameter.hpp"

struct Type {
	std::string identifier;       /* Identifiant de la classe. */
	std::vector<Variable> fields; /* Liste de champs de la classe. */
	Constructor &constructor;     /* Constructeur de la classe. */
	std::vector<Method> methods;  /* Liste de méthodes de la classe. */
	bool isHeritable;

	Type(std::string const &identifier, std::vector<Variable> const &fields, Constructor &constructor, std::vector<Method> const &methods, bool heritable);
	Type(Type const &other) = default;
	Type(Type &&other) = default;
	virtual ~Type() = default;

	virtual bool correctDecl(std::map<std::string, Type>* environnement) const;
};

struct Class : Type {
	std::vector<Parameter> parameters; /* Liste de paramètres de la classe. */
	std::string *superClassIdentifier; /* Identifiant de la super-classe de la classe [optionnel]. */

	Class(std::string const &identifier, std::vector<Parameter> const &parameters, std::string *superClassIdentifier,
		std::vector<Variable> const &fields, ClassConstructor &constructor, std::vector<Method> const &methods);

	bool correctDecl(std::map<std::string, Type>* environnement) const override;
	Class(Class const &other) = default;
	Class(Class &&other) = default;
};

struct Object : Type {
	Object(std::string const &identifier, std::vector<Variable> const &fields, Constructor &constructor,
		std::vector<Method> const &methods);

	bool correctDecl(std::map<std::string, Type>* environnement) const override;
	Object(Object const &other) = default;

};



#endif