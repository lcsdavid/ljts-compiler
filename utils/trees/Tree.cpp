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

int Tree::isCorrect(Environment& env){
	switch(this->operation){
		case 258:
		
		break;
		case 259 :
		
		break;
		case 260:
		
		break;
		case 261 :
		
		break;
		case 262:
		
		break;
		case 263 :
			for(size_t i; i < env.fields.size(); i++){
				if(env.fields.at(i).identifier == (std::string)this->children)
					return -1;//l'identifier appartient effectivement à la liste des variables connues
			}
			return this->lineno;
		
		break;
		case 264:
		
		break;
		case 265 :
		
		break;
		case 266:
		
		break;
		case 267 :
		
		break;
		case 268:
		
		break;
		case 269 :
		
		break;
		case 270:
		
		break;
		case 271 :
		
		break;
		case 272:
		
		break;
		case 273 :
		
		break;
		case 274:
		
		break;
		case 275 :
		
		break;
		case 276:
		
		break;
		case 277 :
		
		break;
		
		
	}

	return -1;
}


	


