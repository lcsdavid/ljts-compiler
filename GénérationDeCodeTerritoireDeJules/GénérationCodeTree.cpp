genereCodeTree(Tree tree)
{
	if(tree.operation==unary_plus)
		genereCodeTree(tree.children[0]);
	else if(tree.operation==unary_substract)
		negat(tree);
	else if
	
}

negat(Tree tree)
{
	genereCodeTree(tree.children[0]);
}