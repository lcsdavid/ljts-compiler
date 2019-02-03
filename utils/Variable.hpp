#ifndef VARIABLE_HPP
#define VARIABLE_HPP

#include <ostream>
#include <string>

struct Tree;

struct Variable {
	std::string identifier;     /* Identifiant du paramètre. */
    std::string typeIdentifier; /* Identifiant du type du paramètre. */
    Tree *initialization;       /* Est-ce que c'est un paramètre 'var'. */
	
	Variable(const std::string &identifier, const std::string &typeIdentifier, Tree *initialization = nullptr);
	~Variable() = default;
};

std::ostream &operator<<(std::ostream &os, const Variable &v);

/**
 * Surcharge de '==' pour les Variable.
 */
bool operator==(Variable const &lhs, Variable const &rhs);

bool operator!=(Variable const &lhs, Variable const &rhs);

#endif
