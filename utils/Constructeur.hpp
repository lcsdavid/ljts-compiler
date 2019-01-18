//
// Created by user on 18/01/2019.
//

#ifndef LJTS_COMPILER_CONSTRUCTEUR_H
#define LJTS_COMPILER_CONSTRUCTEUR_H
#include <string>
#include <type_traits>
#include <variant>
#include <vector>
#include <map>



struct SuperConstructeur{
    std::string identifier;             /* Identifiant. */
    std::vector<std::string*> parameters; /* Liste de paramètre. */
    SuperConstructeur *superConstructor;      /* Super constructeur [optionnel]. */
};

struct Constructor {
    std::string identifier;             /* Identifiant. */
    std::vector<Parameter*> parameters; /* Liste de paramètre. */
    SuperConstructeur *superConstructor;      /* Super constructeur [optionnel]. */
    //tree *m_bloc_instruction; Pas mieux de faire une struct Bloc ?

    Constructor(const std::string &identifier, const std::vector<Parameter*> &parameters, Constructor *superConstructor);
    bool isCorrect(const std::vector<Parameter *> &parameters);
};


#endif //LJTS_COMPILER_CONSTRUCTEUR_H
