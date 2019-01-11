//
// Created by user on 11/01/2019.
//

#ifndef LJTS_COMPILER_CLASS_STRUCT_H
#define LJTS_COMPILER_CLASS_STRUCT_H

#include <string>
#include <vector>
#include "abstract_syntax_tree.hpp"


typedef struct Param_struct {
    bool m_var; //est-ce que ce paramètres
    std::string m_nom;
    std::string m_type;//son type ou sa classe selon le cas
};

typedef struct Methode_struct{

    std::string m_nom;
    std::vector<Param_struct *> m_listParam;
    abstract_syntax_tree m_bloc_instruction;


}Methode_struct;

typedef struct Object_struct {

    std::string m_nom;
    std::vector<Param_struct *> m_listParam;
    std::vector<Methode_struct *> m_listMethode;

}Object_struct;



typedef struct Constructeur_struct{
    std::string m_nom;
    std::vector<Param_struct *> m_parametres;
    Constructeur_struct * m_superConstructeur;
    abstract_syntax_tree m_bloc_instruction;
};

typedef struct Class_struct{
    std::string m_nom;
    std::vector<Param_struct *> m_parametres;
    Class_struct* m_superClasse;
    std::vector<Methode_struct *> m_methodes;
    Constructeur_struct constructeur;
};









#endif //LJTS_COMPILER_CLASS_STRUCT_H
