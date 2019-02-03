#ifndef PARAMETER_HPP
#define PARAMETER_HPP

#include <ostream>
#include <string>

struct Parameter {
	bool var;                   /* Est-ce que c'est un paramètre 'var'. */
	std::string identifier;     /* Identifiant du paramètre. */
    std::string typeIdentifier; /* Identifiant du type du paramètre. */
	
	Parameter(bool var, const std::string &identifier, const std::string &typeIdentifier);
	~Parameter() = default;
};

std::ostream &operator<<(std::ostream &os, const Parameter &p);

#endif
