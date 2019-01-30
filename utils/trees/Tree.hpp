#ifndef TREE_HPP
#define TREE_HPP

#include <variant>
#include <vector>

#include "Block.hpp"

struct Tree;

struct Tree {
	int ligne;
	int operation;
	std::variant<std::vector<int>, std::vector<std::string>, std::vector<Block>, std::vector<Tree*>> children;
	
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

/* Pour récuperer une valeur d'un variant en particulier children. On part du principe que tu as un Tree t;
 * alors t.children est le variant.
 * alors pour récuperer le contenu tu ferras si tu que tu as un std::vector<Tree>* std::get<std::vector<*Tree>>(t.children);
 * si le type stocké dans le variant n'est pas celui ci alors ça balance une exception.
 */


#endif
