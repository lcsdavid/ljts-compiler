#ifndef PARAMETER_HPP
#define PARAMETER_HPP

#include <ostream>
#include <string>

struct Variable {
    std::string identifier;     /* Identifiant du paramètre. */
    std::string typeIdentifier; /* Identifiant du type du paramètre. */
    bool var;                   /* Est-ce que c'est un paramètre 'var'. */

    Variable(const std::string &identifier, const std::string &typeIdentifier, bool var = true);
	Variable(Variable const &other) = default;
	~Variable() = default;
};

std::ostream &operator<<(std::ostream &os, const Variable &parameter);

/**
 * Surcharge de '==' pour les Variable.
 */
bool operator==(Variable const &lhs, Variable const &rhs);

bool operator!=(Variable const &lhs, Variable const &rhs);

#endif
