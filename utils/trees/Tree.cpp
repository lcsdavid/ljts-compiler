#include "Tree.hpp"

#include <algorithm>

#include "../../optype.hpp"
#include "../types/Type.hpp"
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
	switch (operation) {
		case instanciation:
			//TODO
			break;
		case cast:
			//TODO
			break;
		case member_access:
			//TODO
			break;
		case static_member_access:
			//TODO
			break;
		case method_call:
			//TODO
			break;
		case static_method_call:
			if(env.env.find(std::get<std::string>(this->children.at(0))) == env.env.end())
				return this->lineno;
			
			//TODO
			
			break;
		case assignment: {
			this->getType(env);
			return -1;
		}
		case unary_plus:
			if(std::get<Tree*>(children.at(0))->getType(env) != "Integer" || std::get<Tree*>(children.at(1))->getType(env) != "Integer" )
				return -1;
			return this->lineno;
		case unary_minus:
			if(std::get<Tree*>(children.at(0))->getType(env) != "Integer" || std::get<Tree*>(children.at(1))->getType(env) != "Integer" )
				return -1;
			return this->lineno;
		case multiplication:
			if(std::get<Tree*>(children.at(0))->getType(env) != "Integer" || std::get<Tree*>(children.at(1))->getType(env) != "Integer" )
				return -1;
			return this->lineno;
		case division:
			if(std::get<Tree*>(children.at(0))->getType(env) != "Integer" || std::get<Tree*>(children.at(1))->getType(env) != "Integer" )
				return -1;
			return this->lineno;
		case addition:
			if(std::get<Tree*>(children.at(0))->getType(env) != "Integer" || std::get<Tree*>(children.at(1))->getType(env) != "Integer" )
				return -1;
			return this->lineno;
		case substraction:
			if(std::get<Tree*>(children.at(0))->getType(env) != "Integer" || std::get<Tree*>(children.at(1))->getType(env) != "Integer" )
				return -1;
			return this->lineno;
		case less_strict:
			if(std::get<Tree*>(children.at(0))->getType(env) != "Integer" || std::get<Tree*>(children.at(1))->getType(env) != "Integer" )
				return -1;
			return this->lineno;
		case less_equal:
			if(std::get<Tree*>(children.at(0))->getType(env) != "Integer" || std::get<Tree*>(children.at(1))->getType(env) != "Integer" )
				return -1;
			return this->lineno;
		case greater_strict:
			if(std::get<Tree*>(children.at(0))->getType(env) != "Integer" || std::get<Tree*>(children.at(1))->getType(env) != "Integer" )
				return -1;
			return this->lineno;
		case greater_equal:
			if(std::get<Tree*>(children.at(0))->getType(env) != "Integer" || std::get<Tree*>(children.at(1))->getType(env) != "Integer" )
				return -1;
			return this->lineno;
		case equal:
			if(std::get<Tree*>(children.at(0))->getType(env) != "Integer" || std::get<Tree*>(children.at(1))->getType(env) != "Integer" )
				return -1;
			return this->lineno;
		case not_equal:
			if(std::get<Tree*>(children.at(0))->getType(env) != "Integer" || std::get<Tree*>(children.at(1))->getType(env) != "Integer" )
				return -1;
			return this->lineno;
		case integer:
			return -1;
		case string:
			return -1;
		case identifier:
			if (std::find_if(env.fields.begin(), env.fields.end(), [&](const Variable &var) { 
				return var.identifier == std::get<std::string>(children.at(0)); }) != env.fields.end())
				return -1;
			else 
				return this->lineno;
		default:
			return -1;
	}
	return -1;
}


std::string Tree::getType(Environment& env){
	switch (operation) {
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
		case assignment: {
			std::string lhs = std::get<Tree*>(children.at(0))->getType(env),
				rhs = std::get<Tree*>(children.at(1))->getType(env);
			if (lhs != rhs)
				std::cout << "error: tu essaye de mettre " << rhs << " dans " << lhs << std::endl;
			return lhs;
		}
		case unary_plus:
			return "Integer";
		case unary_minus:
			return "Integer";
		case multiplication:
			return "Integer";
		case division:
			return "Integer";
		case addition:
			return "Integer";
		case substraction:
			return "Integer";
		case less_strict:
			return "Integer";
		case less_equal:
			return "Integer";
		case greater_strict:
			return "Integer";
		case greater_equal:
			return "Integer";
		case equal:
			return "Integer";
		case not_equal:
			return "Integer";
		case integer:
			return "Integer";
		case string:
			return "String";
		case identifier:
			return std::get<std::string>(children.at(0));
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
	return os;
}
	


