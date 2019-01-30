#include "Tree.hpp"

#include "Block.hpp"

/* return_call */
Tree::Tree(int lineno, int operation) : lineno(lineno), operation(operation) {}
/* integer */
Tree::Tree(int lineno, int operation, int value) : lineno(lineno), operation(operation), children() {
	children.push_back(value);
}
/* string | identifier */
Tree::Tree(int lineno, int operation, const std::string &value) : lineno(lineno), operation(operation), children() {
	children.push_back(value);
}
/* inst_block */
Tree::Tree(int lineno, int operation, Block* block) : lineno(lineno), operation(operation), children() {
	children.push_back(block);
}
/* subtrees > */
Tree::Tree(int lineno, int operation, std::initializer_list<Tree*> subtrees) : lineno(lineno), operation(operation),
	children() {
	for (Tree* tree : subtrees)
		children.push_back(tree);
}
	
/* cast | object_member_access */
Tree::Tree(int lineno, int operation, const std::string &identifier, Tree* tree) : lineno(lineno),
	operation(operation), children() {
	children.push_back(identifier);
	children.push_back(tree);
}

/* instanciation */
Tree::Tree(int lineno, int operation, const std::string &identifier, const std::vector<Tree*> &params) : lineno(lineno),
	operation(operation), children() {
	children.push_back(identifier);
	for (Tree *param : params)
		children.push_back(param);
}

/* method_call */
Tree::Tree(int lineno, int operation, Tree* tree1, Tree* tree2, const std::vector<Tree*> &params) : lineno(lineno),
	operation(operation), children() {
	children.push_back(tree1);
	children.push_back(tree2);
	for (Tree *param : params)
		children.push_back(param);
}

/* object_method_call */
Tree::Tree(int lineno, int operation, const std::string &identifier, Tree* tree, const std::vector<Tree*> &params) : lineno(lineno),
	operation(operation), children() {
	children.push_back(identifier);
	children.push_back(tree);
	for (Tree *param : params)
		children.push_back(param);
}