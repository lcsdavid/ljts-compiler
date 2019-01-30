#ifndef TREE_HPP
#define TREE_HPP

#include <string>
#include <variant>
#include <vector>

struct Block;
struct Tree;

struct Tree {
	int lineno;
	int operation;
	std::vector<std::variant<int, std::string, Block*, Tree*>> children;
	
	/* Return. */
	Tree(int lineno, int operation);			
	/* Constante entière. */
	Tree(int lineno, int operation, int value);					
	/* Constante string ou identifier. */
	Tree(int lineno, int operation, const std::string &value);	
	/* Block. */
	Tree(int lineno, int operation, Block *block);				
	/* Constructeur w/ sub-Trees. */
	Tree(int lineno, int operation, std::initializer_list<Tree*> children);	
	
	/* Member acess. */
	Tree(int lineno, int operation, const std::string &identifier, Tree* children);	
	
	/* Method call. */
	Tree(int lineno, int operation, const std::string &value, Tree* children, Tree *params);	
	
	Tree(const Tree &other) = default;
	Tree &operator=(const Tree &other) = default;
	
	~Tree() = default;
};

/* Pour récuperer une valeur d'un variant en particulier children. On part du principe que tu as un Tree t;
 * alors t.children est le variant.
 * alors pour récuperer le contenu tu ferras si tu que tu as un std::vector<Tree>* std::get<std::vector<*Tree>>(t.children);
 * si le type stocké dans le variant n'est pas celui ci alors ça balance une exception.
 */


#endif
