//
// Created by user on 18/01/2019.
//

#include "Parameter.hpp"

Parameter::Parameter(const std::string &identifier, const std::string &typeIdentifier, bool var) : identifier(
        identifier), typeIdentifier(typeIdentifier), var(var) {}

bool operator==(const Parameter &lhs, const Parameter &rhs) {
    return lhs.identifier == rhs.identifier && lhs.typeIdentifier == rhs.typeIdentifier && lhs.var == rhs.var;
}