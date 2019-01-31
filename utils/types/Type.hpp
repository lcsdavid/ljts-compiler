#ifndef COMPILER_TYPE_HPP
#define COMPILER_TYPE_HPP

#include <string>
#include <vector>
#include <map>

#include "../Environment.hpp"
#include "../variables/Parameter.hpp"
#include "Constructor.hpp"
#include "Method.hpp"

struct Type {
	std::string identifier;       /* Identifiant de la classe. */
	std::vector<Parameter> fields; /* Liste de champs de la classe. */
	Constructor &constructor;     /* Constructeur de la classe. */
	std::vector<Method> methods;  /* Liste de méthodes de la classe. */

	Type(const std::string &identifier, const std::vector<Parameter> &fields, Constructor &constructor,
		const std::vector<Method> &methods);
	Type(Type const &other) = default;
	Type(Type &&other) = default;
	virtual ~Type();

	virtual bool isInheritable() const = 0;
	
	virtual bool isDuplicable() const = 0;
	
	virtual bool correctDecl(const Environment &env) const;
	
	virtual std::string getSuperClass();
};

#endif