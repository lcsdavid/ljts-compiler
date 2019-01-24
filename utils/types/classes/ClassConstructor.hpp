#ifndef COMPILER_CLASSCONSTRUCTOR_HPP
#define COMPILER_CLASSCONSTRUCTOR_HPP

#include "../Constructor.hpp"

struct ClassConstructor : Constructor {
	std::string *superIdentifier;				/* Identifiant du super constructeur appelé [optionnel]. */
	std::vector<std::string> *superParameters;	/* Paramètres du super constructeur appelé [optionnel]. */
	
	ClassConstructor(std::string const &identifier, std::vector<Parameter> const &parameters, Block *body,
		std::string *superIdentifier, std::vector<std::string> *superParameters);
	ClassConstructor(ClassConstructor const &other);
	ClassConstructor(ClassConstructor &&other);
	~ClassConstructor() override;
	
	ClassConstructor &operator=(ClassConstructor const &other);
	ClassConstructor &operator=(ClassConstructor &&other);
	
	bool correctDecl() const override;
};

#endif