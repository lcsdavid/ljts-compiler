#ifndef PARAMETER_HPP
#define PARAMETER_HPP

#include <string>

struct Parameter {
    std::string identifier;     /* Identifiant du paramètre. */
    std::string typeIdentifier; /* Identifiant du type du paramètre. */
    bool var;                   /* Est-ce que c'est un paramètre 'var'. */

    Parameter(const std::string &identifier, const std::string &typeIdentifier, bool var = false);
	Parameter(Parameter const &other) = default;
	~Parameter() = default;
};

/**
 * Surcharge de '==' pour les Parameter.
 */
bool operator==(Parameter const &lhs, Parameter const &rhs);

bool operator!=(Parameter const &lhs, Parameter const &rhs);

#endif
