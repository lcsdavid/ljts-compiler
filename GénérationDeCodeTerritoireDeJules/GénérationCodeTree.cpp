void genereCodeTree(Tree tree)
{
	if(tree.operation==unary_plus)
		genereCodeTree(tree.children[0]);
	else if(tree.operation==unary_substract)
		negat(tree);
	else if(tree.operation==integer)
		creerVar(tree)
	
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