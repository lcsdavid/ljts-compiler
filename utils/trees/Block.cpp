#include "Block.hpp"

#include "../types/Type.hpp"
#include "Tree.hpp"

Block::Block(std::vector<Variable> const &varDecls, std::vector<Tree*> const &insts): varDecls(varDecls), insts(insts) {}

bool Block::isCorrect(Environment &env) const {/* Dans le cas d'un bloc */
    if(!varDecls.empty()) {
		for (Variable const &varDecl : varDecls) {
			if(env.env.find(varDecl.identifier) == env.env.end())
				return false;
			else
				env.fields.push_back(varDecl);
		}
	}
	
	for(size_t i = 0; i < this->insts.size(); i++){
		if(this->insts.at(i)->isCorrect(env) != -1){
			std::cout << "Problème à la ligne " << this->insts.at(i)->isCorrect(env);
			return false;
		}
	}
	
	for(size_t i =0; i < varDecls.size(); i++){
		env.fields.pop_back();
	}
	
    return true;
}

std::ostream &operator<<(std::ostream &os, const Block &b) {
	os << "block:" << std::endl;
	for (auto it = b.varDecls.begin(); it != b.varDecls.end(); it++)
		os << "  " << *it << std::endl;
	std::cout << "---" << std::endl;
	for (auto it = b.insts.begin(); it != b.insts.end(); it++)
		os << "  " << **it << ';' << std::endl;
	return os;
}
