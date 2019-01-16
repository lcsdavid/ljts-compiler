#include "structs.hpp"

Parameter::Parameter(const std::string &identifier, const std::string &typeIdentifier, bool var) : identifier(
        identifier), typeIdentifier(typeIdentifier), var(var) {}

bool operator==(const Parameter &lhs, const Parameter &rhs) {
    return lhs.identifier == rhs.identifier && lhs.typeIdentifier == rhs.typeIdentifier && lhs.var == rhs.var;
}

Field::Field(const std::string &identifier, const std::string &typeIdentifier) : identifier(identifier),
                                                                                 typeIdentifier(typeIdentifier) {}

Method::Method(const std::string &identifier, const std::vector<Parameter *> parameters) : identifier(identifier),
                                                                                           parameters(parameters) {}

bool operator==(const Method &lhs, const Method &rhs) {
    if (lhs.parameters.size() != rhs.parameters.size())
        return false;
    if (lhs.identifier != rhs.identifier)
        return false;
    for (std::size_t i = 0; i < rhs.parameters.size(); i++)
        if (lhs.parameters[i] == rhs.parameters[i])
            return false;
    return true;
}

Method operator+(const Method &lhs, const Parameter &rhs) {
    lhs.parameters.push_back(rhs);
    return lhs;
}

Constructor::Constructor(const std::string &identifier, const std::vector<Parameter *> &parameters,
                         Constructor *superConstructor) : identifier(identifier),
                                                          parameters(parameters), superConstructor(superConstructor) {}

Type::Type(const std::string &identifier, const std::vector<Field *> &fields, const std::vector<Method *> &methods,
           Constructor &constructor) : identifier(identifier),
                                       fields(fields), methods(methods), constructor(constructor) {}

Class::Class(const std::string &identifier, const std::vector<Parameter *> &parameters, Class *superClass,
             const std::vector<Field *> &fields,
             const std::vector<Method *> &methods, Constructor &constructor) : Type(identifier, fields, methods,
                                                                                    constructor),
                                                                               parameters(parameters),
                                                                               superClass(superClass) {}

Object::Object(const std::string &identifier, const std::vector<Field *> &fields, const std::vector<Method *> &methods)
        : Type(identifier, fields, methods, constructor) {}

void regressionTesting() {
    Parameter p("nom", "String", false);
    Method m("toString", std::vector<Parameter *>());
    Constructor("Compiler", std::vector<Parameter *>(), nullptr);


};


/*	
Param* makeParam(bool var, std::string nom, std::string type){
    Param* res = new Param;
    res->m_nom = nom;
    res->m_type = type;
    res->m_var = var;
    return res;
}

Method* makeMethod(std::string nom, abstract_syntax_tree* bloc_instruction, std::vector<Param *> listParam = std::vector<Param *>()){
    Method* res = new Method;
    res->m_nom = nom;
    res->m_bloc_instruction = bloc_instruction;
    res->m_listParam = listParam;
    return res;
}

Object* makeObject(std::string nom, std::vector<Param *> listParam = std::vector<Param *>(), std::vector<Method *> listMethode = std::vector<Method *>()){
    Object* res = new Object;
    res->m_listParam = listParam;
    res->m_listMethode = listMethode;
    res->m_nom = nom;
    return res;
}

Constructeur_struct* makeConstructeurStruct(std::string nom, Constructeur_struct * superConstructeur, abstract_syntax_tree* bloc_instruction,std::vector<Param *> parametres =  std::vector<Param *>()){
    Constructeur_struct* res = new Constructeur_struct;
    res->m_nom = nom;
    //res->m_bloc_instruction = bloc_instruction;
    res->m_parametres = parametres;
    res->m_superConstructeur =superConstructeur;
    return res;
}

Class_struct* makeClassStruct(std::string nom, Class_struct* superClasse, Constructeur_struct* constructeur_struct, std::vector<Param *> parametres = std::vector<Param *>(), std::vector<Method *> methodes =std::vector<Method *>()){
    Class_struct* res = new Class_struct;

    res->m_parametres =parametres;
    res->m_nom = nom;
    res->m_constructeur = constructeur_struct;
    res->m_methodes = methodes;
    res->m_superClasse = superClasse;
    return res;
}
*/