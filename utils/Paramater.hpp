#ifndef PARAMETER_HPP
#define PARAMETER_HPP

#include <ostream>
#include <string>

struct Parameter {
	bool var;                   /* Est-ce que c'est un param�tre 'var'. */
	std::string identifier;     /* Identifiant du param�tre. */
    std::string typeIdentifier; /* Identifiant du type du param�tre. */
	
	Parameter(bool var, const std::string &identifier, const std::string &typeIdentifier);
	~Parameter() = default;
};

std::ostream &operator<<(std::ostream &os, const Parameter &p);

#endif
