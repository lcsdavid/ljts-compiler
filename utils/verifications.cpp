#include "verifications.hpp"

/**
 * @return true si le programme est bon, false sinon
 * @param programme, le programme que l'on veut evaluer
**/

bool verifications(Programme programme){

    //map des declarations connues
    //si la string est le nom d'une variable alors Type est son Type
    //si la string désigne le nom de la classe alors Type est la déclaration de cette classe
    std::map<std::string, Type> *environnementType;
	
	//le vecteur qui contient toutes les variables connues à cet endroit du programme
	std::vector<Parameter> envVar;

    for(int i = 0; i<programme.decls.size(); i++){
        if(!programme.decls.at(i)->typeCorrect(environnementType))
            return false;//on a un problème de construction du programme
    }


    return true;

}