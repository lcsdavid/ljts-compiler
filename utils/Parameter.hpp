//
// Created by user on 18/01/2019.
//

#ifndef LJTS_COMPILER_PARAMETER_H
#define LJTS_COMPILER_PARAMETER_H

#include <string>
#include <type_traits>
#include <variant>
#include <vector>
#include <map>



struct Parameter {
    std::string identifier;     /* Identifiant du paramètre. */
    std::string typeIdentifier; /* Identifiant du type du paramètre. */
    bool var;                   /* Est-ce que c'est un paramètre 'var'. */

    Parameter(const std::string &identifier, const std::string &type, bool var);
};

/**
 * Surcharge de '==' pour les Parameter.
 */
bool operator==(const Parameter &lhs, const Parameter &rhs);



#endif //LJTS_COMPILER_PARAMETER_H
