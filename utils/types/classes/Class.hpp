#ifndef COMPILER_CLASS_HPP
#define COMPILER_CLASS_HPP

#include "../Type.hpp"
#include "ClassConstructor.hpp"

struct Class : Type {
	std::vector<Parameter> parameters;	/* Liste de paramètres de la classe. */
	std::string superIdentifier;		/* Identifiant de la super-classe de la classe [optionnel]. */

	Class(std::string const &identifier, std::vector<Parameter> const &parameters, std::string superIdentifier,
		std::vector<Variable> const &fields, ClassConstructor &constructor, std::vector<Method> const &methods);
	Class(Class const &other);
	Class(Class &&other);
	~Class() override;
	
	bool isInheritable() const override {
		return true;
	}
	
	bool correctDecl(std::map<std::string, Type*> &env) const override;
};


#endif