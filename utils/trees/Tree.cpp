#include "Tree.hpp"

#include <algorithm>

#include "../../optype.hpp"
#include "../types/Type.hpp"
#include "Block.hpp"
#include "../types/Method.hpp"

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
			if(env.env.find(std::get<std::string>(this->children.at(0)))==env.env.end()){
				std::cout << " Vous essayez d'instancier un type qui n'existe pas à la ligne : "<<lineno << " ! " <<std::endl;
				return lineno;
			}
				
			//on doit maintenant vérifier qu'on instancie pas un objet
			if((env.env[std::get<std::string>(this->children.at(0))])->isStatic()){
				std::cout<<"Vous ne pouvez pas instancier un objet : ligne " << this->lineno << std::endl;
				return lineno;
			}
			break;
		case cast:
			this->getType(env);// vu que getType fait déjà la vérification
			break;
		case member_access:{
			Type *type = env.env.at(std::get<std::string>(children.at(0)));
			type->field(std::get<std::string>(children.at(1)));
			return true;
		}
		case static_member_access: {
			Type *type = env.env.at(std::get<std::string>(children.at(0)));
			if (!type->isStatic()) {
				std::cout << "\033[91merror:\033[0m static member access '" << std::get<std::string>(children.at(1))
					<< "' from non static type '" << type->identifier << "'" << std::endl;
				return false;
			}
			type->field(std::get<std::string>(children.at(1)));
			return true;
		}
		case method_call:{
			Type *type = env.env.at(std::get<Tree*>(children.at(0))->getType(env));
			Method method = type->method(std::get<std::string>(children.at(1)));
			if (children.size() - 2 != method.parameters.size()) {
				std::cout << "\033[91merror:\033[0m '" << type->identifier << "' has no method named '" 
					<< std::get<std::string>(children.at(1)) << "'" << std::endl;
				return false;
			}
			for (std::size_t i = 0; i < children.size(); i++) {
				if (std::get<Tree*>(children.at(i + 2))->getType(env) != method.parameters.at(i).typeIdentifier) {
					std::cout << "\033[91merror:\033[0m '" << type->identifier << "' has no method '" 
						<< std::get<std::string>(children.at(1)) << "'" << std::endl;
					for (std::size_t i = 2; i < children.size(); i++) {
						std::cout << std::get<Tree*>(children.at(i + 2))->getType(env);
						if (i == children.size() - 1)
							std::cout << ", ";
					}
					std::cout << ") ";
					return false;
				}
			}
			break;
		}
		case static_method_call: {
			Type *type = env.env.at(std::get<Tree*>(children.at(0))->getType(env));
			if (!type->isStatic()) {
				std::cout << "\033[91merror:\033[0m static method call from non static type '" << type->identifier << "'" << std::endl;
				return false;
			}
			Method method = type->method(std::get<std::string>(children.at(1)));
			for (std::size_t i = 0; i < children.size(); i++) {
				if (std::get<Tree*>(children.at(i + 2))->getType(env) != method.parameters.at(i).typeIdentifier) {
					std::cout << "\033[91merror:\033[0m '" << type->identifier << "' has no method '" 
						<< std::get<std::string>(children.at(1)) << "'" << std::endl;
					for (std::size_t i = 2; i < children.size(); i++) {
						std::cout << std::get<Tree*>(children.at(i + 2))->getType(env);
						if (i == children.size() - 1)
							std::cout << ", ";
					}
					std::cout << ") ";
					return false;
				}
			}
			return true;
		}
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
			if(this->isCorrect(env) != -1){
				//TODO
				return "";
			}
			return std::get<std::string>(this->children.at(0));
			break;
		case cast:
		if(this->isCorrect(env) != -1){
				//TODO
				return "";
			}
			return std::get<std::string>(this->children.at(0));
			break;
		case member_access: {
			if(this->isCorrect(env) != -1){
				//TODO
				return "";
			}
			Type *type = env.env.at(std::get<Tree*>(this->children.at(0))->getType(env));
			return type->field(std::get<std::string>(children.at(1))).typeIdentifier;
		}
		case static_member_access: {
			if (!env.env.count(std::get<std::string>(children.at(0)))) {
				std::cout << "type inconnue " << lineno;
				return "error";
			}
			Type *type = env.env.at(std::get<std::string>(children.at(0)));
			return type->field(std::get<std::string>(children.at(1))).typeIdentifier;
		}
		case method_call:{
			if(this->isCorrect(env) != -1){
				//TODO
				return "";
			}
			std::string type = (std::get<Tree*>(this->children.at(0)))->getType(env);
				
			for(size_t i = 0; i < env.env[type]->methods.size(); i++){
					if(env.env[type]->methods.at(i).identifier == std::get<std::string>(this->children.at(1)))
						return env.env[type]->methods.at(i).returnTypeIdentifier;
				
			}
			break;
			}
		case static_method_call: {
			if (!env.env.count(std::get<std::string>(children.at(0)))) {
				std::cout << "type inconnue " << lineno;
				return "error";
			}
			Type *type = env.env.at(std::get<std::string>(children.at(0)));
			auto itMethod = std::find_if(type->methods.begin(), type->methods.end(), [&] (const Method &method) {
					return method.identifier != std::get<std::string>(children.at(1)); 
				});
			if(itMethod == type->methods.end()) {
				//dans ce cas on essaie d'appeler une methode qui n'existe pas
				std::cout<<"la fonction " << std::get<std::string>(this->children.at(1)) << " n'existe pas (ou n'a pas les bons arguments) pour le type "<<type<<". Ligne : "<<lineno;
				return "error";
			}
			return (*itMethod).returnTypeIdentifier;
			break;
		}
		case assignment: {
			if(this->isCorrect(env) != -1){
				//TODO
				return "";
			}
			std::string lhs = std::get<Tree*>(children.at(0))->getType(env),
				rhs = std::get<Tree*>(children.at(1))->getType(env);
			if (lhs != rhs)
				std::cout << "error: tu essaye de mettre " << rhs << " dans " << lhs << std::endl;
			return lhs;
		}
		case unary_plus:
			if(this->isCorrect(env) != -1){
				//TODO
				return "";
			}
			return "Integer";
		case unary_minus:
			if(this->isCorrect(env) != -1){
				//TODO
				return "";
			}
			return "Integer";
		case multiplication:
			if(this->isCorrect(env) != -1){
				//TODO
				return "";
			}
			return "Integer";
		case division:
			if(this->isCorrect(env) != -1){
				//TODO
				return "";
			}
			return "Integer";
		case addition:
			if(this->isCorrect(env) != -1){
				//TODO
				return "";
			}
			return "Integer";
		case substraction:
			if(this->isCorrect(env) != -1){
				//TODO
				return "";
			}
			return "Integer";
		case less_strict:
			if(this->isCorrect(env) != -1){
				//TODO
				return "";
			}
			return "Integer";
		case less_equal:
			if(this->isCorrect(env) != -1){
				//TODO
				return "";
			}
			return "Integer";
		case greater_strict:
			if(this->isCorrect(env) != -1){
				//TODO
				return "";
			}
			return "Integer";
		case greater_equal:
			if(this->isCorrect(env) != -1){
				//TODO
				return "";
			}
			return "Integer";
		case equal:
			if(this->isCorrect(env) != -1){
				//TODO
				return "";
			}
			return "Integer";
		case not_equal:
			if(this->isCorrect(env) != -1){
				//TODO
				return "";
			}
			return "Integer";
		case integer:
			if(this->isCorrect(env) != -1){
				//TODO
				return "";
			}
			return "Integer";
		case string:
			if(this->isCorrect(env) != -1){
				//TODO
				return "";
			}
			return "String";
		case identifier:
			if(this->isCorrect(env) != -1){
				//TODO
				return "";
			}
			return std::get<std::string>(children.at(0));
		default:
			return "";
	}
	return "";
}

