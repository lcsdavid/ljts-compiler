#include "../utils/trees/Tree.hpp"
#include "../ljts-compiler.hpp"

vector<Assignee> mesVar;
int possp=0;

struct Assignee
{
	std::string nom;
	int valeur;
}

void genereCodeTree(Tree *tree)
{
	if(tree->operation==unary_plus)
		genereCodeTree(tree.children[0]);
	else if(tree->operation==unary_substract)
		negat(tree);
	else if(tree.operation==integer)
		creerVar(tree)
	else if(tree->operation==addition)
	{
		genereCodeTree(tree.children[0]);
		genereCodeTree(tree.children[1]);
		cout << "ADD";
	}
	else if(tree->operation==substraction)
	{
		genereCodeTree(tree.children[0]);
		genereCodeTree(tree.children[1]);
		cout << "SUB";
	}
	else if(tree->operation==multiplication)
	{
		genereCodeTree(tree.children[0]);
		genereCodeTree(tree.children[1]);
		cout << "MUL";
	}
	else if(tree->operation==division)
	{
		genereCodeTree(tree.children[0]);
		genereCodeTree(tree.children[1]);
		cout << "DIV";
	}
	else if(tree->operation==assignment)
		assignation(tree);
	else if(tree->operation==identifier)
		getVal(tree);
	else
		cout << "CEST LA MERDE JAI PAS PREVU CE CAS !!!" << tree->operation;
}

void getVal(Tree *tree)
{
	for(int i=mesVar.size()-1;i>-1;i--)
	{
		if(mesVar[i].nom==tree->children)
			cout << "PUSHL " << mesVar[i].valeur;
	}
}

void assignation(Tree *tree)
{
	Tree *id = tree->children[0];
	if(tree->operation!=identifier)
		cout << "CEST LA MERDE JAI PAS PREVU CE CAS !!!" << tree->operation;
	Assignee tempo;
	tempo.nom = id->children;
	tempo.valeur = possp;
	mesVar.push_back(tempo);
	possp++;
}

void creerVar(Tree *tree)
{
	cout << "PUSHI " << tree->children;
}

void negat(Tree *tree)
{
	genereCodeTree(tree->children[0]);
	cout << "PUSHI -1\nMUL";
}