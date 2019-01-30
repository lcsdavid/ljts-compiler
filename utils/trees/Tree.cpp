#include "Tree.hpp"

#include "Block.hpp"

Tree::Tree(int lineno, int operation) : lineno(lineno), operation(operation) {}

Tree::Tree(int lineno, int operation, int value) : lineno(lineno), operation(operation), children({value}) {}

Tree::Tree(int lineno, int operation, const std::string &value) : lineno(lineno), operation(operation),
	children({value}) {}
	
Tree::Tree(int lineno, int operation, Block* block) : lineno(lineno), operation(operation), children({block}) {}
	
Tree::Tree(int lineno, int operation, std::initializer_list<Tree*> children) : lineno(lineno), operation(operation),
	children() {
	for (Tree* tree : children)
		this->children.push_back(tree);
}
	
Tree::Tree(int lineno, int operation, const std::string &identifier, Tree *params) : lineno(lineno),
	operation(operation), children() {
	children.push_back(identifier);
	children.push_back(params);
}