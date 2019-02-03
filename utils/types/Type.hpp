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
	virtual ~Type();

	virtual bool isStatic() const = 0;
	virtual bool hasSuper() const = 0;
	virtual std::string super() const = 0;
	
	virtual bool isCorrect(Environment &env) const;
	virtual bool correctDecl(const Environment &env) const;
	
	virtual std::ostream &print(std::ostream &os) const = 0;
	
	//est-ce que l'on connait cette methode ou pas dans notre classe
	virtual Method* know(std::string str);
};

std::ostream &operator<<(std::ostream &os, const Type &type);

#endif