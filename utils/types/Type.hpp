#ifndef COMPILER_TYPE_HPP
#define COMPILER_TYPE_HPP

#include <string>
#include <vector>
#include <map>

#include "../variables/Variable.hpp"
#include "Constructor.hpp"
#include "Method.hpp"

struct Type {
	std::string identifier;       /* Identifiant de la classe. */
	std::vector<Variable> fields; /* Liste de champs de la classe. */
	Constructor &constructor;     /* Constructeur de la classe. */
	std::vector<Method> methods;  /* Liste de méthodes de la classe. */

	Type(std::string const &identifier, std::vector<Variable> const &fields, Constructor &constructor,
		std::vector<Method> const &methods);
	Type(Type const &other);
	Type(Type &&other);
	virtual ~Type();

	virtual bool isInheritable() const = 0;
	
	virtual bool isDuplicable() const = 0;
	
	virtual bool correctDecl(std::map<std::string, Type*> &env) const;
};

#endif