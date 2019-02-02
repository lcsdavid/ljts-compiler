#ifndef GENERE_HPP
#define GENERE_HPP

#include "../utils/trees/Tree.hpp"
#include "../ljts-compiler.hpp"

#include <vector>

using namespace std;

struct Assignee {
	std::string nom;
	int valeur;
};

std::vector<Assignee> VarGenerale;

std::vector<std::vector<Assignee>> mesVar;

std::vector<unsigned int> possp;
unsigned int fctcour=0;

void genereCode(Program *program);
void generationCodeDecls(std::vector<Type*> typesDecls);
void genereCodeTree(Tree *tree);
void getVal(Tree *tree);
void assignation(Tree *tree);
void creerVar(Tree *tree);
void negat(Tree *tree);
void fctif(Tree *tree);

#endif
