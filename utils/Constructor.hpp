#ifndef LJTS_COMPILER_CONSTRUCTEUR_H
#define LJTS_COMPILER_CONSTRUCTEUR_H

#include <string>
#include <type_traits>
#include <variant>
#include <vector>
#include <map>

struct Constructor {
	std::string identifier;            /* Identifiant. */
	std::vector<Parameter> parameters; /* Liste de paramètre. */
    // Tree tree;

    Constructor(std::string const &identifier, std::vector<Parameter> const &parameters);
	
    virtual bool isCorrect();
};

struct ClassConstructor : Constructor {
	std::string *superIdentifier;              /* Identifiant du super constructeur appelé [optionnel]. */
	std::vector<std::string> *superParameters; /* Paramètres du super constructeur appelé [optionnel]. */
	
	ClassConstructor(std::string const &identifier, std::vector<Parameter> const &parameters,
		std::string *superIdentifier, std::vector<std::string> *superParameters);
		
	bool isCorrect();
};

#endif