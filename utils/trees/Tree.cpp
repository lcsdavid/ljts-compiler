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
			
			std::string type = (std::get<Tree*>(this->children.at(0)))->getType(env);
			
			if(std::find_if(env.env[type]->fields.begin(), env.env[type]->fields.end(), [&] (const Variable &var) { return var.identifier == std::get<std::string>(children.at(1)); })  != env.env[type]->fields.end()) {
				return -1;
			} 
			std::cout<<"l'argument " << std::get<std::string>(this->children.at(1)) << " n'existe pas pour le type "<<type<<". Ligne : "<<lineno;
			break;
		}
		case static_member_access: {
			if (!env.env.count(std::get<std::string>(children.at(0)))) {
				std::cout << "type inconnue " << lineno;
				return lineno;
			}
			Type *type = env.env.at(std::get<std::string>(children.at(0)));
			if (!type->isStatic()) {
				std::cout << "appel static pas static " << lineno;
				return lineno;
			}
			auto itVar = std::find_if(type->fields.begin(), type->fields.end(), [&] (const Variable &var) { return var.identifier == std::get<std::string>(children.at(1)); });
			if(itVar == type->fields.end()) {
				std::cout << "pas de champ de ce nom" << lineno;
				return lineno;
			}
			return -1; /* ok */
		}
		case method_call:{

			std::string type = (std::get<Tree*>(this->children.at(0)))->getType(env);
			if(env.env.find(type) == env.env.end())
				return this->lineno;
			Method meth = env.env[type]->know(std::get<std::string>(this->children.at(1)));
			size_t i = 0;
			for (auto it = this->children.begin() + 2; it != this->children.end(); it++) {
				if( i >= meth.parameters.size())
					break;//on vérifie qu'on est toujours dans la taille de meth
				if((*std::get<Tree*>(*it)).getType(env) != meth.parameters.at(i).typeIdentifier)
					break;//on vérifie que les types des arguments sont les bons
				i++;
			}
			if(i == meth.parameters.size())//si on a le bon nombre de parametres
				return -1;
			//dans ce cas on essaie d'appeler une methode qui n'existe pas
			std::cout<<"la fonction " << std::get<std::string>(this->children.at(1)) << " n'existe pas (ou n'a pas les bons arguments) pour le type "<<type<<". Ligne : "<<lineno;
			
			break;
		}
		case static_method_call: {
			if (!env.env.count(std::get<std::string>(children.at(0)))) {
				std::cout << "type inconnue " << lineno;
				return lineno;
			}
			Type *type = env.env.at(std::get<std::string>(children.at(0)));
			if (!type->isStatic()) {
				std::cout << "appel static pas static " << lineno;
				return lineno;
			}
			auto itMethod = std::find_if(type->methods.begin(), type->methods.end(), [&] (const Method &method) {
					if (method.identifier != std::get<std::string>(children.at(1)))
						return false;
					if (children.size() - 2 != method.parameters.size())
						return false;
					for (std::size_t i = 0; i < children.size(); i++) {
						if (std::get<Tree*>(children.at(i + 2))->getType(env) != method.parameters.at(i).typeIdentifier)
							return false;
					}
					return true;
				});
			if(itMethod == type->methods.end()) {
				//dans ce cas on essaie d'appeler une methode qui n'existe pas
				std::cout<<"la fonction " << std::get<std::string>(this->children.at(1)) << " n'existe pas (ou n'a pas les bons arguments) pour le type "<<type<<". Ligne : "<<lineno;
				return lineno;
			}
			return -1; /* ok */
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
		case member_access:{
			if(this->isCorrect(env) != -1){
				//TODO
				return "";
			}
			std::string type = (std::get<Tree*>(this->children.at(0)))->getType(env);
				
			for(size_t i = 0; i < env.env[type]->fields.size(); i++){
					if(env.env[type]->fields.at(i).identifier == std::get<std::string>(this->children.at(1)))
						return env.env[type]->fields.at(i).typeIdentifier;
				
			}
			break;
		}
		case static_member_access:{
			if(this->isCorrect(env) != -1){
				//TODO
				return "";
			}
			std::string type = (*(env.fields.find(std::get<std::string>(this->children.at(0)))).typeIdentifier);
			for(size_t i = 0; i < env.env[type]->fields.size(); i++){
					if(env.env[type]->fields.at(i).identifier == std::get<std::string>(this->children.at(1)))
						return env.env[type]->fields.at(i).typeIdentifier;
				
			}
			break;
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
		case static_method_call:{
			if(this->isCorrect(env) != -1){
				//TODO
				return "";
			}
			std::string type = (*(env.fields.find(std::get<std::string>(this->children.at(0)))).typeIdentifier);
				
			for(size_t i = 0; i < env.env[type]->methods.size(); i++){
					if(env.env[type]->methods.at(i).identifier == std::get<std::string>(this->children.at(1)))
						return env.env[type]->methods.at(i).returnTypeIdentifier;
				
			}
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
	std::vector<Assignee> tempo;
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
			std::get<Tree*>(tree->children[0])->generateAsm(os);
			break;
		case unary_minus:
			os << "PUSHI 0" << std::endl;
			std::get<Tree*>(tree->children[0])->generateAsm(os);
			os << "SUB";
			break;
		case multiplication:
			std::get<Tree*>(tree->children[0])->generateAsm(os);
			std::get<Tree*>(tree->children[1])->generateAsm(os);
			os << "MUL";
			break;
		case division:
			std::get<Tree*>(tree->children[0])->generateAsm(os);
			std::get<Tree*>(tree->children[1])->generateAsm(os);
			os << "DIV";
			break;
		case addition:
			std::get<Tree*>(tree->children[0])->generateAsm(os);
			std::get<Tree*>(tree->children[1])->generateAsm(os);
			os << "ADD";
			break;
		case substraction:
			std::get<Tree*>(tree->children[0])->generateAsm(os);
			std::get<Tree*>(tree->children[1])->generateAsm(os);
			os << "SUB";
			break;
		case less_strict:
			std::get<Tree*>(tree->children[0])->generateAsm(os);
			std::get<Tree*>(tree->children[1])->generateAsm(os);
			os << "INF";
			break;
		case less_equal:
			std::get<Tree*>(tree->children[0])->generateAsm(os);
			std::get<Tree*>(tree->children[1])->generateAsm(os);
			os << "INFEQ";
			break;
		case greater_strict:
			std::get<Tree*>(tree->children[0])->generateAsm(os);
			std::get<Tree*>(tree->children[1])->generateAsm(os);
			os << "SUP";
			break;
		case greater_equal:
			std::get<Tree*>(tree->children[0])->generateAsm(os);
			std::get<Tree*>(tree->children[1])->generateAsm(os);
			os << "SUPEQ";
			break;
		case equal:
			std::get<Tree*>(tree->children[0])->generateAsm(os);
			std::get<Tree*>(tree->children[1])->generateAsm(os);
			os << "EQUAL";
			break;
		case not_equal:
			std::get<Tree*>(tree->children[0])->generateAsm(os);
			std::get<Tree*>(tree->children[1])->generateAsm(os);
			os << "EQUAL" << std::endl << "NOT";
			break;
		case if_then_else:
			break;
		case return_call:
			break;
		case integer:
			os << "PUSHI " << std::get<int>(tree->children[0]);
			break;
		case string:
			os << "PUSHS " << std::get<std::string>(tree->children[0]);
			break;
		case identifier:
			break;
		default:
			os << "\033[91mundefined\033[0m";
	}
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
	


