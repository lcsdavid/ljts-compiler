#include "Tree.hpp"

#include "../../optype.hpp"

#include "Block.hpp"
#include "../types/Type.hpp"

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
	switch(operation){
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
		case 263:
			for(size_t i; i < env.fields.size(); i++){
				if (env.fields.at(i).identifier == std::get<std::string>(children.at(0)))
					return -1; //l'identifier appartient effectivement à la liste des variables connues
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
			return -1;
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


std::string Tree::getType(Environment& env){
	switch (this->operation) {
		case instanciation:
			return std::get<std::string>(this->children.at(0));
			break;
		case cast:
		if(this->isCorrect(env) != -1){
				//TODO
				return "";
			}
			return std::get<std::string>(this->children.at(0));
			break;
		case member_access:
			if(this->isCorrect(env) != -1){
				//TODO
				return "";
			}
				
			for(size_t i = 0; i < env.env[(std::get<Tree*>(this->children.at(0)))->getType(env)]->fields.size(); i++){
					if(env.env[(std::get<Tree*>(this->children.at(0)))->getType(env)]->fields.at(i).identifier == std::get<std::string>(this->children.at(1)))
						return env.env[(std::get<Tree*>(this->children.at(0)))->getType(env)]->fields.at(i).typeIdentifier;
				
			}
			break;
		case static_member_access:
			if(this->isCorrect(env) != -1){
				//TODO
				return "";
			}
				
			for(size_t i = 0; i < env.env[std::get<std::string>(this->children.at(0))]->fields.size(); i++){
					if(env.env[std::get<std::string>(this->children.at(0))]->fields.at(i).identifier == std::get<std::string>(this->children.at(1)))
						return env.env[std::get<std::string>(this->children.at(0))]->fields.at(i).typeIdentifier;
				
			}
			break;
		case method_call:
			if(this->isCorrect(env) != -1){
				//TODO
				return "";
			}
				
			for(size_t i = 0; i < env.env[(std::get<Tree*>(this->children.at(0)))->getType(env)]->methods.size(); i++){
					if(env.env[(std::get<Tree*>(this->children.at(0)))->getType(env)]->methods.at(i).identifier == std::get<std::string>(this->children.at(1)))
						return env.env[(std::get<Tree*>(this->children.at(0)))->getType(env)]->methods.at(i).returnTypeIdentifier;
				
			}
			break;
		case static_method_call:
			if(this->isCorrect(env) != -1){
				//TODO
				return "";
			}
				
			for(size_t i = 0; i < env.env[std::get<std::string>(this->children.at(0))]->methods.size(); i++){
					if(env.env[std::get<std::string>(this->children.at(0))]->methods.at(i).identifier == std::get<std::string>(this->children.at(1)))
						return env.env[std::get<std::string>(this->children.at(0))]->methods.at(i).returnTypeIdentifier;
				
			}
			break;
		case assignment:
			std::string lhs = std::get<Tree*>(children.at(0))->getType(env); /* Type à gauche. */
			std::string rhs = std::get<Tree*>(children.at(1))->getType(env); /* Type à droite. */
			if (lhs != rhs)
				std::cout << "error: tu essaye de mettre " << rhs << " dans " << lhs << std::endl;
			return lhs;
		case unary_plus:
			return "int";
			break;
		case unary_minus:
			return "int";
			break;
		case multiplication:
			return "int";
			break;
		case division:
			return "int";
			break;
		case addition:
			return "int";
			break;
		case substraction:
			return "int";
			break;
		case less_strict:
			return "bool";
			break;
		case less_equal:
			return "bool";
			break;
		case greater_strict:
			return "bool";
			break;
		case greater_equal:
			return "bool";
			break;
		case equal:
			return "bool";
			break;
		case not_equal:
			return "bool";
			break;
		case if_then_else:
			return "";
			break;
		case return_call:
			return "";
			break;
		case integer:
			return "integer";
			break;
		case string:
			return "string";
			break;
		case identifier:
			return std::get<std::string>(children.at(0));
			break;
		default:
			return "";
	}

	return "";
}

std::ostream &operator<<(std::ostream &os, const Tree &t) {
	switch (t.operation) {
		case instanciation:
			os << "new " << std::get<std::string>(t.children.at(0));
			break;
		case cast:
			os << '(' << std::get<std::string>(t.children.at(0)) << " " << *std::get<Tree*>(t.children.at(1));
			break;
		case member_access:
			os << *std::get<Tree*>(t.children.at(0)) << '.' << std::get<std::string>(t.children.at(1));
			break;
		case static_member_access:
			os << std::get<std::string>(t.children.at(0)) << '.' << std::get<std::string>(t.children.at(1));
			break;
		case method_call:
			os << *std::get<Tree*>(t.children.at(0)) << '.' << std::get<std::string>(t.children.at(1)) << '(';
			for (auto it = t.children.begin() + 2; it != t.children.end(); it++) {
				os << *std::get<Tree*>(*it);
				if (it != t.children.end() - 1)
					os << ", ";
			}
			os << ')';
			break;
		case static_method_call:
			os << std::get<std::string>(t.children.at(0)) << '.' << std::get<std::string>(t.children.at(1)) << '(';
			for (auto it = t.children.begin() + 2; it != t.children.end(); it++) {
				os << *std::get<Tree*>(*it);
				if (it != t.children.end() - 1)
					os << ", ";
			}
			os << ')';
			break;
		case assignment:
			os << *std::get<Tree*>(t.children.at(0)) << " := " << *std::get<Tree*>(t.children.at(1));
			break;
		case unary_plus:
			os << "+ " << *std::get<Tree*>(t.children.at(0));
			break;
		case unary_minus:
			os << "- " << *std::get<Tree*>(t.children.at(0));
			break;
		case multiplication:
			os << *std::get<Tree*>(t.children.at(0)) << " * " << *std::get<Tree*>(t.children.at(1));
			break;
		case division:
			os << *std::get<Tree*>(t.children.at(0)) << " / " << *std::get<Tree*>(t.children.at(1));
			break;
		case addition:
			os << *std::get<Tree*>(t.children.at(0)) << " + " << *std::get<Tree*>(t.children.at(1));
			break;
		case substraction:
			os << *std::get<Tree*>(t.children.at(0)) << " - " << *std::get<Tree*>(t.children.at(1));
			break;
		case less_strict:
			os << *std::get<Tree*>(t.children.at(0)) << " < " << *std::get<Tree*>(t.children.at(1));
			break;
		case less_equal:
			os << *std::get<Tree*>(t.children.at(0)) << " <= " << *std::get<Tree*>(t.children.at(1));
			break;
		case greater_strict:
			os << *std::get<Tree*>(t.children.at(0)) << " > " << *std::get<Tree*>(t.children.at(1));
			break;
		case greater_equal:
			os << *std::get<Tree*>(t.children.at(0)) << " >= " << *std::get<Tree*>(t.children.at(1));
			break;
		case equal:
			os << *std::get<Tree*>(t.children.at(0)) << " = " << *std::get<Tree*>(t.children.at(1));
			break;
		case not_equal:
			os << *std::get<Tree*>(t.children.at(0)) << " <> " << *std::get<Tree*>(t.children.at(1));
			break;
		case if_then_else:
			os << "if (" << *std::get<Tree*>(t.children.at(0)) << ')' << std::endl 
				<< "---then" << std::endl << *std::get<Tree*>(t.children.at(1)) << ";--- " << std::endl
				<< "---else" << std::endl << *std::get<Tree*>(t.children.at(2)) << ";--- " << std::endl;
			break;
		case return_call:
			os << "return;";
			break;
		case integer:
			os << std::get<int>(t.children.at(0));
			break;
		case string:
			os << std::get<std::string>(t.children.at(0));
			break;
		case identifier:
			os << std::get<std::string>(t.children.at(0));
			break;
		default:
			os << "\033[91mundefined\033[0m";
	}
	
}
	