std::ostream &Tree::generateAsm(std::ostream &os, Environment& env) {
	switch (operation) {
		case instanciation:
			break;
		case cast:
			break;
		case member_access:
			break;
		case static_member_access:
			break;
		case method_call:

			break;
		case static_method_call:
			
			break;
		case assignment:
			break;
		case unary_plus:
			std::get<Tree*>(children[0])->generateAsm(os, env);
			break;
		case unary_minus:
			os << "PUSHI 0" << std::endl;
			std::get<Tree*>(children[0])->generateAsm(os, env);
			os << "SUB";
			break;
		case multiplication:
			std::get<Tree*>(children[0])->generateAsm(os, env);
			std::get<Tree*>(children[1])->generateAsm(os, env);
			os << "MUL";
			break;
		case division:
			std::get<Tree*>(children[0])->generateAsm(os, env);
			std::get<Tree*>(children[1])->generateAsm(os, env);
			os << "DIV";
			break;
		case addition:
			std::get<Tree*>(children[0])->generateAsm(os, env);
			std::get<Tree*>(children[1])->generateAsm(os, env);
			os << "ADD";
			break;
		case substraction:
			std::get<Tree*>(children[0])->generateAsm(os, env);
			std::get<Tree*>(children[1])->generateAsm(os, env);
			os << "SUB";
			break;
		case less_strict:
			std::get<Tree*>(children[0])->generateAsm(os, env);
			std::get<Tree*>(children[1])->generateAsm(os, env);
			os << "INF";
			break;
		case less_equal:
			std::get<Tree*>(children[0])->generateAsm(os, env);
			std::get<Tree*>(children[1])->generateAsm(os, env);
			os << "INFEQ";
			break;
		case greater_strict:
			std::get<Tree*>(children[0])->generateAsm(os, env);
			std::get<Tree*>(children[1])->generateAsm(os, env);
			os << "SUP";
			break;
		case greater_equal:
			std::get<Tree*>(children[0])->generateAsm(os, env);
			std::get<Tree*>(children[1])->generateAsm(os, env);
			os << "SUPEQ";
			break;
		case equal:
			std::get<Tree*>(children[0])->generateAsm(os, env);
			std::get<Tree*>(children[1])->generateAsm(os, env);
			os << "EQUAL";
			break;
		case not_equal:
			std::get<Tree*>(children[0])->generateAsm(os, env);
			std::get<Tree*>(children[1])->generateAsm(os, env);
			os << "EQUAL" << std::endl << "NOT";
			break;
		case if_then_else:
			break;
		case return_call:
			break;
		case integer:
			os << "PUSHI " << std::get<int>(children[0]);
			break;
		case string:
			os << "PUSHS " << std::get<std::string>(children[0]);
			break;
		case identifier:
			break;
		default:
			os << "\033[91mundefined\033[0m";
	}
	return os << std::endl;
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
	


