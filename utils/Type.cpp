#include "Type.hpp"

Type::Type(std::string const &identifier, std::vector<Parameter*> const &parameters, std::string const &superClass, 
    std::vector<Field*> const &fields, Constructor &constructor, std::vector<Method*> const &methods) 
	: identifier(identifier), fields(fields), constructor(constructor), methods(methods) {}
		   
bool Type::typeCorrect(std::map<std::string, Type>* environnement){
    //cas ou le nom de la classe est déjà pris
    bool correct = false;
    try{
        environnement->at(this->identifier);
    }catch(std::out_of_range){
        correct = true;//on a le droit de définir cette variable vu qu'elle n'existe pas déjà

    }
    if(!correct)
        return false;

    std::string res = this->getSuperClass();
    if(res != ""){//si le type déclare avoir une super classe
        try{
            environnement->at(res);
        }catch(std::out_of_range){
            return false;//la super classe n'est pas connue
        }
    }


    return true;
}

Class::Class(std::string const &identifier, std::vector<Parameter*> const &parameters, 
    std::string const &superClassIdentifier, std::vector<Field*> const &fields, Constructor &constructor,
	const std::vector<Method*> &methods) : Type(identifier, fields, constructor, methods), parameters(parameters),
	superClass(superClass) {}
			 
Object::Object(std::string const &identifier, std::vector<Field*> const &fields, Constructor const &constructor,
    std::vector<Method*> const &methods) : Type(identifier, fields, constructor, methods) {}
			   
Field::Field(std::string const &identifier, const std::string &typeIdentifier) : identifier(identifier),
    typeIdentifier(typeIdentifier) {}
																				 

Method::Method(std::string const &identifier, std::vector<Parameter *> const parameters) : identifier(identifier),
    parameters(parameters) {}
			   
Method operator+(Method &lhs, Parameter *rhs) {
    lhs.parameters.push_back(rhs);
    return lhs;
}

bool operator==(Method const &lhs, Method const &rhs) {
    if (lhs.parameters.size() != rhs.parameters.size())
        return false;
    if (lhs.identifier != rhs.identifier)
        return false;
    for (std::size_t i = 0; i < rhs.parameters.size(); i++)
        if (lhs.parameters[i] != rhs.parameters[i])
            return false;
    return true;
}

