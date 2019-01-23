#ifndef BLOCK_HPP
#define BLOCK_HPP

#include <string>
#include <vector>
#include <map>

#include "Tree.hpp"
#include "Type.hpp"
#include "Variable.hpp"

struct Block {
	std::vector<Variable*> varDecls;
	std::vector<Tree*> insts;

	Block(std::vector<Variable*> const &varDecls, std::vector<Tree*> const &insts);
	~Block() = default;

	bool correctDecl(std::map<std::string, Type*>* environnement) const;
}; 

#endif