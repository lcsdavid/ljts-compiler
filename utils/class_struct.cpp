//
// Created by user on 11/01/2019.
//

#include "class_struct.h"


Param_struct* makeParamStruct(bool var, std::string nom, std::string type){
    Param_struct* res = new Param_struct;
    res->m_nom = nom;
    res->m_type = type;
    res->m_var = var;
    return res;
}

/*Methode_struct* makeMethodeStruct(std::string nom, abstract_syntax_tree* bloc_instruction, std::vector<Param_struct *> listParam = std::vector<Param_struct *>()){
    Methode_struct* res = new Methode_struct;
    res->m_nom = nom;
    res->m_bloc_instruction = bloc_instruction;
    res->m_listParam = listParam;
    return res;
}*/

Object_struct* makeObjectStruct(std::string nom, std::vector<Param_struct *> listParam = std::vector<Param_struct *>(), std::vector<Methode_struct *> listMethode = std::vector<Methode_struct *>()){
    Object_struct* res = new Object_struct;
    res->m_listParam = listParam;
    res->m_listMethode = listMethode;
    res->m_nom = nom;
    return res;
}

/*Constructeur_struct* makeConstructeurStruct(std::string nom, Constructeur_struct * superConstructeur, abstract_syntax_tree* bloc_instruction,std::vector<Param_struct *> parametres =  std::vector<Param_struct *>()){
    Constructeur_struct* res = new Constructeur_struct;
    res->m_nom = nom;
    //res->m_bloc_instruction = bloc_instruction;
    res->m_parametres = parametres;
    res->m_superConstructeur =superConstructeur;
    return res;
}*/

Class_struct* makeClassStruct(std::string nom, Class_struct* superClasse, Constructeur_struct* constructeur_struct, std::vector<Param_struct *> parametres = std::vector<Param_struct *>(), std::vector<Methode_struct *> methodes =std::vector<Methode_struct *>()){
    Class_struct* res = new Class_struct;

    res->m_parametres =parametres;
    res->m_nom = nom;
    res->m_constructeur = constructeur_struct;
    res->m_methodes = methodes;
    res->m_superClasse = superClasse;
    return res;
}