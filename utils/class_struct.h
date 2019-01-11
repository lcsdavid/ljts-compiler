//
// Created by user on 11/01/2019.
//

#ifndef LJTS_COMPILER_CLASS_STRUCT_H
#define LJTS_COMPILER_CLASS_STRUCT_H

#include <string>
#include <vector>
#include "tree.hpp"


struct Param_struct {
    bool m_var; //est-ce que ce paramètres
    std::string m_nom;
    std::string m_type;//son type ou sa classe selon le cas
};

Param_struct* makeParamStruct(bool var, std::string nom, std::string type);

struct Methode_struct{

    std::string m_nom;
    std::vector<Param_struct *> m_listParam;
    //std::tree* m_bloc_instruction;


};

//Methode_struct* makeMethodeStruct(std::string nom, std::tree* m_bloc_instruction, std::vector<Param_struct *> listParam = std::vector<Param_struct *>());



struct Object_struct {

    std::string m_nom;
    std::vector<Param_struct *> m_listParam;
    std::vector<Methode_struct *> m_listMethode;

};

Object_struct* makeObjectStruct(std::string nom, std::vector<Param_struct *> m_listParam = std::vector<Param_struct *>(), std::vector<Methode_struct *> m_listMethode = std::vector<Methode_struct *>());



struct Constructeur_struct{
    std::string m_nom;
    std::vector<Param_struct *> m_parametres;
    Constructeur_struct * m_superConstructeur;
    //std::tree* m_bloc_instruction;
};

//Constructeur_struct* makeConstructeurStruct(std::string nom, Constructeur_struct * superConstructeur, std::tree* m_bloc_instruction,std::vector<Param_struct *> m_parametres =  std::vector<Param_struct *>());

struct Class_struct{
    std::string m_nom;
    std::vector<Param_struct *> m_parametres;
    Class_struct* m_superClasse;
    std::vector<Methode_struct *> m_methodes;
    Constructeur_struct* m_constructeur;
};

Class_struct* makeClassStruct(std::string nom, Class_struct* superClasse, Constructeur_struct* constructeur_struct, std::vector<Param_struct *> parametres = std::vector<Param_struct *>(), std::vector<Methode_struct *> methodes =std::vector<Methode_struct *>());







#endif //LJTS_COMPILER_CLASS_STRUCT_H
