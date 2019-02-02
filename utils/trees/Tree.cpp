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

/* cast */
Tree::Tree(int lineno, int operation, const std::string &identifier, Tree* expr) : lineno(lineno),
	operation(operation), children() {
	children.push_back(identifier);
	children.push_back(expr);
}

/* instanciation */
Tree::Tree(int lineno, int operation, const std::string &identifier, const std::vector<Tree*> &params) : lineno(lineno),
	operation(operation), children() {
	children.push_back(identifier);
	for (Tree *param : params)
		children.push_back(param);
}

	
/* member_access */
Tree::Tree(int lineno, int operation, Tree *expr, const std::string &field) : lineno(lineno),
	operation(operation), children() {
	children.push_back(expr);
	children.push_back(field);
}	

Tree::Tree(int lineno, int operation, const std::string &var, const std::string &field) : lineno(lineno),
	operation(operation), children() {
	children.push_back(var);
	children.push_back(field);
}	

	
/* method_call */
Tree::Tree(int lineno, int operation, Tree* expr, const std::string &method, const std::vector<Tree*> &params)
	: lineno(lineno), operation(operation), children() {
	children.push_back(expr);
	children.push_back(method);
	for (Tree *param : params)
		children.push_back(param);
}

Tree::Tree(int lineno, int operation, const std::string &var, const std::string &method, const std::vector<Tree*> &params)
	: lineno(lineno), operation(operation), children() {
	children.push_back(var);
	children.push_back(method);
	for (Tree *param : params)
		children.push_back(param);
}

	


