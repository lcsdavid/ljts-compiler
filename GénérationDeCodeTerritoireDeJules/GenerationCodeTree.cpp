#include "GenerationCodeTree.hpp"

void genereCodeTree(Tree *tree)
{
	if(tree->operation==unary_plus)
		genereCodeTree(get<Tree*>(tree->children[0]));
	else if(tree->operation==unary_substract)
		negat(tree);
	else if(tree->operation==integer)
		creerVar(tree);
	else if(tree->operation==addition)
	{
		genereCodeTree(get<Tree*>(tree->children[0]));
		genereCodeTree(get<Tree*>(tree->children[1]));
		cout << "ADD" << endl;
	}
	else if(tree->operation==substraction)
	{
		genereCodeTree(get<Tree*>(tree->children[0]));
		genereCodeTree(get<Tree*>(tree->children[1]));
		cout << "SUB" << endl;
	}
	else if(tree->operation==multiplication)
	{
		genereCodeTree(get<Tree*>(tree->children[0]));
		genereCodeTree(get<Tree*>(tree->children[1]));
		cout << "MUL" << endl;
	}
	else if(tree->operation==division)
	{
		genereCodeTree(get<Tree*>(tree->children[0]));
		genereCodeTree(get<Tree*>(tree->children[1]));
		cout << "DIV" << endl;
	}
	else if(tree->operation==assignment)
		assignation(tree);
	else if(tree->operation==identifier)
		getVal(tree);
	else if(tree->operation==if_then_else)
		fctif(tree);
	else if(tree->operation==equal)
	{
		genereCodeTree(get<Tree*>(tree->children[0]));
		genereCodeTree(get<Tree*>(tree->children[1]));
		cout << "EQUAL" << endl;
	}
	else if(tree->operation==less_strict)
	{
		genereCodeTree(get<Tree*>(tree->children[0]));
		genereCodeTree(get<Tree*>(tree->children[1]));
		cout << "INF" << endl;
	}
	else if(tree->operation==less_equal)
	{
		genereCodeTree(get<Tree*>(tree->children[0]));
		genereCodeTree(get<Tree*>(tree->children[1]));
		cout << "INFEQ" << endl;
	}
	else if(tree->operation==greater_strict)
	{
		genereCodeTree(get<Tree*>(tree->children[0]));
		genereCodeTree(get<Tree*>(tree->children[1]));
		cout << "SUP" << endl;
	}
	else if(tree->operation==greater_equal)
	{
		genereCodeTree(get<Tree*>(tree->children[0]));
		genereCodeTree(get<Tree*>(tree->children[1]));
		cout << "SUPEQ" << endl;
	}
	else if(tree->operation==not_equal)
	{
		genereCodeTree(get<Tree*>(tree->children[0]));
		genereCodeTree(get<Tree*>(tree->children[1]));
		cout << "EQUAL" << endl;
		cout << "PUSHI 0" << endl;
		cout << "EQUAL" << endl;
	}
	else
		cout << "CEST LA MERDE JAI PAS PREVU CE CAS !!!" << tree->operation;
}

std::string generateurLabel()
{
	unsigned int alea;
	std::string res;
	for(unsigned int i;i<10;i++)
	{
		alea = rand();
		res+=(char)alea;
	}
	return res;
}

void fctif(Tree *tree)
{
	std::string label=generateurLabel();
	std::string label2=generateurLabel();
	genereCodeTree(get<Tree*>(tree->children[0]));
	cout << "JZ " << label << endl;
	genereCodeTree(get<Tree*>(tree->children[1]));
	cout << "JUMP " << label2 << endl;
	cout << "PUSHA " << label << endl;
	genereCodeTree(get<Tree*>(tree->children[2]));
	cout << "PUSHA " << label2 << endl;
}

void getVal(Tree *tree)
{
	for(int i=mesVar.size()-1;i>-1;i--)
	{
		if(mesVar[i].nom==get<std::string>(tree->children[0]))
			cout << "PUSHL " << mesVar[i].valeur;
	}
}

void assignation(Tree *tree)
{
	Tree *id = get<Tree*>(tree->children[0]);
	if(id->operation==identifier)
	{
		Assignee tempo;
		tempo.nom = get<std::string>(tree->children[0]);
		tempo.valeur = possp;
		mesVar.push_back(tempo);
		possp++;
		genereCodeTree(get<Tree*>(tree->children[1]));
	}
	else
		cout << "CEST LA MERDE JAI PAS PREVU CE CAS !!!" << tree->operation;
}

void creerVar(Tree *tree)
{
	cout << "PUSHI " << get<int>(tree->children[0]);
}

void negat(Tree *tree)
{
	genereCodeTree(get<Tree*>(tree->children[0]));
	cout << "PUSHI -1\nMUL";
}