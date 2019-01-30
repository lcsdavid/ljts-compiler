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
	
	/* return_call */
	Tree(int lineno, int operation);			
	/* integer */
	Tree(int lineno, int operation, int value);					
	/* string | identifier */
	Tree(int lineno, int operation, const std::string &value);	
	/* inst_block */
	Tree(int lineno, int operation, Block *block);			
	/* subtrees > operators | member_access */
	Tree(int lineno, int operation, std::initializer_list<Tree*> children);	
	
	/* cast | object_member_access */
	Tree(int lineno, int operation, const std::string &identifier, Tree* tree);	
	/* instanciation */
	Tree(int lineno, int operation, const std::string &identifier, const std::vector<Tree*> &params);	
	
	/* method_call */
	Tree(int lineno, int operation, Tree* tree1, Tree* tree2, const std::vector<Tree*> &params);	
	/* object_method_call */
	Tree(int lineno, int operation, const std::string &identifier, Tree* tree, const std::vector<Tree*> &params);	
	
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
