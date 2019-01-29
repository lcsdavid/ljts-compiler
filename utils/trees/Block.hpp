#ifndef BLOCK_HPP
#define BLOCK_HPP

#include <string>
#include <vector>
#include <map>

#include "../variables/Parameter.hpp"

struct Type;
struct Tree;

struct Block {
	std::vector<Parameter> varDecls;
	std::vector<Tree*> insts;

	Block(std::vector<Parameter> const &varDecls, std::vector<Tree*> const &insts);
	~Block() = default;

	bool correctDecl(std::map<std::string, Type*> &env) const;

}; 

#endif