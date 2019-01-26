#ifndef TREE_HPP
#define TREE_HPP

#include <variant>
#include <vector>

#include "Block.hpp"
#include "../types/Type.hpp"

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
	
	//renvoie une string correspondant au type de l'arbre si ça a un sens(exemple: 2+2) "" sinon.
	std::string getType(std::map<std::string, Type*> &env, std::vector<Variable> envVar);
	
	//renvoie vrai si l'arbre est correct, false sinon
	bool isCorrect(std::map<std::string, Type*> &env, std::vector<Variable> envVar);
	
	Tree(Tree const &other) = default;
	~Tree() = default;
};


#endif

/*
std::string Type::getType(std::map<std::string, Type*> &env, std::vector<Variable> envVar){
	std::string res = "";
	
	return res;	
}
	
//renvoie vrai si l'arbre est correct, false sinon
bool Type::isCorrect(std::map<std::string, Type*> &env, std::vector<Variable> envVarr){
	
	
	return false;
}*/