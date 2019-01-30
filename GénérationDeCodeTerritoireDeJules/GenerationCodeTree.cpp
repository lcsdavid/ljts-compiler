#include "GenerationCodeTree.hpp"

void genereCodeTree(Tree *tree)
{
	if(tree->operation==unary_plus)
		genereCodeTree(get<vector<Tree*>> (tree->children)[0]);
	else if(tree->operation==unary_substract)
		negat(tree);
	else if(tree->operation==integer)
		creerVar(tree);
	else if(tree->operation==addition)
	{
		genereCodeTree(get<vector<Tree*>> (tree->children)[0]);
		genereCodeTree(get<vector<Tree*>> (tree->children)[1]);
		cout << "ADD";
	}
	else if(tree->operation==substraction)
	{
		genereCodeTree(get<vector<Tree*>> (tree->children)[0]);
		genereCodeTree(get<vector<Tree*>> (tree->children)[1]);
		cout << "SUB";
	}
	else if(tree->operation==multiplication)
	{
		genereCodeTree(get<vector<Tree*>> (tree->children)[0]);
		genereCodeTree(get<vector<Tree*>> (tree->children)[1]);
		cout << "MUL";
	}
	else if(tree->operation==division)
	{
		genereCodeTree(get<vector<Tree*>> (tree->children)[0]);
		genereCodeTree(get<vector<Tree*>> (tree->children)[1]);
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
		if(mesVar[i].nom==get<std::string> (tree->children))
			cout << "PUSHL " << mesVar[i].valeur;
	}
}

void assignation(Tree *tree)
{
	Tree *id = get<vector<Tree*>> (tree->children)[0];
	if(id->operation==identifier)
	{
		Assignee tempo;
		tempo.nom = get<std::string> (id->children);
		tempo.valeur = possp;
		mesVar.push_back(tempo);
		possp++;
		genereCodeTree(get<vector<Tree*>> (tree->children)[1]);
	}
	else
		cout << "CEST LA MERDE JAI PAS PREVU CE CAS !!!" << tree->operation;
}

void creerVar(Tree *tree)
{
	cout << "PUSHI " << get<int> (tree->children);
}

void negat(Tree *tree)
{
	genereCodeTree(get<vector<Tree*>> (tree->children)[0]);
	cout << "PUSHI -1\nMUL";
}