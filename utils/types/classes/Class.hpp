#ifndef COMPILER_CLASS_HPP
#define COMPILER_CLASS_HPP

#include "../Type.hpp"

#include "ClassConstructor.hpp"

struct Class : Type {
	std::vector<Parameter> parameters;	/* Liste de paramètres de la classe. */
	std::string superIdentifier;		/* Identifiant de la super-classe de la classe [optionnel]. */

	Class(const std::string &identifier, const std::vector<Parameter> &parameters, const std::string &superIdentifier,
		const std::vector<Variable> &fields, ClassConstructor &constructor, const std::vector<Method> &methods);
	Class(const Class &other) = default;
	Class(Class &&other) = default;
	~Class() override = default;
	
	bool isStatic() const override {
		return false;
	}
	
	bool hasSuper() const override {
		return !superIdentifier.empty();
	}
	
	std::string super() const override {
		if (!hasSuper())
			throw std::logic_error(identifier + " n'a pas de super classe.");
		return superIdentifier;
	}
	
	bool correctDecl(const Environment &env) const override;
};


#endif