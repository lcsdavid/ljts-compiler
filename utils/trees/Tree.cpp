#include "Tree.hpp"

#include "Block.hpp"

Tree::Tree(int lineno, int operation) : lineno(lineno), operation(operation) {}

Tree::Tree(int lineno, int operation, int value) : lineno(lineno), operation(operation), children({value}) {}

Tree::Tree(int lineno, int operation, const std::string &value) : lineno(lineno), operation(operation),
	children({value}) {}
	
Tree::Tree(int lineno, int operation, Block* block) : lineno(lineno), operation(operation), children({block}) {}
	
Tree::Tree(int lineno, int operation, std::initializer_list<std::variant<int, std::string, Block*, Tree*>> children) : 
	lineno(lineno), operation(operation), children(children) {}