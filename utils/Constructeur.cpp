//
// Created by user on 18/01/2019.
//
#include "Constructeur.hpp"

Constructor::Constructor(const std::string &identifier, const std::vector<Parameter *> &parameters,
                         Constructor *superConstructor) : identifier(identifier), parameters(parameters),
                                                          superConstructor(superConstructor) {}

bool Constructeur::isCorrect() {
    if (superConstructor != nullptr) {
        for (auto param :superConstructor->parameters)
            if (std::find(parameters.begin(), parameters.end(), param) != parameters.end())
                return false;
        return paramaters == superConstructor->parameters;
    }

}
