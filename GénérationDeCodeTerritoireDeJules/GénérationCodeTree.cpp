#include "../utils/trees/Tree.hpp"

void genereCodeTree(Tree tree)
{
	if(tree.operation==unary_plus)
		genereCodeTree(tree.children[0]);
	else if(tree.operation==unary_substract)
		negat(tree);
	else if(tree.operation==integer)
		creerVar(tree)
	else if(tree.operation==addition)
	{
		genereCodeTree(tree.children[0]);
		genereCodeTree(tree.children[1]);
		cout << "ADD";
	}
	else if(tree.operation==substraction)
	{
		genereCodeTree(tree.children[0]);
		genereCodeTree(tree.children[1]);
		cout << "SUB";
	}
	else if(tree.operation==multiplication)
	{
		genereCodeTree(tree.children[0]);
		genereCodeTree(tree.children[1]);
		cout << "MUL";
	}
	else if(tree.operation==division)
	{
		genereCodeTree(tree.children[0]);
		genereCodeTree(tree.children[1]);
		cout << "DIV";
	}
	
}

void creerVar(Tree tree)
{
	cout << "PUSHI " << tree.children;
}

void negat(Tree tree)
{
	genereCodeTree(tree.children[0]);
	cout << "PUSHI -1\nMUL";
}