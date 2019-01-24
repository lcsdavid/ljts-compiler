#ifndef TREE_HPP
#define TREE_HPP

#include <variant>
#include <vector>

#include "Block.hpp"

struct Tree;

struct Tree {
	int ligne;
	int operation;
	std::vector<std::variant<int, std::string, Block, Tree*>> children;
	
	explicit Tree(int integer);			/* Constante entière. */
	explicit Tree(std::string string);	/* Constante string. */
	
	Tree(int operation, Tree *rhs);				/* Opérateur unaire. */
	Tree(int operation, Tree *lhs, Tree *rhs);	/* Opérateur binaire. */
	
	Tree(std::string const &lhs, Tree *rhs); /* Cast. */
	
	//Tree(ConstructorCall const &constructorCall);	/* Appel d'un constructeur. */
	Tree(std::string const& typeIdentifier);
	//Tree(MethodCall const &methodCall);				/* Appel d'une méthode. */
	
	
	
	Tree(Tree const &other) = default;
	~Tree() = default;
};


#endif
