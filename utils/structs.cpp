#include "structs.hpp"

Parameter::Parameter(const std::string &identifier, const std::string &typeIdentifier, bool var) : identifier(identifier), typeIdentifier(typeIdentifier), var(var) {}

bool operator ==(Parameter p1, Parameter p2){
	return (p1.identifier == p2.identifier && p1.typeIdentifier==p2.typeIdentifier && p1.var==p2.var);
}


Field::Field(const std::string &identifier, const std::string &typeIdentifier) : identifier(identifier), typeIdentifier(typeIdentifier) {}

Method::Method(const std::string &identifier, const std::vector<Parameter*> parameters) : identifier(identifier), parameters(parameters) {}

bool operator ==(Method m1, Method m2){
	if(m1.parameters.size() != m2.parameters.size() )
		return false;
	bool res = m1.identifier == m2.identifier ;
	for(size_t i = 0; i < m2.parameters.size(); i++ ){
		res = res && (m1.parameters.at(i) == m2.parameters.at(i));
	}
	return res;

}

Method operator+(Method &m, Parameter* p){
	if( p != nullptr)
		m.parameters.push_back(p);
	return m;
}

Constructor::Constructor(const std::string &identifier, const std::vector<Parameter*> &parameters, Constructor *superConstructor) : identifier(identifier),
    parameters(parameters), superConstructor(superConstructor) {}

    


Class::Class(const std::string &identifier, const std::vector<Parameter*> &parameters, Class *superClass, const std::vector<Field*> &fields,
    const std::vector<Method*> &methods, Constructor &constructor) : identifier(identifier), parameters(parameters), superClass(superClass), fields(fields), 
	methods(methods), constructor(constructor) {}
	
Object::Object(const std::string &identifier, const std::vector<Field*> &fields, const std::vector<Method*> &methods) : identifier(identifier), fields(fields),
    methods(methods) {}
	
void regressionTesting() {
	Parameter p("nom", "String", false);
	Method m("toString", std::vector<Parameter*>());
	Constructor("Compiler", std::vector<Parameter*>(), nullptr);
	
	
	
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