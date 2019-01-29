#ifndef COMPILER_TYPE_HPP
#define COMPILER_TYPE_HPP

#include <string>
#include <vector>
#include <map>

#include "../variables/Parameter.hpp"
#include "Constructor.hpp"
#include "Method.hpp"

struct Type {
	std::string identifier;       /* Identifiant de la classe. */
	std::vector<Parameter> fields; /* Liste de champs de la classe. */
	Constructor &constructor;     /* Constructeur de la classe. */
	std::vector<Method> methods;  /* Liste de méthodes de la classe. */

	Type(std::string const &identifier, std::vector<Parameter> const &fields, Constructor &constructor,
		std::vector<Method> const &methods);
	Type(Type const &other);
	Type(Type &&other);
	virtual ~Type();

	virtual bool isInheritable() const = 0;
	
	virtual bool isDuplicable() const = 0;
	
	virtual bool correctDecl(std::map<std::string, Type*> &env) const;
};

#endif