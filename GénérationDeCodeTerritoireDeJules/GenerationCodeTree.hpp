#ifndef GENERE_HPP
#define GENERE_HPP

#include "../utils/trees/Tree.hpp"
#include "../ljts-compiler.hpp"

#include <vector>

struct Assignee
{
	std::string nom;
	int valeur;
};

vector<Assignee> mesVar;
int possp=0;

void genereCodeTree(Tree *tree);
void getVal(Tree *tree);
void assignation(Tree *tree);
void creerVar(Tree *tree);
void negat(Tree *tree);

#endif
