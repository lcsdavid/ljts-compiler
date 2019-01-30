#include "GenerationCodeTree.hpp"

#include <cassert>

void genereCodeTree(Tree *tree) {
	assert(tree);
	switch (tree->operation) {
		case operation::unary_plus:
			genereCodeTree(std::get<Tree*>(tree->children[0]));
			break;
		case unary_substract:
			negat(tree);
			break;
		case operation::integer:
			creerVar(tree);
			break;
		case operation::addition:
			genereCodeTree(std::get<Tree*>(tree->children[0]));
			genereCodeTree(std::get<Tree*>(tree->children[1]));
			std::cout << "ADD" << std::endl;
			break;
		case operation::substraction:
			genereCodeTree(std::get<Tree*>(tree->children[0]));
			genereCodeTree(std::get<Tree*>(tree->children[1]));
			std::cout << "SUB" << std::endl;
			break;
		case operation::multiplication:
			genereCodeTree(std::get<Tree*>(tree->children[0]));
			genereCodeTree(std::get<Tree*>(tree->children[1]));
			std::cout << "MUL" << std::endl;
			break;
		case operation::division:
			genereCodeTree(std::get<Tree*>(tree->children[0]));
			genereCodeTree(std::get<Tree*>(tree->children[1]));
			std::cout << "DIV" << std::endl;
			break;
		case operation::assignment:
			assignation(tree);
			break;
		case operation::identifier:
			getVal(tree);
			break;
		case operation::if_then_else:
			fctif(tree);
			break;
		case operation::equal:
			genereCodeTree(std::get<Tree*>(tree->children[0]));
			genereCodeTree(std::get<Tree*>(tree->children[1]));
			std::cout << "EQUAL" << std::endl;
			break;
		case operation::less_strict:
			genereCodeTree(std::get<Tree*>(tree->children[0]));
			genereCodeTree(std::get<Tree*>(tree->children[1]));
			std::cout << "INF" << std::endl;
			break;
		case operation::less_equal:
			genereCodeTree(std::get<Tree*>(tree->children[0]));
			genereCodeTree(std::get<Tree*>(tree->children[1]));
			std::cout << "INFEQ" << std::endl;
			break;
		case operation::greater_strict:
			genereCodeTree(std::get<Tree*>(tree->children[0]));
			genereCodeTree(std::get<Tree*>(tree->children[1]));
			std::cout << "SUP" << std::endl;
			break;
		case operation::greater_equal:
			genereCodeTree(std::get<Tree*>(tree->children[0]));
			genereCodeTree(std::get<Tree*>(tree->children[1]));
			std::cout << "SUPEQ" << std::endl;
			break;
		case operation::not_equal:
			genereCodeTree(std::get<Tree*>(tree->children[0]));
			genereCodeTree(std::get<Tree*>(tree->children[1]));
			std::cout << "EQUAL" << std::endl;
			std::cout << "PUSHI 0" << std::endl;
			std::cout << "EQUAL" << std::endl;
			break;
		default:
			std::cout << "CEST LA MERDE JAI PAS PREVU CE CAS !!!" << tree->operation;
			break;
	}
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
	genereCodeTree(std::get<Tree*>(tree->children[0]));
	std::cout << "JZ " << label << std::endl;
	genereCodeTree(std::get<Tree*>(tree->children[1]));
	std::cout << "JUMP " << label2 << std::endl;
	std::cout << "PUSHA " << label << std::endl;
	genereCodeTree(std::get<Tree*>(tree->children[2]));
	std::cout << "PUSHA " << label2 << std::endl;
}

void getVal(Tree *tree)
{
	for(int i=mesVar.size()-1;i>-1;i--)
	{
		if(mesVar[i].nom==std::get<std::string>(tree->children[0]))
			std::cout << "PUSHL " << mesVar[i].valeur;
	}
}

void assignation(Tree *tree)
{
	Tree *id = std::get<Tree*>(tree->children[0]);
	if(id->operation==identifier)
	{
		Assignee tempo;
		tempo.nom = std::get<std::string>(tree->children[0]);
		tempo.valeur = possp;
		mesVar.push_back(tempo);
		possp++;
		genereCodeTree(std::get<Tree*>(tree->children[1]));
	}
	else
		std::cout << "CEST LA MERDE JAI PAS PREVU CE CAS !!!" << tree->operation;
}

void creerVar(Tree *tree)
{
	std::cout << "PUSHI " << std::get<int>(tree->children[0]);
}

void negat(Tree *tree)
{
	genereCodeTree(std::get<Tree*>(tree->children[0]));
	std::cout << "PUSHI -1\nMUL";
}