#ifndef BLOCK_HPP
#define BLOCK_HPP

#include <string>
#include <vector>
#include <map>

#include "../variables/Variable.hpp"

struct Type;
struct Tree;

struct Block {
	std::vector<Variable> varDecls;
	std::vector<Tree*> insts;

	Block(std::vector<Variable> const &varDecls, std::vector<Tree*> const &insts);
	~Block() = default;

	bool correctDecl(std::map<std::string, Type*> &env, std::vector<Variable> envVar) const;

}; 

#endif