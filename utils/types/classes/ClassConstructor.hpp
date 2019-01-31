#ifndef COMPILER_CLASSCONSTRUCTOR_HPP
#define COMPILER_CLASSCONSTRUCTOR_HPP

#include "../Constructor.hpp"

struct ClassConstructor : Constructor {
	std::string superIdentifier;		/* Identifiant du super constructeur appelé [optionnel]. */
	std::vector<Tree*> superParameters;	/* Paramètres du super constructeur appelé [optionnel]. */
	
	ClassConstructor(const std::string &identifier, const std::vector<Parameter> &parameters,
		const std::string &superIdentifier, const std::vector<Tree*> &superParameters, Block *body);
	ClassConstructor(const ClassConstructor &other) = default;
	ClassConstructor(ClassConstructor &&other) = default;
	~ClassConstructor() override = default;
	
	ClassConstructor &operator=(const ClassConstructor &other) = default;
	ClassConstructor &operator=(ClassConstructor &&other) = default;
	
	bool correctDecl(const Environment &env) const override;
};

#endif