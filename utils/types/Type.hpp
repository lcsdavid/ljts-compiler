#ifndef COMPILER_TYPE_HPP
#define COMPILER_TYPE_HPP

#include <iostream>
#include <map>
#include <stdexcept>
#include <string>
#include <vector>

#include "../Variable.hpp"
#include "Constructor.hpp"
#include "Method.hpp"

#include "../Environment.hpp"

struct Type {
	std::string identifier;       /* Identifiant de la classe. */
	std::vector<Variable> fields; /* Liste de champs de la classe. */
	Constructor &constructor;     /* Constructeur de la classe. */
	std::vector<Method> methods;  /* Liste de méthodes de la classe. */

	Type(const std::string &identifier, const std::vector<Variable> &fields, Constructor &constructor,
		const std::vector<Method> &methods);
	Type(Type const &other) = default;
	Type(Type &&other) = default;
	virtual ~Type();

	virtual bool isStatic() const = 0;
	virtual bool hasSuper() const = 0;
	virtual std::string super() const = 0;
	
	virtual bool correctDecl(const Environment &env) const;
};

std::ostream &operator<<(std::ostream &os, const Type &type);

#endif